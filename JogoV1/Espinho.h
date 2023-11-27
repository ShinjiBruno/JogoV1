#pragma once
#include "Obstaculo.h"

namespace Entidades {
	namespace Obstaculos {
		class Espinho : public Obstaculo {
		private:
			float afiado;
			static float dif; //diferenca de distancia entre dois obstaculos
		public :
			Espinho();
			~Espinho();

			void configuraObstaculo();
			void executar();
		};
	}
}