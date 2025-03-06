#include "Gosma.h"
using namespace Entidades;
using namespace Obstaculos;

float Gosma::dif = 0.0f;

Gosma::Gosma() : gosma(0)
{
	textureParado = new sf::Texture();
	if (textureParado->loadFromFile("assets/gosma.png"))
		;

	id = 4;
	figura->setSize(sf::Vector2f(250.0f, 50.0f));
	figura->setOrigin(sf::Vector2f(figura->getSize().x / 2, figura->getSize().y / 2));
	figura->setPosition(sf::Vector2f(200.0f + rand() % 500, 250.0f));
	figura->setTexture(textureParado);

	grav = 0;
}

Gosma::~Gosma()
{
}

void Gosma::configuraObstaculo()
{
	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<int> distribution(1000, 2500);
	int aleatorio = distribution(rng);

	gosma = aleatorio / 10;
	figura->setSize(sf::Vector2f(gosma, 50.0f));
	figura->setOrigin(sf::Vector2f(figura->getSize().x / 2, figura->getSize().y / 2));
	figura->setPosition(sf::Vector2f(200.0f + dif + aleatorio, 250.0f));
	dif += aleatorio;
}

void Gosma::executar()
{
	gGraf->desenhar(*this->figura);
}