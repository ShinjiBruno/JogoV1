#pragma once
#include "SFML/Graphics/RectangleShape.hpp"
#include "GerenciadorGrafico.h"

using namespace Gerenciadores;

class Ente {
protected:
	sf::RectangleShape* figura; //a posição padrão de rectshape é medida a partir do canto superior esquerdo
	GerenciadorGrafico* gGraf;
	int id; //cada obj ente com seu id 

public:
	Ente();
	~Ente();

	int getId() { return id; }
	sf::RectangleShape* getFigura() { return figura; }

	virtual void executar() = 0;

};
