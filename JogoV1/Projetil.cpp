#include "Projetil.h"
using namespace Entidades;

Projetil::Projetil(): direc(-1) {
	textureParado = new sf::Texture();
	if (textureParado->loadFromFile("bolaFogo.png")) {}
	animProj = new Animacao(textureParado, sf::Vector2u(4, 1), 5.0f);

	raivoso = static_cast<float>(rand() / RAND_MAX);
	andar = 0.5f + raivoso;
	figura->setSize(sf::Vector2f(50.0f, 50.0f));
	figura->setOrigin(sf::Vector2f(figura->getSize().x/2, figura->getSize().y/2));
	figura->setFillColor(sf::Color::White);
	neutralizado = true;
	grav = 0.02f;
}

Projetil::~Projetil() {
		
}

void Projetil::moveProj() { //direc=0 esquerda; direc=1 direita
	if (direc == 0) {
		figura->move(sf::Vector2f(-andar, grav));
	}
	else{
		figura->move(sf::Vector2f(andar, grav));
	}
	float distAt = abs(figura->getPosition().x - posIni.x);
	if (distAt >= 1500.0f) {
		neutralizado = true;
	}
}

void Projetil::executar() {
	if (!neutralizado) {
		moveProj();
		animProj->Atualiza(0, direc);
		figura->setTexture(textureParado);
		figura->setTextureRect(animProj->getMolde());

		gGraf->desenhar(*this->figura);
	}
}