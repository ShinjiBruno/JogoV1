#pragma once
#include "Obstaculo.h"

namespace Entidades {
	namespace Obstaculos {
		class Plataforma : public Obstaculo {
		private:
				static int qnt;
				static float dif;
				float altura;	
				int fase;
		public:
			Plataforma(int f = 1);
			~Plataforma();

			void configuraObstaculo();
			void executar();
		};
	}
}