#pragma once
#include "Personagem.h"
#include <string>
#define VIDA 550.0f

namespace Entidades {
	namespace Personagens {
		class Jogador : public Personagem {
		private:
			static int numJog;

			std::string nome;
			int jogador;
			sf::RectangleShape barraVida; //barra verde q vai diminuindo conforme o dano que vai lenvando
			sf::RectangleShape barraDano; //barra verelha 
			bool pulo;
			int pontos;
		public:
			Jogador();
			~Jogador();
			
			void tomaDano(float dano) {
				if (vida - dano > 0.0f) {
					barraVida.setSize(sf::Vector2f(barraVida.getSize().x - dano * (50.0f / VIDA), barraVida.getSize().y));
					vida -= dano;
				}
				else {
					neutralizado = true;
				}
			}

			void setPulo(bool b) { pulo = b; }
			void setTempoLoop(float t) { tempoLoop = t; }
			float getTempoLoop() { return T_LOOP; }
			void estadoPadrao();
			void moveJog1();
			void moveJog2();
			void executar();
		};
	}
}