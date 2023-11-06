#pragma once
#include "Obstaculo.h"

namespace Entidades {
	namespace Obstaculos {
		class ObstaculoProjetil : public Obstaculo {
		public:
			ObstaculoProjetil();
			~ObstaculoProjetil();
			Obstaculo* clone() {
				return new ObstaculoProjetil(*this);
			}
			void configuraObstaculo();
			void executar();
		};
	}
}