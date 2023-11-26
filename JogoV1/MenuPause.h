#pragma once


#include "Menu.h"

using namespace std;
using namespace Gerenciadores;

namespace Menus {
	class MenuPause : public Menu
	{
		private:
			unsigned int escalaPause;
			unsigned int escalaOpPause;

		public:
			MenuPause();
			~MenuPause();

			void executar();
			void selecionar();
	};
}
