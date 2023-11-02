#include "Entidade.h"
using namespace Entidades;

Entidade::Entidade():pos(-1.0f,-1.0f), andar(0.0f),
neutralizado(false), chao(true)
{
	grav = 0.9f;
}

Entidade::~Entidade() {
	pos = sf::Vector2f(-1.0f,-1.0f);
	grav = 0;
	andar = 0.0f;
}