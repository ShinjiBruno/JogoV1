#include "Torrada.h"
using namespace Entidades;
using namespace Personagens;

float Torrada::ult_increm = 0.0f;

Torrada::Torrada() {
	textureParado = new sf::Texture();
	if (textureParado->loadFromFile("sneaky-toast-idle.png")) {}
	animParado = new Animacao(textureParado, sf::Vector2u(4,1), 10.0f);

	std::mt19937 rng(std::random_device{}());					
	std::uniform_int_distribution<int> distribution(5, 40);

	determinacao = distribution(rng);
	andar = 0.2f;
	vida = 50.0f;
	danar = 30.0f + determinacao;
	figura->setFillColor(sf::Color(255.0f, 6.3f * determinacao, 6.3f*determinacao));
	printf("Torrada atque: %f", danar);
}

void Torrada::configuraInimigo() {
	std::mt19937 rng(std::random_device{}());						//gerador de numeros aleatorios (mto mais eficiente que rand())
	std::uniform_int_distribution<int> distribution(150, 500);
	int aleatorio = distribution(rng);

	this->figura->setPosition(sf::Vector2f((ult_increm + aleatorio), 200.0f));
	ult_increm += aleatorio;
}

void Torrada::executar() {
	if (!neutralizado) {
		moveIni();
		animParado->Atualiza(0, direc);
		figura->setTexture(textureParado);
		figura->setTextureRect(animParado->getMolde());

		this->gGraf->desenhar(*this->figura);
	}
	else {
		this->figura->setPosition(sf::Vector2f(-1.0f, -1.0f));

	}
	
}