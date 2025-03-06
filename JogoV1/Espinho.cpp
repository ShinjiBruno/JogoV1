#include "Espinho.h"
using namespace Entidades;
using namespace Obstaculos;

float Espinho::dif = 0.0f;

Espinho::Espinho()
{
	textureParado = new sf::Texture();
	if (textureParado->loadFromFile("assets/espinho.png"))
		;

	id = 2;
	figura->setSize(sf::Vector2f(100.0f, 50.0f));
	figura->setOrigin(sf::Vector2f(figura->getSize().x / 2, figura->getSize().y / 2));
	figura->setPosition(sf::Vector2f(275.0f + rand() % 500, 250.0f));
	figura->setFillColor(sf::Color::Red);
	figura->setTexture(textureParado);

	grav = 0;
	dano = 0.5f;
}

Espinho::~Espinho()
{
}

void Espinho::configuraObstaculo()
{
	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<int> distribution(500, 1500);
	int aleatorio = distribution(rng);

	figura->setSize(sf::Vector2f(100.0f, 50.0f));
	figura->setOrigin(sf::Vector2f(figura->getSize().x / 2, figura->getSize().y / 2));
	figura->setPosition(sf::Vector2f(275.0f + (dif + aleatorio), 250.0f));
	// figura->setFillColor(sf::Color::Red);
	dif += (float)aleatorio;
}

void Espinho::executar()
{
	gGraf->desenhar(*this->figura);
}