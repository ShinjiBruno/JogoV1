#pragma once
#include "Inimigo.h"

namespace Entidades {
	namespace Personagens {
		class Caveira : public Inimigo {
		private:
			static float ult_increm; //ultimo incremento da posicao
			float odio;	//atributo da caveira 
		public:
			Caveira();
			void configuraInimigo();
			void executar();
		};
	}
}