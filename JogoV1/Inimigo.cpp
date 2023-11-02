#include "Inimigo.h"
using namespace Entidades;
using namespace Personagens;

Inimigo::Inimigo(): detectaJog(false), visao(RAIO_VISAO) {

	figura->setSize(sf::Vector2f(20.0f, 40.0f));
	figura->setOrigin(sf::Vector2f(figura->getSize().x / 2, figura->getSize().y / 2));
	figura->setPosition(sf::Vector2f(175.0f, 200.0f));
	figura->setFillColor(sf::Color::Blue);
	grav = 0.1f;
	andar = 0.05f;
	visao.setOrigin(figura->getOrigin());
	visao.setPosition(figura->getPosition());
	direc = -1;
}

Inimigo::~Inimigo() {}

void Inimigo::moveIni() {
	if (detectaJog) {
		if (direc == 0) {
			this->figura->move(sf::Vector2f(-andar, 0));
		}
		else if (direc == 1) {
			this->figura->move(sf::Vector2f(andar, 0));
		}
	}

	this->figura->move(sf::Vector2f(0, grav));
	visao.setPosition(figura->getPosition());
}
void Inimigo::executar() {
	moveIni();
	this->gGraf->desenhar(*this->figura);
}