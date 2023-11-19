#pragma once
#include "Obstaculo.h"

namespace Entidades {
	namespace Obstaculos {
		class Espinho : public Obstaculo {
		private:
			static float dif; //diferenca de distancia entre dois obstaculos
		public :
			Espinho();
			~Espinho();

			Obstaculo* clone() {
				return new Espinho(*this);
			}
			void configuraObstaculo();
			void executar();
		};
	}
}