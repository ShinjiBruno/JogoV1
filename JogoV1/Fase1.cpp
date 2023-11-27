#include "Fase1.h"

using namespace Fases;

Fase1::Fase1() {
	fundo = new BackGround(1);

	serenidade = 0.1f + static_cast<float>(rand() / RAND_MAX);
}

Fase1::~Fase1() {

}

void Fase1::criaInimigos() {
	int numSk = 15 + rand() % 5; //skull
	int numT = 20 + rand() % 5; //torradas

	for (int i = 0; i < numT; i++) {
		//gerProto.registraPrototipoInim(i, new Torrada());
		Inimigo* inim = new Torrada();
		inim->configuraInimigo();
		inim->setAndar(inim->getAndar() + serenidade);

		if (inim) {
			lista->incluir(static_cast<Entidade*>(inim));
			gerCol.incluirInimigos(inim);
		}
	}

	for (int i = 0; i < numSk; i++) {
		//gerProto.registraPrototipoInim( i, new Caveira());
		Inimigo* inim = new Caveira();
		inim->configuraInimigo();
		inim->setAndar(inim->getAndar() + serenidade);

		if (inim) {
			lista->incluir(static_cast<Entidade*>(inim));
			gerCol.incluirInimigos(inim);
		}
	}
}

void Fase1::criaObstaculos() {
	int numPlat = 10 + rand() % 11;
	int numDanoso = 3 + rand() % 3;
	int numGosma = 5 + rand() % 2;


	for (int i = 1; i < numPlat; i++) {
		//gerProto.registraPrototipoObst(i, new Plataforma());
		//Obstaculo* plat = gerProto.criaObstaculo(i);
		Obstaculo* plat = new Plataforma();
		plat->configuraObstaculo();

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
	for (int i = 0; i < numGosma; i++) {
		//gerProto.registraPrototipoObst(numPlat + numDanoso + i, new Slime());
		Obstaculo* gosma = new Gosma();//gerProto.criaObstaculo(numPlat + numDanoso + i);
		gosma->configuraObstaculo();
		if (gosma) {
			lista->incluir(static_cast<Entidade*>(gosma));
			gerCol.incluirObstaculos(gosma);
		}
	}
}

void Fase1::percorreLista() {
	fundo->fundoFase();
	lista->percorrer();
	gerCol.colisaoProjetil();
	gerCol.colisaoJogInim();
	gerCol.colisaoVisaoInimigo();
	gerCol.colisaoPersoObst();
	if (gerCol.getQntInim() == 0 || !gerCol.getJogVivos()) {
		acabouJogo = true;
	}

}