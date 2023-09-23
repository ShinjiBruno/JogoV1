#pragma once
#include "SFML/Graphics/RectangleShape.hpp"
#include "GerenciadorGrafico.h"

class Ente {
protected:
	sf::RectangleShape figura;
	int id; //cada obj ente com seu id (como se fosse cpf)



public:
	Ente();
	~Ente();



};