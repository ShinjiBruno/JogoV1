#pragma once
#include "SFML/Graphics/RectangleShape.hpp"
#include "GerenciadorGrafico.h"

using namespace Gerenciadores;

class Ente {
protected:
	sf::RectangleShape* figura; 
	GerenciadorGrafico* gGraf;
	int id;  

public:
	Ente();
	~Ente();

	int getId() { return id; }
	sf::RectangleShape* getFigura() { return figura; }

	virtual void executar() = 0;

};
