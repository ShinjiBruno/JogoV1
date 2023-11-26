#pragma once

#include "Menu.h"

using namespace Menus;

namespace Menus {
	class MenuNumeroJogadores : public Menu {
	private:
		bool doisJogadores;
		bool umJogador;

		Texto* jogadorUm;
		Texto* jogadorDois;

	public:
		MenuNumeroJogadores();
		~MenuNumeroJogadores();

		void executar();
		void selecionar();

		bool getUmJogadores();
		bool getDoisJogadores();

	};
}