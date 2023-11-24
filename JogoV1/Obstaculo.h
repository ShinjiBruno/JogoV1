#pragma once
#include "Entidade.h"
#include <random>
//implementar prototype
namespace Entidades {
	
	namespace Obstaculos {
		class Obstaculo: public Entidade  {
		protected:
			float dano;

		public:
			Obstaculo();
			~Obstaculo();

			float getDanar() { return dano; }

			virtual Obstaculo* clone() = 0;
			virtual void configuraObstaculo() = 0;
			virtual void executar() = 0;

		};
	}
}