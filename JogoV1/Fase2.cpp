#include "Fase2.h"

//u  sing namespace Entidades;
using namespace Fases;

Fase2::Fase2() {
	Mago* mago = new Mago();
	raiva = rand() % 21;
}

Fase2::~Fase2() {
	raiva = 0;
}

void Fase2::criaInimigos() {
	int numT = 8 + rand() % 5; //torradas
	
	for (int i = 0; i < numT; i++) {
		//gerProto.registraPrototipoInim(i, new Torrada());
		//Inimigo* inim = gerProto.criaInimigo(i);
		Inimigo* inim = new Torrada();
		
		inim->configuraInimigo();
		if (inim) {
			lista->incluir(static_cast<Entidade*>(inim));
			gerCol.incluirInimigos(inim);
		}
	}

	for (int i = 0; i < 1; i++) { //CHEFAO
		//gerProto.registraPrototipoInim(i, new Caveira());
		//Inimigo* inim = gerProto.criaInimigo(i);
		Mago* mago = new Mago();
		Inimigo* inim = mago;
		inim->configuraInimigo();
		if (inim) {
			lista->incluir(static_cast<Entidade*>(inim));
			gerCol.incluirInimigos(inim);
			gerCol.incluirProjeteis(*mago->getProjVector());
		}
	}

}

void Fase2::criaObstaculos() {
	int numPlat = 10 + rand() % 11;
	int numDanoso = 5 + rand() % 8;
	int numObstProj = 4 + rand() % 7;

	for (int i = 1; i < numPlat; i++) {
		//gerProto.registraPrototipoObst(i, new Plataforma());
		//Obstaculo* plat = gerProto.criaObstaculo(i);
		Obstaculo* plat = new Plataforma(2);
		
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
		//Obstaculo* danoso = gerProto.criaObstaculo(numPlat + i);
		Obstaculo* danoso = new Espinho();
		danoso->configuraObstaculo();
		if (danoso) {
			lista->incluir(static_cast<Entidade*>(danoso));
			gerCol.incluirObstaculos(danoso);
		}
	}
}

void Fase2::percorreLista() {
	lista->percorrer();
	gerCol.colisaoProjetil();
	gerCol.colisaoJogInim();
	gerCol.colisaoVisaoInimigo();
	gerCol.colisaoPersoObst();

}