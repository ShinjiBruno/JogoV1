#include "GerenciadorGrafico.h"
using namespace Gerenciadores;

GerenciadorGrafico* GerenciadorGrafico::gGrafInstancia = nullptr;

GerenciadorGrafico::GerenciadorGrafico() {
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "Jogo Tecprog");
	event = new sf::Event();
}

GerenciadorGrafico::~GerenciadorGrafico() {
	window = NULL;
	event = NULL;
}