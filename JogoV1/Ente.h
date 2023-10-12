#pragma once
#include "SFML/Graphics/RectangleShape.hpp"
#include "GerenciadorGrafico.h"

int Ente::id = 0;

class Ente {
protected:
	sf::RectangleShape figura;
	GerenciadorGrafico* gGraf;
	static int id; //cada obj ente com seu id 

public:
	Ente() :figura(sf::Vector2f(-1.0f, -1.0f)), gGraf(NULL) { id++; }
	~Ente() { figura.setOrigin(sf::Vector2f(-1.0f, -1.0f)); gGraf = NULL; }

	int getId() { return id; }

	virtual void executar() = 0;

};
