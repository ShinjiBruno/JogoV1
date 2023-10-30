#include "Personagem.h"
using namespace Entidades;
using namespace Personagens;

Personagem::Personagem(): danar(-1.0f), vida(-1.0f){

}

Personagem::~Personagem() {
	danar = -1.0f;
	vida = -1.0f;
}