#pragma once
#include "SFML/Graphics/RectangleShape.hpp"
#include "GerenciadorGrafico.h"

class Ente {
protected:
	sf::RectangleShape figura;
	GerenciadorGrafico* gGraf;
	int id; //cada obj ente com seu id 

public:
	Ente();
	~Ente();


	void executar();

	int getId() { return id; }

};