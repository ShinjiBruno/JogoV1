#include "Fase2.h"

using namespace Fases;

Fase2::Fase2() {

}

Fase2::~Fase2() {

}

void Fase2::criaInimigos() {
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

void Fase2::criaObstaculos() {
	int numPlat = 10 + rand() % 11;
	int numDanoso = 3 + rand() % 3;

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
	//cria Obstaculo Danoso
	for (int i = 0; i < numDanoso; i++) {
		gerProto.registraPrototipoObst(numPlat + i, new Espinho());
		Obstaculo* danoso = gerProto.criaObstaculo(numPlat + i);
		danoso->configuraObstaculo();
		if (danoso) {
			lista->incluir(static_cast<Entidade*>(danoso));
			gerCol.incluirObstaculos(danoso);
		}
	}
}

void Fase2::percorreLista() {
	this->lista->percorrer();
	gerCol.colisaoPersoObst();
	gerCol.colisaoJogInim();
	gerCol.colisaoVisaoInimigo();
}