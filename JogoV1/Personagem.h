#pragma once
#include "Entidade.h"
#include "Animacao.h"
#include <math.h>
#define T_LOOP 0.0017f //intervalo de tempo hipotetico para cada "frame" do loop principal
#define ALT_MAX_PULO 0.43f
#define ALT_MAX_COL 0.0f
#define ALT_MAX_QL 0.0f //queda livre

namespace Entidades {
	namespace Personagens {
		class Personagem : public Entidade {
		protected:
			float vida;
			float tempoLoop; //tempo de cada iteracao do loop principal
			int pontuacao;
			Animacao* animParado;
			Animacao* animAndando;

		public:
			Personagem();
			~Personagem();

			bool neutralizou() { return vida < 0.0f ? true : false; }

			float aplicaGrav(int opt);	//opt=1 pulo; opt=2 colisao inimigo; opt=3 ataque inimigo
										//manda calcular grav conforme situacoes especificas
			float calculaGrav(float alturaMax);
			
			int getPontuacao() { return pontuacao; }
			virtual void executar() = 0;
		};
	}
}