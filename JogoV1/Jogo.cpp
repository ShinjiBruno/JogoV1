#include "Jogo.h"

Jogo::Jogo():
rec(sf::Vector2f(50.0f, 50.0f))
{
    window = GerenciadorGrafico::getInstancia();

    rec.setOrigin(sf::Vector2f(rec.getSize().x/2,rec.getSize().y/2));
    rec.setPosition(sf::Vector2f(50.0f, 50.0f));
    rec.setFillColor(sf::Color::Red);

    fase.criaInimigos();
    fase.criaObstaculos();
    fase.criaJogadores(static_cast<Entidade*>(&jogador1));

    executarJogo();

}
Jogo::~Jogo() {

}

void Jogo::executarJogo() {
	
	while (window->getWindow()->isOpen()) {
        sf::Event evento;
        while (window->getWindow()->pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                window->getWindow()->close();
            }
        }

        window->getWindow()->clear();

        fase.percorreLista();

        window->getWindow()->display();

	}

}
	

