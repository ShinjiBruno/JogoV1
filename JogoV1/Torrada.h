#pragma once
#include "Inimigo.h"

namespace Entidades {
	namespace Personagens {
		class Torrada: public Inimigo {
		private:
			static float ult_increm; //ultimo incremento da posicao
			float determinacao; //atributo da torrada
		public:
			Torrada();

			void configuraInimigo();
			void executar();
		};
	}
}