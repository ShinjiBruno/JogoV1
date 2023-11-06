#pragma once
#include "ObstaculoDanoso.h"
using namespace Entidades;
using namespace Obstaculos;

ObstaculoDanoso::ObstaculoDanoso() {
	figura->setSize(sf::Vector2f(100.0f, 50.0f));
	figura->setOrigin(sf::Vector2f(figura->getSize().x / 2, figura->getSize().y / 2));
	figura->setPosition(sf::Vector2f(275.0f + rand()%500, 250.0f));
	figura->setFillColor(sf::Color::Red);

	grav = 0;
	dano = 0.01f;
	srand(time(NULL));

}

ObstaculoDanoso::~ObstaculoDanoso() {
	
}

void ObstaculoDanoso::configuraObstaculo() {
	figura->setFillColor(sf::Color::Red);
	figura->setSize(sf::Vector2f(100.0f, 50.0f));
	figura->setOrigin(sf::Vector2f(figura->getSize().x / 2, figura->getSize().y / 2));
	figura->setPosition(sf::Vector2f(275.0f + rand() % 500, 250.0f));
}

void ObstaculoDanoso::executar() {
	gGraf->desenhar(*this->figura);
}