#include "ObstaculoProjetil.h"
using namespace Entidades;
using namespace Obstaculos;

ObstaculoProjetil::ObstaculoProjetil() {

	figura->setSize(sf::Vector2f(50.0f, 50.0f));
	figura->setOrigin(sf::Vector2f(figura->getSize().x / 2, figura->getSize().y / 2));
	figura->setPosition(sf::Vector2f(200.0f + rand()%500, 250.0f));
	figura->setFillColor(sf::Color::Cyan);

	grav = 0;
	srand(time(NULL));
}

ObstaculoProjetil::~ObstaculoProjetil() {
	
}

void ObstaculoProjetil::configuraObstaculo() {
	figura->setFillColor(sf::Color::Cyan);
	figura->setSize(sf::Vector2f(50.0f, 50.0f));
	figura->setOrigin(sf::Vector2f(figura->getSize().x / 2, figura->getSize().y / 2));
	figura->setPosition(sf::Vector2f(200.0f + rand() % 500, 350.0f));
}

void ObstaculoProjetil::executar() {
	gGraf->desenhar(*this->figura);
}