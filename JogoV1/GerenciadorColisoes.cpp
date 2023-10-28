#include "GerenciadorColisoes.h"

using namespace Gerenciadores;

GerenciadorColisoes::GerenciadorColisoes() {
}

GerenciadorColisoes::~GerenciadorColisoes() {
}

/*******************INCLUSAO*********************/
void GerenciadorColisoes::incluirInimigos(Personagem* inim) {
	if (inim != NULL) {
		LIs.push_back(inim);
	}
	else { return; }
}

void GerenciadorColisoes::incluirJogadores(Personagem* jog) {
	if (jog != NULL) {
		LJs.push_back(jog);
	}
	else { return; }
}

void GerenciadorColisoes::incluirObstaculos(Obstaculo* obst) {
	if (obst != NULL) {
		LOs.push_back(obst);
	}
	else { return; }
}
/***********************************/

void GerenciadorColisoes::colisaoPersoObst() {
	for (int i = 0; i < LOs.size(); i++) {
		for (int j = 0; j < LJs.size() + LIs.size(); j++) {
			
		}
	}
}
