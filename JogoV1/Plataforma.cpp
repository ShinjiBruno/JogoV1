#include "Plataforma.h"
using namespace Entidades;
using namespace Obstaculos;

int Plataforma::qnt = 0;
float Plataforma::dif = 0.0f;

Plataforma::Plataforma(){
	id = 5;
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
	std::uniform_int_distribution<int> distribution1(350, 800); 
	std::uniform_int_distribution<int> distribution2(10, 100);
	int aleatorio = distribution1(rng);
	float prob = (float)(aleatorio - distribution1.min()) / (distribution1.max() - distribution1.min());

	printf("prob = %f\n", prob);
	if (qnt != 0) {
		if (prob > 0.9f) {
			this->figura->setSize(sf::Vector2f(100.0f, 50.0f));
			this->figura->setOrigin(sf::Vector2f(this->figura->getSize().x / 2, this->figura->getSize().y / 2));
			this->figura->setPosition(sf::Vector2f((dif + aleatorio), 100.0f - distribution2(rng)));
			this->figura->setFillColor(sf::Color::Green);
			this->dif += aleatorio;
		}
		else {
			id = 6;
			this->figura->setSize(sf::Vector2f(100.0f, 200.0f));
			this->figura->setOrigin(sf::Vector2f(this->figura->getSize().x / 2, this->figura->getSize().y / 2));
			this->figura->setPosition(sf::Vector2f((dif + aleatorio), 250.0f - 100.0f));
			this->figura->setFillColor(sf::Color::Green);
			this->dif += aleatorio;
		}
	}
}

void Plataforma::executar() {
	gGraf->desenhar(*this->figura);
}