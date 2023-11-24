#include "Caveira.h"
using namespace Entidades;
using namespace Personagens;

float Caveira::ult_increm = 0.0f;

Caveira::Caveira() {
	vida = 25.0f;
	danar = 15.0f;
	figura->setFillColor(sf::Color::Green);
}

void Caveira::configuraInimigo() {
	std::mt19937 rng(std::random_device{}());						//gerador de numeros aleatorios (mto mais eficiente que rand())
	std::uniform_int_distribution<int> distribution(150, 500);
	int aleatorio = distribution(rng);

	this->figura->setPosition(sf::Vector2f((ult_increm + aleatorio), 200.0f));
	ult_increm += aleatorio;
}

void Caveira::executar() {
	if (!neutralizado) {
		moveIni();
		this->gGraf->desenhar(*this->figura);
	}
	else {
		this->figura->setPosition(sf::Vector2f(-1.0f, -1.0f));

	}
}