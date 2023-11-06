#pragma once
#include "ListaEntidades.h"
#include "GerenciadorColisoes.h"
#include "GerenciadorPrototipo.h"
#include "ObstaculoProjetil.h"
#include "ObstaculoDanoso.h"
#include "Plataforma.h"
#include "Inimigo.h"
#include "stdlib.h"

#define NUM_OBST 3
#define NUM_JOG 1
#define NUM_INI 1
#define MAX_FLUT 20

using namespace Gerenciadores;
using namespace Listas;

namespace Fases {
	class Fase {
	protected:
		GerenciadorPrototipo gerProto;
		GerenciadorColisoes gerCol;
		ListaEntidades* lista;

	public:
		Fase();
		~Fase();

		void criaInimigos();
		void criaObstaculos();
		void criaPlataforma();
		void criaObstFlutuantes();
		void criaJogadores(Entidade* jog1, Entidade* jog2 = NULL);

		void percorreLista();
	};
}