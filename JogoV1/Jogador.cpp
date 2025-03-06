#include "Jogador.h"

using namespace Entidades;
using namespace Personagens;
using namespace Obstaculos;

int Jogador::numJog = 0;

Jogador::Jogador() : jogador(0), nome(""), afetado(false)
{
	pontuacao = 0;

	textureParado = new sf::Texture();
	texAndando = new sf::Texture();
	std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;
	// When loading an image:
	std::cout << "Attempting to load: " << "assets/jog-parado.png" << std::endl;

	if (textureParado->loadFromFile("assets/jog-parado.png"))
	{
	}
	if (texAndando->loadFromFile("assets/jog-andando.png"))
	{
	}
	animParado = new Animacao(textureParado, sf::Vector2u(1, 1), 1.0f);
	animAndando = new Animacao(texAndando, sf::Vector2u(8, 1), 10.0f);
	animParado->Atualiza(0, true);

	id = 1;
	vida = VIDA;
	danar = 121.0f;
	if (numJog == 0)
	{
		figura->setSize(sf::Vector2f(25.0f, 55.0f));
		figura->setOrigin(sf::Vector2f(figura->getSize().x / 2, figura->getSize().y / 2));
		figura->setPosition(sf::Vector2f(100.0f, 185.0f));
		// figura->setFillColor(sf::Color::Red);
		jogador = 0;
	}
	else
	{
		figura->setSize(sf::Vector2f(25.0f, 55.0f));
		figura->setOrigin(sf::Vector2f(figura->getSize().x / 2, figura->getSize().y / 2));
		figura->setPosition(sf::Vector2f(140.0f, 185.0f));
		// figura->setFillColor(sf::Color::Red);
		jogador = 1;
	}
	barraDano.setSize(sf::Vector2f(50.0f, 15.0f));
	barraDano.setOrigin(sf::Vector2f(barraDano.getSize().x / 2, barraDano.getSize().y / 2));
	barraDano.setPosition(sf::Vector2f(figura->getPosition().x, figura->getPosition().y - figura->getSize().y - 5.0f));
	barraDano.setFillColor(sf::Color::Red);

	barraVida.setSize(sf::Vector2f(50.0f, 15.0f));
	barraVida.setOrigin(sf::Vector2f(barraDano.getSize().x / 2, barraDano.getSize().y / 2));
	barraVida.setPosition(barraDano.getPosition());
	barraVida.setFillColor(sf::Color::Green);

	andar = 0.75f;
	pulo = false;
	chao = true;
	grav = 0.5f;
	numJog += 1;
}

Jogador::~Jogador() {}

void Jogador::moveJog1()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		figura->move(sf::Vector2f(andar, 0));
		animParado->Atualiza(0, true);
		animAndando->Atualiza(0, true);
		figura->setTexture(texAndando);
		figura->setTextureRect(animAndando->getMolde());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		figura->move(sf::Vector2f(-andar, 0));
		animParado->Atualiza(0, false);
		animAndando->Atualiza(0, false);
		figura->setTexture(texAndando);
		figura->setTextureRect(animAndando->getMolde());
	}
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		figura->move(sf::Vector2f(0, -andar));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		figura->move(sf::Vector2f(0, andar));
	}*/

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && chao)
	{
		tempoLoop = T_LOOP;
		chao = false;
		pulo = true;
		afetado = false;
		estadoPadrao();
	}
	if (!chao)
	{
		if (pulo)
		{
			float velocY = aplicaGrav(1); // opt=1 caso pular
			figura->move(sf::Vector2f(0, -velocY));
		}
		else
		{
			float velocY = aplicaGrav(2); // opt=2 colisao inimigo
			figura->move(sf::Vector2f(0, -velocY));
		}
	}
	else
	{
		figura->move(sf::Vector2f(0, grav));
	} // pulo = false; }

	barraDano.setPosition(sf::Vector2f(figura->getPosition().x, figura->getPosition().y - figura->getSize().y - 5.0f));
	barraVida.setPosition(sf::Vector2f(barraDano.getPosition()));
}

void Jogador::moveJog2()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		figura->move(sf::Vector2f(andar, 0));
		animParado->Atualiza(0, true);
		animAndando->Atualiza(0, true);
		figura->setTexture(texAndando);
		figura->setTextureRect(animAndando->getMolde());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		figura->move(sf::Vector2f(-andar, 0));
		animParado->Atualiza(0, false);
		animAndando->Atualiza(0, false);
		figura->setTexture(texAndando);
		figura->setTextureRect(animAndando->getMolde());
	}
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		figura->move(sf::Vector2f(0, -andar));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		figura->move(sf::Vector2f(0, andar));
	}*/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && chao)
	{
		tempoLoop = T_LOOP;
		chao = false;
		pulo = true;
		afetado = false;
		estadoPadrao();
	}
	if (!chao)
	{
		if (pulo)
		{
			float velocY = aplicaGrav(1); // opt=1 caso pular
			figura->move(sf::Vector2f(0, -velocY));
		}
		else
		{
			float velocY = aplicaGrav(2); // opt=2 colisao inimigo
			figura->move(sf::Vector2f(0, -velocY));
		}
	}
	else
	{
		figura->move(sf::Vector2f(0, grav));
	} // pulo = false; }

	barraDano.setPosition(sf::Vector2f(figura->getPosition().x, figura->getPosition().y - figura->getSize().y - 5.0f));
	barraVida.setPosition(sf::Vector2f(barraDano.getPosition()));
}

void Jogador::estadoPadrao()
{
	grav = 0.5f;
	andar = 0.4f;
	figura->setFillColor(sf::Color::White);
	figura->setTexture(textureParado);
	figura->setTextureRect(animParado->getMolde());
}

void Jogador::efeitoNegativo(int id, Obstaculo *ob)
{ // TER FUNCAO EFEITO-NEGATIVO PARA CADA OBSTACULO EH MAIS BONITO EM QUESTAO DE CODIGO, JA QUE CADA EFEITO EH PROPRIO DE CADA OBSTACULO (CONSERTAR DPS)
	switch (id)
	{
	case 2:
		printf("dano: %f\n", ob->getDanar());
		printf("vida: %f\n", vida);
		tomaDano(ob->getDanar());

		figura->setFillColor(sf::Color::Red);
		break;
	case 4:
		figura->setFillColor(sf::Color(173, 216, 230));
		andar = 0.05f;
		break;

	case 5:
		estadoPadrao();
		break;
	}
}

void Jogador::executar()
{
	if (!neutralizado)
	{
		figura->setTexture(textureParado);
		figura->setTextureRect(animParado->getMolde());
		if (jogador == 0)
		{
			moveJog1();
		}
		else
		{
			moveJog2();
		}
		gGraf->desenhar(*this->figura);
		gGraf->desenhar(this->barraDano);
		gGraf->desenhar(this->barraVida);
	}
	else
	{
		figura->setPosition(sf::Vector2f(-20.f, -20.0f));
	}
}