#pragma once
#include "Entidade.h"
#include <math.h>

namespace Entidades {
	class Projetil: public Entidade {
	private:
		sf::Vector2f posIni;
		float raivoso; //incrementa a veloc, consequentemente o dano do chefao
		int direc;
	public:
		Projetil();
		~Projetil();

		void setPosIni(sf::Vector2f p) { posIni = pos; }
		void setDirec(int d) { direc = d; }
		void Atingiu(bool a) { neutralizado = a; }

		int getDirec() { return direc; }
		int getRaivoso() { return raivoso; }
		void moveProj();
		void executar();
	};

}

