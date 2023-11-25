#include "Projetil.h"
using namespace Entidades;

Projetil::Projetil(): direc(-1) {
	raivoso = static_cast<float>(rand() / RAND_MAX);
	andar = 0.25f + raivoso;
	figura->setSize(sf::Vector2f(30.0f, 30.0f));
	figura->setOrigin(sf::Vector2f(figura->getSize().x/2, figura->getSize().y/2));
	neutralizado = true;
}

Projetil::~Projetil() {
		
}

void Projetil::moveProj() { //direc=0 esquerda; direc=1 direita
	if (direc == 0) {
		figura->move(sf::Vector2f(-andar, 0.0f));
	}
	else{
		figura->move(sf::Vector2f(andar, 0.0f));
	}
	float distAt = abs(figura->getPosition().x - posIni.x);
	if (distAt >= 1500.0f) {
		neutralizado = true;
	}
}

void Projetil::executar() {
	if (!neutralizado) {
		moveProj();
		gGraf->desenhar(*this->figura);
	}
}