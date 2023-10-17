#pragma once
#include "Entidade.h"

namespace Entidades {
	namespace Obstaculos {
		class Obstaculo {
		protected:

		public:
			Obstaculo();
			~Obstaculo();

			virtual void executar() = 0;

		};
	}
}