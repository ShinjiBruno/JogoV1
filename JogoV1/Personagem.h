#pragma once
#include "Entidade.h"

namespace Entidades {
	namespace Personagens {
		class Personagem : public Entidade {
		protected:
			float danar; //dano que vai causar
			float vida;


		public:
			Personagem();
			~Personagem();

			virtual void executar() = 0;
		};
	}
}