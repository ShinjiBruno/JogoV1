#pragma once
#include "Fase.h"
#include "Caveira.h"
#include "Mago.h"
#include "Animacao.h"
#include <iostream>

using namespace Entidades;
using namespace Personagens;

using namespace std;

namespace Fases
{
	class Fase2 : public Fase
	{
	private:
		float raiva; // aumenta o dano dos inimigos
		// Mago* mago;

	public:
		Fase2();
		~Fase2();
		void criaInimigos();
		void criaObstaculos();
		void percorreLista();
	};
}