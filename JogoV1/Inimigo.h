#pragma once
#include "Personagem.h"
#include <random>

#define RAIO_VISAO 400.0f

namespace Entidades {
	namespace Personagens {
		class Inimigo : public Personagem {
		protected:
			sf::CircleShape visao;
			bool detectaJog;
			int direc; //direcao pra perseguir o jogador. 0 == esquerda; 1 == direita; outro valor == parado

		public:
			Inimigo();
			~Inimigo();

			void setDetectaJog(bool detec, int dir) {
				detectaJog = detec;
				if (detec) {
					visao.setRadius(2.5f * RAIO_VISAO);
					direc = dir;
				}

				else {
					visao.setRadius(RAIO_VISAO);
					direc = -1;
				}
					
			}
			const sf::CircleShape getVisao() { return visao; }

			void moveIni();
			virtual Inimigo* clone() = 0;
			virtual void configuraInimigo() = 0;
			virtual void executar() = 0;
		};
	}
}