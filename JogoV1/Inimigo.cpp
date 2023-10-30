#include "Inimigo.h"
using namespace Entidades;
using namespace Personagens;

Inimigo::Inimigo() {

	figura->setSize(sf::Vector2f(20.0f, 40.0f));
	figura->setOrigin(sf::Vector2f(figura->getSize().x / 2, figura->getSize().y / 2));
	figura->setPosition(sf::Vector2f(175.0f, 200.0f));
	figura->setFillColor(sf::Color::Blue);
	grav = 0.1f;
}

Inimigo::~Inimigo() {}

void Inimigo::moveIni() {

	this->figura->move(sf::Vector2f(0, grav));
}

void Inimigo::executar() {
	moveIni();
	this->gGraf->desenhar(*this->figura);
}