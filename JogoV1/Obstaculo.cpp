#include "Obstaculo.h"
using namespace Entidades;
using namespace Obstaculos;

Obstaculo::Obstaculo()
{

	figura->setSize(sf::Vector2f(500.0f, 50.0f));
	figura->setOrigin(sf::Vector2f(figura->getSize().x/2, figura->getSize().y/2));
	figura->setPosition(sf::Vector2f(275.0f, 250.0f));
	grav = 0;
}

Obstaculo::~Obstaculo() {
}

void Obstaculo::executar() {
	gGraf->desenhar(*this->figura);
}


