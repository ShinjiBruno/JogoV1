#pragma once

#include "Ente.h"
#include "Texto.h"

#include <vector>
#include <chrono>
#include <iostream>
#include <fstream>

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Text.hpp>

#define TAMANHO_MAX_TEXT 130
#define TAMANHO_TEXT 50
#define DISTANCIA_Y 20

using namespace std;


namespace Menus
{
	class Menu : public Ente {
	protected:
		sf::Font* font;

		Texto* titulo;
		Texto* iniciar;
		Texto* carregar;
		Texto* ranking;
		Texto* sair;

		vector<Texto*> listaOpcoes;

		Vector2f posicaoCentro;
		Vector2f posicaoJanela;

		Vector2u tamJanela;

		int nAlternativas;
		int opMax;
		int i;
		float meioX;

		static bool principal;
		static bool comando;
		static bool comecar;
		static bool escolherFase;
		static bool escolherJogadores;
		static bool escolherNome;


		string endereco;

	public:
		Menu();
		~Menu();

		virtual void executar() = 0;
		virtual void selecionar() = 0;

		void representaSelecionado();
		//void opSelecionador();

		int getNumOp();
		void setSelecionado(int max, int opcao);

		static bool getComecar();
		static bool getComando();
		static bool getEscolherFase();
		static bool getEscolherJogadores();
		static bool getEscolherNome();
		static bool getPrincipal();

		static void setComecar(bool comec);
		static void setComando(bool pressionado);
		static void setPrincipal(bool primeiro);
		static void setEscolherFase(bool escolhido);
		static void setEscolherJogadores(bool escolhido);
		static void setEscolherNome(bool escolhido);

		vector<Texto*> getLista();

		GerenciadorGrafico* getGgraf();
		sf::Font* getFonte();
	};
}