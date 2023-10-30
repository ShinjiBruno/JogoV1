#pragma once
#include "Personagem.h"

namespace Entidades {
	namespace Personagens {
		class Jogador : public Personagem {
		private:
			sf::RectangleShape barraVida;
			float pulo;
		public:
			Jogador();
			~Jogador();

			void moveJog();
			void executar();
		};
	}
}