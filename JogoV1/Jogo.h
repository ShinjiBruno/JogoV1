#pragma once
#include "SFML/Graphics.hpp"
#include "GerenciadorGrafico.h"
#include "Fase.h"
#include "Jogador.h"

using namespace Gerenciadores;
using namespace Fases;

class Jogo {
private:
	Jogador jogador1;
	Fase fase;
	GerenciadorGrafico* window;
	sf::RectangleShape rec; //
	
public:
	Jogo();
	~Jogo();

	void executarJogo();

};