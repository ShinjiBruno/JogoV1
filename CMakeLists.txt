cmake_minimum_required(VERSION 3.28)
project(JogoV1)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.5.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

# Adiciona todos os arquivos .cpp da pasta src ao executável
file(GLOB_RECURSE SRC_FILES JogoV1/*.cpp)

add_executable(main ${SRC_FILES})
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE sfml-graphics)

# Create directory structure for assets
add_custom_command(TARGET main POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/fonts)

# Copy assets directory to output directory if it exists
if(EXISTS "${CMAKE_SOURCE_DIR}/assets")
    add_custom_command(TARGET main POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets)
    message(STATUS "Assets directory copied to output directory.")
else()
    message(STATUS "Assets directory not found. Created empty directory structure.")
endif()