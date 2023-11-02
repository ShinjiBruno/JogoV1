#pragma once
#include "Entidade.h"
#include <math.h>
#define T_LOOP 0.0015f //intervalo de tempo hipotetico para cada "frame" do loop principal

namespace Entidades {
	namespace Personagens {
		class Personagem : public Entidade {
		protected:
			float danar; //dano que vai causar
			float vida;
			float tempoLoop; //tempo de cada iteracao do loop principal

		public:
			Personagem();
			~Personagem();


			float calculaGrav(float alturaMax);
			virtual void executar() = 0;
		};
	}
}