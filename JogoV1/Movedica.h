#pragma once
#include "Obstaculo.h"

namespace Entidades {
	namespace Obstaculos {
		class Movedica : public Obstaculo {
		private:
			static float dif;
		public:
			Movedica();
			~Movedica();
			Obstaculo* clone() {
				return new Movedica(*this);
			}
			void configuraObstaculo();
			void executar();
		};
	}
}