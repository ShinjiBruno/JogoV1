#include "Personagem.h"
using namespace Entidades;

Personagem::Personagem(): danar(-1.0f), vida(-1.0f) {
}

Personagem::~Personagem() {
	danar = -1.0f;
	vida = -1.0f;
}