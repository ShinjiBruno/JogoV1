#include "Jogo.h"

Jogo::Jogo()
{
    window = GerenciadorGrafico::getInstancia();

    fase.criaJogadores(static_cast<Entidade*>(&jogador1));
    fase.criaInimigos();
    fase.criaObstaculos();
    
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
	

