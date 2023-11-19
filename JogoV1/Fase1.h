#pragma once
#include "Fase.h"
#include "Caveira.h"

namespace Fases {

	class Fase1: public Fase {
	public:
		Fase1();
		~Fase1();
		
		void criaInimigos();
		void criaObstaculos();
		void percorreLista();
	};
}