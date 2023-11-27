	#pragma once
#include "Menu.h"

using namespace Menus;
using namespace Gerenciadores;

namespace Menus {

	class MenuDeFases : public Menu {
		private:
			bool fasePrimeira, faseSegunda;

			Texto* fase1;
			Texto* fase2;

		public:

			MenuDeFases();
			~MenuDeFases();

			void executar();
			void selecionar();

			bool getFasePrimeira();
			bool getFaseSegunda();
	};
}