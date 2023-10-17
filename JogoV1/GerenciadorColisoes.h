#pragma once
#include <list>
#include <vector>
#include "Personagem.h"
#include "Obstaculo.h"
using namespace Entidades::Personagens;
using namespace Entidades::Obstaculos;

using std::list;
using std::vector;

namespace Gerenciadores {
	class GerenciadorColisoes {
	private:
		vector<Personagem*> LIs;	//vector de inimigos
		vector<Personagem*> LJs;	//vector de jogadores 
		list<Obstaculo*> LOs;		//lista de obstaculos

	public:
		GerenciadorColisoes();
		~GerenciadorColisoes();

		void incluirObstaculos(Obstaculo* obst);
		void incluirInimigos(Personagem* inim);
		void incluirJogadores(Personagem* jog);

	};

}