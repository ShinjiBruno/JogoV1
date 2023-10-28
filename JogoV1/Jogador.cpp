#include "Jogador.h"
using namespace Entidades;
using namespace Personagens;

Jogador::Jogador() {

	figura.setSize(sf::Vector2f(20.0f, 40.0f));
	figura.setOrigin(sf::Vector2f(figura.getSize().x / 2, figura.getSize().y / 2));
	figura.setPosition(sf::Vector2f(100.0f, 200.0f));
	figura.setFillColor(sf::Color::Red);

}

Jogador::~Jogador() {}

void Jogador::executar() {
	gGraf->desenhar(this->figura);
}