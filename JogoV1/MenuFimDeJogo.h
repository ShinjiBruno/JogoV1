#pragma once

#include "Menu.h"

using namespace Menus;

namespace Menus {
	class MenuFimDeJogo : public Menu {
		
		private:
			Texto* mensagem;
			Texto* pontosUm;
			Texto* pontosDois;

			float escala;
			string pontuacao1;
			string pontuacao2;

			bool dois, ganhou;

		public:

			MenuFimDeJogo();
			~MenuFimDeJogo();

			void executar();
			void selecionar();

			void setPontos1(int pontuac);
			void setPontos2(int pontuac);

			void setGanhou(bool win);
			void setDois(bool two);
	};

}