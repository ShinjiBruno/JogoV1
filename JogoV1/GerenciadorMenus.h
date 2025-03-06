#pragma once

#include "MenuPause.h"
#include "MenuPrincipal.h"
#include "MenuDeFases.h"
#include "MenuNumeroJogadores.h"
#include "MenuRanking.h"
#include "MenuFimDeJogo.h"
#include "BackGround.h"

#include <iostream>

using namespace std;

using namespace Menus;

namespace Menus
{
	class GerenciadorMenus
	{
	private:
		// bool principal;
		bool comando;
		bool faseUm;
		bool faseDois;
		bool pressionado;
		bool fimDeJogo;

		int op, i;

		MenuPrincipal menuPrincipal;
		MenuPause menuPause;
		MenuDeFases menuFase;
		MenuNumeroJogadores menuNumJogadores;
		MenuFimDeJogo menuFimDeJogo;

		BackGround *fundoMenu;

	public:
		GerenciadorMenus();
		~GerenciadorMenus();

		void executarMenu(bool primeiro);

		void selecionadorOp();

		void movimentaOp(int max);

		bool getFaseUm();
		bool getFaseDois();

		void atrasoComando(sf::Clock *relogio);
		void verificaComando(sf::Clock *relogioEnter);

		bool getJogadorUm();
		bool getJogadorDois();

		void setFimDeJogo(bool fim);

		void setPontuacao1(int pont);
		void setPontuacao2(int pont);

		void setGanhou(bool win);
	};
}