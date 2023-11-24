#pragma once

#include "Ente.h"
//#include "MenuPrincipal.h"
//#include "MenuPause.h"
#include "Texto.h"
#include <vector>
#include <chrono>

#include <iostream>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Text.hpp>

#define TAMANHO_MAX_TEXT 130
#define TAMANHO_TEXT 50
#define DISTANCIA_Y 100
#define OPCOES_MAX 3
#define OPCOES_MIN 0

using namespace std;

namespace Menus
{
	class Menu : public Ente {
	private:
		sf::Font font;
		/*
		Texto* Jogar;

		Texto* iniciar;
		Texto* carregar;
		Texto* ranking;

		Texto* sair;
		*/
		
		Texto* nomeJogo;
		Texto* pause;

		Texto* iniciar;
		Texto* carregar;
		Texto* ranking;

		Texto* sair;
		Texto* voltar;

		vector<Texto*> listaOpcoes;//vector<Texto*> listaOpcoes = { nomeJogo, iniciar , carregar, ranking, sair };

		int op, i;


		float meioX;
		float topoY;

		bool comando;
		bool comecar;


		string endereco;

		//float tempo;


	public:
		Menu();
		~Menu();

		void executar();
		void executeMenu(bool Principal);

		void desenharMenuPause();
		void desenharMenuPrincipal();
		//void desenhar Ranking();

		void opSelecionado();
		void selecionadorOp();
	};
}