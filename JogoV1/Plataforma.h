#pragma once
#include "Obstaculo.h"
#include <random>

namespace Entidades {
	namespace Obstaculos {
		class Plataforma : public Obstaculo {
		private:
				static int plat_chao;
				static float dif;
		public:
			Plataforma();
			~Plataforma();
			Obstaculo* clone() {
				return new Plataforma(*this);//(*this);
			}
			void configuraObstaculo();
			void executar();
		};
	}
}