#pragma once
#include "SFML/Graphics.hpp"
#include "Personagem.h"

namespace Entidades {
	namespace Personagens {
		class Jogador : public Personagem {
		private:
			sf::RectangleShape barraVida;

		public:
			Jogador();
			~Jogador();


			void executar();
		};
	}
}