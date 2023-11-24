#pragma once
#include <list>
#include <vector>
#include "Jogador.h"
#include "Inimigo.h"
#include "Obstaculo.h"
#include "Projetil.h"


using namespace Entidades;
using namespace Entidades::Personagens;
using namespace Entidades::Obstaculos;

using std::list;
using std::vector;

namespace Gerenciadores {
	class GerenciadorColisoes {
	private:
		vector<Inimigo*> LIs;	//vector de inimigos
		vector<Jogador*> LJs;	//vector de jogadores
		vector<Projetil*> LPs; //vector de projeteis
		list<Obstaculo*> LOs;		//lista de obstaculos

	public:
		GerenciadorColisoes();
		~GerenciadorColisoes();
		
		void colisaoPersoObst();
		void colisaoJogInim();
		void colisaoVisaoInimigo();
		void colisaoProjetil();

		void incluirObstaculos(Obstaculo* obst);
		void incluirInimigos(Entidade* inim);
		void incluirJogadores(Entidade* jog);
		void incluirProjeteis(std::vector<Projetil*> &proj);
	};

}