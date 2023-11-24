#include "Slime.h"
using namespace Entidades;
using namespace Obstaculos;

float Slime::dif = 0.0f;

Slime::Slime() {
	id = 4;
	figura->setSize(sf::Vector2f(50.0f, 50.0f));
	figura->setOrigin(sf::Vector2f(figura->getSize().x / 2, figura->getSize().y / 2));
	figura->setPosition(sf::Vector2f(200.0f + rand()%500, 250.0f));
	figura->setFillColor(sf::Color::Cyan);

	grav = 0;
}

Slime::~Slime() {
	
}

void Slime::configuraObstaculo() {
	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<int> distribution(1000, 2500);
	int aleatorio = distribution(rng);

	figura->setFillColor(sf::Color::Cyan);
	figura->setSize(sf::Vector2f(50.0f, 50.0f));
	figura->setOrigin(sf::Vector2f(figura->getSize().x / 2, figura->getSize().y / 2));
	figura->setPosition(sf::Vector2f(200.0f + dif + aleatorio, 250.0f));
	dif += aleatorio;
}

void Slime::executar() {
	gGraf->desenhar(*this->figura);
}