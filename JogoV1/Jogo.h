#pragma once
#include "SFML/Graphics.hpp"
#include "GerenciadorGrafico.h"
#include "GerenciadorMenus.h"
#include "Fase1.h"
#include "Fase2.h"
#include "Jogador.h"

using namespace Gerenciadores;
using namespace Fases;

class Jogo {
private:
	Jogador jogador1;
	Jogador jogador2;
	Fase1 fase1;
	Fase2 fase2;
	GerenciadorGrafico* gerenciaGraf;
	GerenciadorMenus menu;
	
public:
	Jogo();
	~Jogo();

	void criaFase();

	void telaFinalFaseUmJogador();
	void telaFinalFaseDoisJogadores();

	void configuracaoGraf();

	void executarJogo();

};