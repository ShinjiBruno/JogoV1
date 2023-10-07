#pragma once
#include "SFML/Graphics.hpp"

class Jogo {
private:
	sf::RenderWindow window;
	sf::CircleShape circ; //
		
public:
	Jogo();
	~Jogo();

	void executarJogo();

};