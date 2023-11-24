#pragma once
#include "Inimigo.h"
#include "Projetil.h"
#include "Fase2.h"
#include <vector>
#define NUM_PROJ 4

namespace Entidades {
	namespace Personagens {
		class Mago: public Inimigo {
		private:
			float maldicao; //atributo que aumenta o dano do mago
			sf::Clock relogio;
			sf::Time tempoPercorrido;
			std::vector<Projetil*> *vecProj; //ponteiro de vector para poder manipular no gerenciador de colisoes
			int posVecProj; //posVecProj = 0, 1 ou 2
			//Fase2* fase2;
			
		public:
			Mago();
			~Mago();

			std::vector<Projetil*>* getProjVector() { return vecProj; }

			void criaProjeteis();
			void atiraProj();
			void configuraInimigo();
			void executar();
		};
	}
}