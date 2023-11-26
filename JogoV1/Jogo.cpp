#include "Jogo.h"

Jogo::Jogo()
{
    gerenciaGraf = GerenciadorGrafico::getInstancia();

    menu.executarMenu(true);
    criaFase();

    executarJogo();
}
Jogo::~Jogo() {

}

void Jogo::configuracaoGraf() {
    if (!jogador1.getNeutralizado()) {
        gerenciaGraf->getView()->setCenter(jogador1.getFigura()->getPosition());
    }
    else {
        gerenciaGraf->getView()->setCenter(jogador2.getFigura()->getPosition());

    }
    sf::View* v = gerenciaGraf->getView();
    v->setSize(sf::Vector2f(800.0f, 1000.0f));
    gerenciaGraf->getWindow()->setView(*v);
}

void Jogo::executarJogo() {

    while (gerenciaGraf->getWindow()->isOpen()) {
        sf::Event evento;
        while (gerenciaGraf->getWindow()->pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                gerenciaGraf->getWindow()->close();
            }
            if (sf::Event::Resized) {
                gerenciaGraf->redimensiona();
                break;
            }
        }

        gerenciaGraf->getWindow()->clear();

        configuracaoGraf();

        if (menu.getFaseUm()) {
            fase1.percorreLista();
        }
        else if (menu.getFaseDois()) {
            fase2.percorreLista();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            menu.executarMenu(false);
        }

        gerenciaGraf->getWindow()->display();

    }

}

void Jogo::criaFase() {

    if (menu.getFaseUm()) {
        fase1.criaInimigos();
        fase1.criaObstaculos();

        if (menu.getJogadorUm()) {
            fase1.criaJogadores(static_cast<Entidade*>(&jogador1));
        }
        else if (menu.getJogadorDois()) {
            fase1.criaJogadores(static_cast<Entidade*>(&jogador1), static_cast<Entidade*>(&jogador2));
        }
    }

    else if (menu.getFaseDois()) {
        fase2.criaInimigos();
        fase2.criaObstaculos();

        if (menu.getJogadorUm()) {
            fase2.criaJogadores(static_cast<Entidade*>(&jogador1));
        }
        else if (menu.getJogadorDois()) {
            fase2.criaJogadores(static_cast<Entidade*>(&jogador1), static_cast<Entidade*>(&jogador2));
        }
    }
}
