#include "Fase1.h"

using namespace Fases;

Fase1::Fase1() {

}

Fase1::~Fase1() {

}

void Fase1::criaInimigos() {
	int numST = 20 + rand() % 5; //sneaky toast
	int numSk = 15 + rand() % 5; //skull

	int numT = 20 + rand() % 5; //torradas
	for (int i = 0; i < numT; i++) {
		//gerProto.registraPrototipoInim(i, new Torrada());
		Inimigo* inim = new Torrada();
		inim->configuraInimigo();
		if (inim) {
			lista->incluir(static_cast<Entidade*>(inim));
			gerCol.incluirInimigos(inim);
		}
	}

	for (int i = 0; i < numSk; i++) {
		//gerProto.registraPrototipoInim( i, new Caveira());
		Inimigo* inim = new Caveira();
		inim->configuraInimigo();
		if (inim) {
			lista->incluir(static_cast<Entidade*>(inim));
			gerCol.incluirInimigos(inim);
		}
	}
}

void Fase1::criaObstaculos() {
	int numPlat = 10 + rand() % 11;
	int numDanoso = 3 + rand() % 3;
	int numObstProj = 1 + rand() % 2;


	for (int i = 1; i < numPlat; i++) {
		//gerProto.registraPrototipoObst(i, new Plataforma());
		//Obstaculo* plat = gerProto.criaObstaculo(i);
		Obstaculo* plat = new Plataforma();
		plat->configuraObstaculo();
		printf("Plataforma %d - Size: (%f; %f) and Position: (%f, %f) \n", i, plat->getFigura()->getSize().x, plat->getFigura()->getSize().y, plat->getFigura()->getPosition().x, plat->getFigura()->getPosition().y);

		if (plat) {
			lista->incluir(static_cast<Entidade*>(plat));
			gerCol.incluirObstaculos(plat);
		}
	}
	//cria Obstaculo Danoso
	for (int i = 0; i < numDanoso; i++) {
		//gerProto.registraPrototipoObst(numPlat + i, new Espinho());
		Obstaculo* danoso = new Espinho();//erProto.criaObstaculo(numPlat + i);
		danoso->configuraObstaculo();
		if (danoso) {
			lista->incluir(static_cast<Entidade*>(danoso));
			gerCol.incluirObstaculos(danoso);
		}
	}
	for (int i = 0; i < numObstProj; i++) {
		//gerProto.registraPrototipoObst(numPlat + numDanoso + i, new Slime());
		Obstaculo* obst_proj = new Slime();//gerProto.criaObstaculo(numPlat + numDanoso + i);
		obst_proj->configuraObstaculo();
		if (obst_proj) {
			lista->incluir(static_cast<Entidade*>(obst_proj));
			gerCol.incluirObstaculos(obst_proj);
		}
	}
}

void Fase1::percorreLista() {
	lista->percorrer();
	gerCol.colisaoProjetil();
	gerCol.colisaoJogInim();
	gerCol.colisaoVisaoInimigo();
	gerCol.colisaoPersoObst();
}