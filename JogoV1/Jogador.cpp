#include "Jogador.h"
using namespace Entidades;
using namespace Personagens;

Jogador::Jogador() {

	figura->setSize(sf::Vector2f(20.0f, 40.0f));
	figura->setOrigin(sf::Vector2f(figura->getSize().x / 2, figura->getSize().y / 2));
	figura->setPosition(sf::Vector2f(100.0f, 200.0f));
	figura->setFillColor(sf::Color::Red);
	andar = 0.15f;
	pulo = 80.0f;
	grav = 0.1f;
}

Jogador::~Jogador() {}

void Jogador::moveJog() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		printf("Right key pressed\n");
		figura->move(sf::Vector2f(andar, 0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
		figura->move(sf::Vector2f(-andar, 0));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && chao) {
		figura->move(sf::Vector2f(0, -pulo));
		chao = false;
	}
	
	figura->move(sf::Vector2f(0, grav));
	//printf("Pos Jogador: x= %f; y = %f\n", figura->getPosition().x, figura->getPosition().y);

}

void Jogador::executar() {
	moveJog();
	gGraf->desenhar(*this->figura);
}