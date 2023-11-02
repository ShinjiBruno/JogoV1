#include "Personagem.h"
using namespace Entidades;
using namespace Personagens;

Personagem::Personagem(): danar(-1.0f), vida(-1.0f), tempoLoop(T_LOOP) {

}

Personagem::~Personagem() {
	danar = -1.0f;
	vida = -1.0f;
}

float Personagem::calculaGrav(float alturaMax) {
	//usar a equacao horaria de posicao: vf = v0 - g.t, onde v0 = sqrt(2.g.H), H eh altura max
	tempoLoop += T_LOOP;
	float v0 = sqrt(2 * alturaMax);
	float vf = v0 - (tempoLoop);
	return vf;
	
}