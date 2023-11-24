#include "Jogo.h"

Jogo::Jogo()
{
    gerenciaGraf = GerenciadorGrafico::getInstancia();
    
    /*fase1.criaJogadores(static_cast<Entidade*>(&jogador1), static_cast<Entidade*>(&jogador2));
    fase1.criaInimigos();
    fase1.criaObstaculos();*/
    
    fase2.criaJogadores(static_cast<Entidade*>(&jogador1), static_cast<Entidade*>(&jogador2));
    fase2.criaInimigos();
    fase2.criaObstaculos();
    
    executarJogo();
}
Jogo::~Jogo() {

}

void Jogo::configuracaoGraf() {
    gerenciaGraf->getView()->setCenter(jogador1.getFigura()->getPosition());
    sf::View* v = gerenciaGraf->getView();

    gerenciaGraf->getWindow()->setView(*v);
}

void Jogo::executarJogo() {
	
	while (gerenciaGraf->getWindow()->isOpen()) {
        sf::Event evento;
        while (gerenciaGraf->getWindow()->pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                gerenciaGraf->getWindow()->close();
            }
        }

        gerenciaGraf->getWindow()->clear();

        configuracaoGraf();

        fase2.percorreLista();

        gerenciaGraf->getWindow()->display();

	}

}
	

