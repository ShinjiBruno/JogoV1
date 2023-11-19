#pragma once
#include "Fase.h"
#include "Caveira.h"

namespace Fases {

	class Fase2 : public Fase {
	public:
		Fase2();
		~Fase2();

		void criaInimigos();
		void criaObstaculos();
		void percorreLista();
	};
}