#include "Plataforma.h"
using namespace Entidades;
using namespace Obstaculos;

int Plataforma::qnt = 0;
float Plataforma::dif = 0.0f;

Plataforma::Plataforma(){
	grav = 0;

	figura->setSize(sf::Vector2f(7000.0f, 50.0f));
	figura->setOrigin(sf::Vector2f(figura->getSize().x / 2, figura->getSize().y / 2));
	figura->setPosition(sf::Vector2f(3500.0f, 250.0f));
	figura->setFillColor(sf::Color::Green);
	qnt+=1;
}

Plataforma::~Plataforma() {
}

void Plataforma::configuraObstaculo() {
	std::mt19937 rng(std::random_device{}());						//gerador de numeros aleatorios (mto mais eficiente que rand())
	std::uniform_int_distribution<int> distribution1(150, 500); 
	std::uniform_int_distribution<int> distribution2(10, 100);
	int aleatorio = distribution1(rng);

	if (qnt != 0) {
		this->figura->setSize(sf::Vector2f(100.0f, 50.0f));
		this->figura->setOrigin(sf::Vector2f(this->figura->getSize().x / 2, this->figura->getSize().y / 2));
		this->figura->setPosition(sf::Vector2f((dif + aleatorio), 100.0f - distribution2(rng)));
		this->figura->setFillColor(sf::Color::Green);
		this->dif += aleatorio;
	}

}

void Plataforma::executar() {
	gGraf->desenhar(*this->figura);
}