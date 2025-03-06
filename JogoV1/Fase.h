#pragma once
#include "ListaEntidades.h"
#include "GerenciadorColisoes.h"
#include "Espinho.h"
#include "Plataforma.h"
#include "Torrada.h"
#include "Animacao.h"
#include "BackGround.h"
#include <stdlib.h>
#include <iostream>

#define NUM_OBST 3
#define NUM_JOG 1
#define NUM_INI 1
#define MAX_FLUT 20

using namespace Gerenciadores;
using namespace Listas;

using namespace std;

namespace Fases
{
	class Fase
	{
	protected:
		BackGround *fundo;
		GerenciadorColisoes gerCol;
		ListaEntidades *lista;
		bool acabouJogo;

	public:
		Fase();
		~Fase();

		// void criaTorradas();
		bool getAcabouJogo() { return acabouJogo; }
		void criaJogadores(Entidade *jog1, Entidade *jog2 = NULL);
		virtual void criaInimigos() = 0;
		virtual void criaObstaculos() = 0;
		virtual void percorreLista() = 0;
	};
}