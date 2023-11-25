#include "Mago.h"
using namespace Entidades;
using namespace Personagens;


Mago::Mago(): posVecProj(0) {
	vecProj = new std::vector<Projetil*>();
	visao.setRadius(3500.0f);
	id = 8;
	andar = 0.01f;
	vida = 550.0f;
	danar = 250.0f;
	pontuacao = 500;
	//fase2 = NULL;

	std::mt19937 rng(std::random_device{}());						//gerador de numeros aleatorios (mto mais eficiente que rand())
	std::uniform_int_distribution<int> distribution(5, 50);			//numero aleatorio entre 5 e 50 que sera incrementado no dano do mago
	maldicao = 1.0f*distribution(rng);
	danar += 1.0f*maldicao;
	pontuacao += distribution(rng);

	criaProjeteis();
	relogio.restart();
}

Mago::~Mago() {
	for (auto it = vecProj->begin(); it != vecProj->end();) {
		delete* it; 
		it = vecProj->erase(it); 
		
	}
}

void Mago::configuraInimigo() {
	std::mt19937 rng(std::random_device{}());						//gerador de numeros aleatorios (mto mais eficiente que rand())
	std::uniform_int_distribution<int> distribution(150, 500);
	int aleatorio = distribution(rng);

	figura->setSize(sf::Vector2f(40.0f, 80.0f));
	figura->setOrigin(sf::Vector2f(figura->getSize().x / 2, figura->getSize().y / 2));
	this->figura->setPosition(sf::Vector2f((1500.0f + aleatorio), 200.0f));
}

void Mago::criaProjeteis() {
	for (int i = 0; i < NUM_PROJ; i++) {
		Projetil* prj = new Projetil();
		prj->setDirec(this->direc);
		prj->getFigura()->setPosition(figura->getPosition());
		prj->setDanar(danar);
		vecProj->push_back(prj);
	}
}

void Mago::atiraProj() {
	posVecProj = (posVecProj >= 4) ? 0 : posVecProj;
	tempoPercorrido = relogio.getElapsedTime();
	if (tempoPercorrido.asSeconds() >= 4.0f && detectaJog) {
		Projetil* proj =  (*vecProj)[posVecProj];//new Projetil();
		proj->Atingiu(false);
		if (proj->getRaivoso() == 1) {					//se o tiro raivoso for 1, aumenta 50%; se 2, aumenta em dobro
			danar += danar * 0.5f;
		}
		else if (proj->getRaivoso() == 2) {
			danar *= 2;
		}
		
		proj->setDirec(direc);
		proj->setDanar(danar);
		vecProj->push_back(proj);
		relogio.restart();
	}
	std::vector<Projetil*>::iterator it;
	for (it = vecProj->begin(); it != vecProj->end();++it) {
		if ((*it)->getNeutralizado()) {
			//delete *it;
			//it = vecProj->erase(it);
			(*it)->getFigura()->setPosition(figura->getPosition());
		}
		(*it)->executar();
	}
	posVecProj += 1;
}

void Mago::executar() {
	if (!neutralizado) {
		moveIni();
		atiraProj();
		this->gGraf->desenhar(*this->figura);
	}
	else {
		this->figura->setPosition(sf::Vector2f(-10.0f, -10.0f));
		figura->setSize(sf::Vector2f(0.0f, 0.0f));
		
	}

}