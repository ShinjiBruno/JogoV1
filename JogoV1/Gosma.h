#pragma once
#include "Obstaculo.h"

namespace Entidades {
	namespace Obstaculos {
		class Gosma : public Obstaculo {
		private:
			float gosma;
			static float dif;
		public:
			Gosma();
			~Gosma();
			void configuraObstaculo();
			void executar();
		};
	}
}