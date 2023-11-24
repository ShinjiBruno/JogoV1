#include "Movedica.h"
using namespace Entidades;
using namespace Obstaculos;

float Movedica::dif = 0.0f;

Movedica::Movedica() {
	id = 3;
	figura->setSize(sf::Vector2f(150.0f, 50.0f));
	figura->setOrigin(sf::Vector2f(figura->getSize().x / 2, figura->getSize().y / 2));
	figura->setPosition(sf::Vector2f(200.0f + rand() % 500, 250.0f));
	figura->setFillColor(sf::Color::Magenta);

	grav = 0;
}

Movedica::~Movedica() {

}

void Movedica::configuraObstaculo() {
	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<int> distribution(500, 1500);
	int aleatorio = distribution(rng);

	figura->setFillColor(sf::Color::Magenta);
	figura->setSize(sf::Vector2f(150.0f, 50.0f));
	figura->setOrigin(sf::Vector2f(figura->getSize().x / 2, figura->getSize().y / 2));
	figura->setPosition(sf::Vector2f(500.0f + dif + aleatorio, 250.0f));
	dif += aleatorio;
}

void Movedica::executar() {
	gGraf->desenhar(*this->figura);
}