#include "Fase.h"
using namespace Fases;

Fase::Fase() {
	lista = new ListaEntidades();
}

Fase::~Fase() {
	
}

void Fase::criaJogadores(Entidade* jog1, Entidade* jog2) {
	if (jog2 == NULL) {
		lista->incluir(jog1);
	}
	else {
		lista->incluir(jog1);
		lista->incluir(jog2);
	}
}

void Fase::criaInimigos() {
	for (int i = 0; i < NUM_JOG; i++) {
		Inimigo* inim = new Inimigo();
		lista->incluir(static_cast<Entidade*>(inim));
	}
}

void Fase::criaObstaculos() {
	for (int i = 0; i < 1; i++) {
		Obstaculo* obs = new Obstaculo();
		lista->incluir(static_cast<Entidade*>(obs));
	}

}


void Fase::percorreLista() {
	lista->percorrer();
}