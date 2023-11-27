#include "Fase.h"
using namespace Fases;

Fase::Fase(): acabouJogo(false) {
	lista = new ListaEntidades();
	Obstaculo* plat = new Plataforma();
	lista->incluir(static_cast<Entidade*>(plat));
	gerCol.incluirObstaculos(plat);
	
	//criaTorradas();

	/*
	gerProto.registraPrototipoObst(2, new ObstaculoDanoso());
	gerProto.registraPrototipoObst(3, new ObstaculoProjetil());*/
}

Fase::~Fase() {

}

void Fase::criaJogadores(Entidade* jog1, Entidade* jog2) {
	if (jog2 == NULL) {
		lista->incluir(jog1);
		gerCol.incluirJogadores(jog1);
	}
	else {
		lista->incluir(jog1);
		lista->incluir(jog2);
		gerCol.incluirJogadores(jog1);
		gerCol.incluirJogadores(jog2);
	}
}


/*void Fase::criaInimigos() {
	int numST = 8 + rand() % 5; //sneaky toast
	int numSk = 8 + rand() % 5; //skull

	int numT = 8 + rand() % 5; //torradas
	for (int i = 0; i < numT; i++) {
		gerProto.registraPrototipoInim(i, new Torrada());
		Inimigo* inim = gerProto.criaInimigo(i);
		inim->configuraInimigo();
		if (inim) {
			lista->incluir(static_cast<Entidade*>(inim));
			gerCol.incluirInimigos(inim);
		}
	}

	for (int i = 0; i < numSk; i++) {
		gerProto.registraPrototipoInim(i, new Caveira());
		Inimigo* inim = gerProto.criaInimigo(i);
		inim->configuraInimigo();
		if (inim) {
			lista->incluir(static_cast<Entidade*>(inim));
			gerCol.incluirInimigos(inim);
		}
	}
}

void Fase::criaObstaculos() {
	//cria Plataforma
	int numPlat = 10 + rand() % 11;
	int numDanoso = 3 + rand() % 3;
	int numObstProj = 1 + rand() % 2;

	for (int i = 1; i < numPlat; i++) {
		gerProto.registraPrototipoObst(i, new Plataforma());
		Obstaculo* plat = gerProto.criaObstaculo(i);
		plat->configuraObstaculo();
		printf("Plataforma %d - Size: (%f; %f) and Position: (%f, %f) \n", i, plat->getFigura()->getSize().x, plat->getFigura()->getSize().y, plat->getFigura()->getPosition().x, plat->getFigura()->getPosition().y);

		if (plat) {
			lista->incluir(static_cast<Entidade*>(plat));
			gerCol.incluirObstaculos(plat);
		}
	}

	printf("Lista tamanho: %d\n", lista->getSize());

	//cria Obstaculo Danoso
	for (int i = 0; i < numDanoso; i++) {
		gerProto.registraPrototipoObst(numPlat+i, new Espinho());
		Obstaculo* danoso = gerProto.criaObstaculo(numPlat+i);
		danoso->configuraObstaculo();
		if (danoso) {
			lista->incluir(static_cast<Entidade*>(danoso));
			gerCol.incluirObstaculos(danoso);
		}
	}
	printf("Lista tamanho: %d\n", lista->getSize());


	//cria obstaculo projetil
	for (int i = 0; i < numObstProj; i++) {
		gerProto.registraPrototipoObst(numPlat+numDanoso+i, new Slime());
		Obstaculo* obst_proj = gerProto.criaObstaculo(numPlat+numDanoso+i);
		obst_proj->configuraObstaculo();
		if (obst_proj) {
			lista->incluir(static_cast<Entidade*>(obst_proj));
			gerCol.incluirObstaculos(obst_proj);
		}
	}
	printf("Lista tamanho: %d\n", lista->getSize());

}

void Fase::percorreLista() {
	this->lista->percorrer();
	gerCol.colisaoPersoObst();
	gerCol.colisaoJogInim();
	gerCol.colisaoVisaoInimigo();
}
*/