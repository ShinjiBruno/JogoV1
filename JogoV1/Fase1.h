#pragma once
#include "Fase.h"
#include "Caveira.h"
#include "Gosma.h"
#include <iostream>

using namespace std;

namespace Fases
{

	class Fase1 : public Fase
	{
	private:
		float serenidade; // atributo da Fase1: faz aumentar a velocidade dos inimigos
	public:
		Fase1();
		~Fase1();

		void criaInimigos();
		void criaObstaculos();
		void percorreLista();
	};
}