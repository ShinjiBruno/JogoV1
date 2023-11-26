#include "Entidade.h"
using namespace Entidades;

Entidade::Entidade(): andar(0.0f), danar(1.0f),
neutralizado(false), chao(true)
{
	grav = 0.9f;
}

Entidade::~Entidade() {
	grav = 0;
	andar = 0.0f;
}