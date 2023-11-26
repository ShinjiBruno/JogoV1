#include "GerenciadorGrafico.h"
using namespace Gerenciadores;

GerenciadorGrafico* GerenciadorGrafico::gGrafInstancia = nullptr;

GerenciadorGrafico::GerenciadorGrafico() {
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "Jogo Tecprog");
	event = new sf::Event();
	//view = new sf::View(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(800.0f, 1000.0f));
	view = new sf::View();
}

GerenciadorGrafico::~GerenciadorGrafico() {
	window = NULL;
	event = NULL;
}

void GerenciadorGrafico::redimensiona() {
	float proporcao = float(window->getSize().x) / float(window->getSize().y);
	view->setSize(ALT_MAX * proporcao, ALT_MAX);
}