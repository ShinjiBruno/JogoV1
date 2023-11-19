#include "Torrada.h"
using namespace Entidades;
using namespace Personagens;

float Torrada::ult_increm = 0.0f;

Torrada::Torrada() {
	vida = 50.0f;
	danar = 50.0f;
}

void Torrada::configuraInimigo() {
	std::mt19937 rng(std::random_device{}());						//gerador de numeros aleatorios (mto mais eficiente que rand())
	std::uniform_int_distribution<int> distribution(150, 500);
	int aleatorio = distribution(rng);

	this->figura->setPosition(sf::Vector2f((ult_increm + aleatorio), 200.0f));
	ult_increm += aleatorio;
}

void Torrada::executar() {
	moveIni();
	this->gGraf->desenhar(*this->figura);
	
}