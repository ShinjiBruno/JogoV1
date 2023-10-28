#include "GerenciadorGrafico.h"
using namespace Gerenciadores;

GerenciadorGrafico* GerenciadorGrafico::gGrafInstancia = nullptr;

GerenciadorGrafico::GerenciadorGrafico() {
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "Jogo Tecprog");
}

GerenciadorGrafico::~GerenciadorGrafico() {
	window = NULL;
}