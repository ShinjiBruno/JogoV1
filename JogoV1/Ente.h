#pragma once
#include "SFML/Graphics/RectangleShape.hpp"
#include "GerenciadorGrafico.h"

using namespace Gerenciadores;

class Ente {
protected:
	sf::RectangleShape figura; //a posi��o padr�o de rectshape � medida a partir do canto superior esquerdo
	GerenciadorGrafico* gGraf;
	static int id; //cada obj ente com seu id 

public:
	Ente();
	~Ente();

	int getId() { return id; }

	virtual void executar() = 0;

};
