#pragma once
#include "SFML/Graphics.hpp"
#include "Personagem.h"

namespace Entidades {
	namespace Personagens {
		class Inimigo : public Personagem {
		private:


		public:
			Inimigo();
			~Inimigo();

			void moveIni();
			void executar();
		};
	}
}