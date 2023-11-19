#pragma once
#include "Inimigo.h"

namespace Entidades {
	namespace Personagens {
		class Torrada: public Inimigo {
		private:
			static float ult_increm; //ultimo incremento da posicao
		public:
			Torrada();

			Inimigo* clone() {
				return new Torrada(*this);
			}
			void configuraInimigo();
			void executar();
		};
	}
}