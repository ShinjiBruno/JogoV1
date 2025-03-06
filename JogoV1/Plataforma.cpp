#include "Plataforma.h"
using namespace Entidades;
using namespace Obstaculos;

int Plataforma::qnt = 0;
float Plataforma::dif = 0.0f;

Plataforma::Plataforma(int f) : fase(f), altura(0)
{
	id = 5;
	grav = 0;
	textureParado = new sf::Texture();
	if (textureParado->loadFromFile("assets/chaoF1.png"))
		;

	figura->setSize(sf::Vector2f(7000.0f, 50.0f));
	figura->setOrigin(sf::Vector2f(figura->getSize().x / 2, figura->getSize().y / 2));
	figura->setPosition(sf::Vector2f(3500.0f, 250.0f));
	// figura->setFillColor(sf::Color::Green);
	figura->setTexture(textureParado);

	qnt += 1;
}

Plataforma::~Plataforma()
{
}

void Plataforma::configuraObstaculo()
{
	std::mt19937 rng(std::random_device{}()); // gerador de numeros aleatorios (mto mais eficiente que rand())
	std::uniform_int_distribution<int> distribution1(350, 800);
	std::uniform_int_distribution<int> distribution2(10, 100);
	int aleatorio = distribution1(rng);
	altura = distribution2(rng);
	float prob = (float)(aleatorio - distribution1.min()) / (distribution1.max() - distribution1.min());

	printf("prob = %f\n", prob);
	if (textureParado->loadFromFile("assets/platF1.png"))
	{
	}

	if (qnt != 0)
	{
		if (fase == 1)
		{
			this->figura->setSize(sf::Vector2f(100.0f, 50.0f));
			this->figura->setOrigin(sf::Vector2f(this->figura->getSize().x / 2, this->figura->getSize().y / 2));
			this->figura->setPosition(sf::Vector2f((dif + aleatorio), 100.0f - distribution2(rng)));
			// this->figura->setFillColor(sf::Color::Green);
			figura->setTexture(textureParado);

			this->dif += aleatorio;
		}
		else if (fase == 2)
		{
			if (prob > 0.5f)
			{
				this->figura->setSize(sf::Vector2f(100.0f, 50.0f));
				this->figura->setOrigin(sf::Vector2f(this->figura->getSize().x / 2, this->figura->getSize().y / 2));
				this->figura->setPosition(sf::Vector2f((dif + aleatorio), 100.0f - distribution2(rng)));
				// this->figura->setFillColor(sf::Color::Green);
				figura->setTexture(textureParado);

				this->dif += aleatorio;
			}
			else
			{
				this->figura->setSize(sf::Vector2f(100.0f, 100.0f + altura));
				this->figura->setOrigin(sf::Vector2f(this->figura->getSize().x / 2, this->figura->getSize().y / 2));
				this->figura->setPosition(sf::Vector2f((dif + aleatorio), 225.0f - (50.0f + altura) / 2));
				// this->figura->setFillColor(sf::Color::Green);
				figura->setTexture(textureParado);

				this->dif += aleatorio;
			}
		}
	}
}

void Plataforma::executar()
{
	gGraf->desenhar(*this->figura);
}