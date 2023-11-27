#pragma once

#include "Menu.h"

using namespace std;
using namespace Gerenciadores;

namespace Menus {
	class MenuPrincipal : public Menu
	{
		private:
			static bool rank;

		public:
			MenuPrincipal();
			~MenuPrincipal();

			void executar();
			void selecionar();

			void setRank(bool ran);
			static bool getRank();
	};
}

