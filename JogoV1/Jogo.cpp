#include "Jogo.h"

Jogo::Jogo():
window(sf::VideoMode(800, 600), "My SFML window"),
circ(50.0f)
{
    circ.setFillColor(sf::Color::Red);
    executarJogo();

}
Jogo::~Jogo() {

}

void Jogo::executarJogo() {
	
	while (window.isOpen()) {
        sf::Event evento;
        while (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();

        window.draw(circ);

        window.display();

	}

}
	

