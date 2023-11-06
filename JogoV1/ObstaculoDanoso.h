#pragma once
#include "Obstaculo.h"

namespace Entidades {
	namespace Obstaculos {
		class ObstaculoDanoso : public Obstaculo {
		public :
			ObstaculoDanoso();
			~ObstaculoDanoso();

			Obstaculo* clone() {
				return new ObstaculoDanoso(*this);
			}
			void configuraObstaculo();
			void executar();
		};
	}
}