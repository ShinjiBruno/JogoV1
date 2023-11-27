#include "GerenciadorGrafico.h"
using namespace Gerenciadores;

GerenciadorGrafico* GerenciadorGrafico::gGrafInstancia = nullptr;

GerenciadorGrafico::GerenciadorGrafico() {
	window = new sf::RenderWindow(sf::VideoMode(1200, 800), "Jogo Tecprog");
	event = new sf::Event();
	view = new sf::View(sf::Vector2f(1750.0f, 0.0f), sf::Vector2f(700.0f, 900.0f));
	//view = new sf::View();
	window->setView(*view);
}

GerenciadorGrafico::~GerenciadorGrafico() {
	window = NULL;
	event = NULL;
}

void GerenciadorGrafico::redimensiona() {
	float proporcao = float(window->getSize().x) / float(window->getSize().y);
	view->setSize(ALT_MAX * proporcao, ALT_MAX);
	window->setView(*view);
}