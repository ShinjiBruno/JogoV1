#pragma once
#include "Entidade.h"

namespace Entidades {
	namespace Obstaculos {
		class Obstaculo: public Entidade  {
		protected:

		public:
			Obstaculo();
			~Obstaculo();

			virtual void executar();

		};
	}
}