#include "Personagem.h"
using namespace Entidades;
using namespace Personagens;

Personagem::Personagem():vida(-1.0f), tempoLoop(T_LOOP), pontuacao(0) {
	
}

Personagem::~Personagem() {
	vida = -1.0f;
}


float Personagem::aplicaGrav(int opt) {
	switch (opt) {
	case 1:
		return calculaGrav(ALT_MAX_PULO);
	case 2:
		return calculaGrav(ALT_MAX_COL);
	case 3:
		if (tempoLoop > T_LOOP) {
				
		}
		return calculaGrav(ALT_MAX_QL);
	}
}


float Personagem::calculaGrav(float alturaMax) {
	//usar a equacao horaria de posicao: vf = v0 - g.t, onde v0 = sqrt(2.g.H), H eh altura max
	this->tempoLoop += T_LOOP;
	float v0 = sqrt(2 * alturaMax* 1.5);
	float vf = v0 - (tempoLoop*1.8);
	return vf;
	
}