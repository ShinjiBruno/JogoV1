#pragma once
#include "Obstaculo.h"

namespace Entidades {
	namespace Obstaculos {
		class Plataforma : public Obstaculo {
		private:
				static int qnt;
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