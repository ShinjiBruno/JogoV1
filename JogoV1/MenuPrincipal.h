#pragma once

#include "Menu.h"

using namespace std;
using namespace Gerenciadores;

namespace Menus {
	class MenuPrincipal : public Menu
	{
		private:


		public:
			MenuPrincipal();
			~MenuPrincipal();

			void executar();
			void selecionar();

	};
}

