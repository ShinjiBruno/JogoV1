#include "Entidade.h"
using namespace Entidades;

Entidade::Entidade():pos(-1.0f,-1.0f), velocX(0.0f),
velocY(0.0f), neutralizado(false)
{
	grav = 0.9f;
}

Entidade::~Entidade() {
	pos = sf::Vector2f(-1.0f,-1.0f);
	grav = 0;
	velocX = 0.0f;
	velocY = 0.0f;
}