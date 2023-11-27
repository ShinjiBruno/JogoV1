#pragma once

#include "Menu.h"

using namespace Menus;

namespace Menus {
	class MenuRanking : public Menu {
	private:
		Texto* primeiro;
		Texto* segundo;
		Texto* terceiro;
		Texto* quarto;
		Texto* quinto;
		Texto* sexto;

		ifstream colocacoes;

		string nomePonto;

		vector<string> teste;
		vector<string> posicao;
		vector<string> nomes;
		vector<string> pontos;

		bool voltar;

	public:
		MenuRanking();
		~MenuRanking();


		void executar();
		void selecionar();

		bool getVoltar();

		void setVoltar(bool vol);

		void pegaNomePontos();

	};
}