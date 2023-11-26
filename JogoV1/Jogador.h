#pragma once
#include "Personagem.h"
#include "Obstaculo.h"
#include <string>
#define VIDA 1750.0f

using namespace Entidades;
using namespace Obstaculos;

namespace Entidades {
	namespace Personagens {
		class Jogador : public Personagem {
		private:
			static int numJog;
			int jogador;

			std::string nome;
			sf::RectangleShape barraVida; //barra verde q vai diminuindo conforme o dano que vai lenvando
			sf::RectangleShape barraDano; //barra verelha 
			sf::Texture* texAndando;
			bool pulo;
			bool afetado; //verifica se esta afetado por algum efeito negativo

		public:
			Jogador();
			~Jogador();
		

			void tomaDano(float dano) {
				if (vida - dano > 0.0f) {
					barraVida.setSize(sf::Vector2f(barraVida.getSize().x - dano * (50.0f / VIDA), barraVida.getSize().y));
					vida -= dano;
				}
				else {
					barraVida.setSize(sf::Vector2f(0.1f, barraVida.getSize().y));
					neutralizado = true;
				}
			}

			void efeitoNegativo(int id, Obstaculo* ob); //id dos obstaculos. Para cada caso tem efeito diferente
			void setAfetado(bool a) { afetado = a; }
			void setPulo(bool b) { pulo = b; }
			void setTempoLoop(float t) { tempoLoop = t; }
			bool getAfetado() { return afetado; }
			float getTempoLoop() { return T_LOOP; }
			void estadoPadrao();
			void moveJog1();
			void moveJog2();
			void executar();
		};
	}
}