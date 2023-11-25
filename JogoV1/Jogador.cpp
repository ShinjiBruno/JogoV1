#include "Jogador.h"
using namespace Entidades;
using namespace Personagens;
using namespace Obstaculos;

int Jogador::numJog = 0;

Jogador::Jogador():jogador(0), nome(""), afetado(false) {
	id = 1;
	vida = VIDA;
	danar = 121.0f;
	if(numJog == 0) {
		figura->setSize(sf::Vector2f(20.0f, 40.0f));
		figura->setOrigin(sf::Vector2f(figura->getSize().x / 2, figura->getSize().y / 2));
		figura->setPosition(sf::Vector2f(100.0f, 200.0f));
		figura->setFillColor(sf::Color::Red);
		jogador = 0;
	}
	else {
		figura->setSize(sf::Vector2f(20.0f, 40.0f));
		figura->setOrigin(sf::Vector2f(figura->getSize().x / 2, figura->getSize().y / 2));
		figura->setPosition(sf::Vector2f(140.0f, 200.0f));
		figura->setFillColor(sf::Color::Red);
		jogador = 1;
	}
	barraDano.setSize(sf::Vector2f(50.0f, 15.0f));
	barraDano.setOrigin(sf::Vector2f(barraDano.getSize().x/2, barraDano.getSize().y/2 ));
	barraDano.setPosition(sf::Vector2f(figura->getPosition().x, figura->getPosition().y - figura->getSize().y - 5.0f));
	barraDano.setFillColor(sf::Color::Red);

	barraVida.setSize(sf::Vector2f(50.0f, 15.0f));
	barraVida.setOrigin(sf::Vector2f(barraDano.getSize().x / 2, barraDano.getSize().y / 2));
	barraVida.setPosition(barraDano.getPosition());
	barraVida.setFillColor(sf::Color::Green);

	andar = 0.15f;
	pulo = false;
	chao = true;
	grav = 0.5f;
	numJog += 1;
}

Jogador::~Jogador() {}

void Jogador::moveJog1() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		figura->move(sf::Vector2f(andar, 0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		figura->move(sf::Vector2f(-andar, 0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		figura->move(sf::Vector2f(0, -andar));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		figura->move(sf::Vector2f(0, andar));
	}
	/*
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && chao) {
		tempoLoop = T_LOOP;
		chao = false;
		pulo = true;
	}
	if (!chao) {
		if (pulo) {
			float velocY = aplicaGrav(1); //opt=1 caso pular
			figura->move(sf::Vector2f(0, -velocY));
		}
		else {
			float velocY = aplicaGrav(2); //opt=2 colisao inimigo
			figura->move(sf::Vector2f(0, -velocY));
		}
	}
	else { figura->move(sf::Vector2f(0, grav)); }//pulo = false; }*/

	barraDano.setPosition(sf::Vector2f(figura->getPosition().x, figura->getPosition().y - figura->getSize().y - 5.0f));
	barraVida.setPosition(sf::Vector2f(barraDano.getPosition()));
}

void Jogador::moveJog2() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		figura->move(sf::Vector2f(andar, 0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		figura->move(sf::Vector2f(-andar, 0));
	}
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		figura->move(sf::Vector2f(0, -andar));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		figura->move(sf::Vector2f(0, andar));
	}*/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && chao) {
		tempoLoop = T_LOOP;
		chao = false;
		pulo = true;
	}
	if (!chao) {
		if (pulo) {
			float velocY = aplicaGrav(1); //opt=1 caso pular
			figura->move(sf::Vector2f(0, -velocY));
		}
		else {
			float velocY = aplicaGrav(2); //opt=2 colisao inimigo
			figura->move(sf::Vector2f(0, -velocY));
		}
	}
	else { figura->move(sf::Vector2f(0, grav)); }//pulo = false; }

	barraDano.setPosition(sf::Vector2f(figura->getPosition().x, figura->getPosition().y - figura->getSize().y - 5.0f));
	barraVida.setPosition(sf::Vector2f(barraDano.getPosition()));
}

void Jogador::estadoPadrao() {
	andar = 0.15f;
	figura->setFillColor(sf::Color::Red);
}

void Jogador::efeitoNegativo(int id, Obstaculo* ob) {
	switch(id) {
	case 2:
		tomaDano(ob->getDanar());
		figura->setFillColor(sf::Color(248, 200, 220));
		break;
	case 3:
		if (jogador == 0) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				figura->move(sf::Vector2f(andar-0.05f, 0));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				figura->move(sf::Vector2f(-andar+0.05f, 0));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				figura->move(sf::Vector2f(0.0f, 0.08f));
			}
		}
		else {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				figura->move(sf::Vector2f(andar - 0.05f, 0));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				figura->move(sf::Vector2f(-andar + 0.05f, 0));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				figura->move(sf::Vector2f(0.0f, 0.08f));
			}
		}
		figura->move(sf::Vector2f(0.0f, 0.01f));
		break;

	case 4:
		break;


	}
}

void Jogador::executar() {
	if (jogador == 0) {
		moveJog1();
	}
	else {
		moveJog2();
	}
	gGraf->desenhar(*this->figura);
	gGraf->desenhar(this->barraDano);
	gGraf->desenhar(this->barraVida);
}