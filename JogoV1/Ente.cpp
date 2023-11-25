#include "Ente.h"

Ente::Ente() {
	figura = new sf::RectangleShape(sf::Vector2f(-1.0f, -1.0f));
	gGraf = GerenciadorGrafico::getInstancia();
	//id++;
}

Ente::~Ente() { figura->setOrigin(sf::Vector2f(-1.0f, -1.0f)); gGraf = NULL; }

