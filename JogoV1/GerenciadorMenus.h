#pragma once

#include "MenuPause.h"
#include "MenuPrincipal.h"
#include "MenuDeFases.h"
#include "MenuNumeroJogadores.h"

using namespace Menus;

namespace Menus {
	class GerenciadorMenus {
	private:
		//bool principal;
		bool comando;
		bool faseUm;
		bool faseDois;
		bool pressionado;


		int op,i;

		MenuPrincipal menuPrincipal;
		MenuPause menuPause;
		MenuDeFases menuFase;
		MenuNumeroJogadores menuNumJogadores;

	public:

		GerenciadorMenus();
		~GerenciadorMenus();

		void executarMenu(bool primeiro);

		void selecionadorOp();

		void movimentaOp(int max);

		bool getFaseUm();
		bool getFaseDois();

		void atrasoComando(sf::Clock* relogio);
		void verificaComando(sf::Clock* relogioEnter);

		bool getJogadorUm();
		bool getJogadorDois();
	};
}