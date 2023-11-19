#pragma once
#include "Obstaculo.h"

namespace Entidades {
	namespace Obstaculos {
		class Slime : public Obstaculo {
		private:
			static float dif;
		public:
			Slime();
			~Slime();
			Obstaculo* clone() {
				return new Slime(*this);
			}
			void configuraObstaculo();
			void executar();
		};
	}
}