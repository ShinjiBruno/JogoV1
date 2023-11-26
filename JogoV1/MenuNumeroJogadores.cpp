#include "MenuNumeroJogadores.h"

MenuNumeroJogadores::MenuNumeroJogadores()
{
	titulo = new Texto("MENU", TAMANHO_MAX_TEXT, meioX, posicaoCentro.y - static_cast<float>(posicaoJanela.y / 2.2), font);

	jogadorUm = new Texto("Um Jogador", TAMANHO_TEXT, meioX, posicaoCentro.y - static_cast<float>(posicaoJanela.y) / 3 + TAMANHO_TEXT, font);
	jogadorDois = new Texto("Dois Jogadores", TAMANHO_TEXT, meioX, posicaoCentro.y - static_cast<float>(posicaoJanela.y) / 3 + TAMANHO_TEXT * 2 + DISTANCIA_Y, font);
	sair = new Texto("Voltar", TAMANHO_TEXT, meioX, posicaoCentro.y - static_cast<float>(posicaoJanela.y) / 3 + TAMANHO_TEXT * 3 + DISTANCIA_Y * 2, font);

	titulo->mudaCor("Yellow");

	listaOpcoes = { jogadorUm, jogadorDois, sair };
	nAlternativas = 3;

	doisJogadores = false;
	umJogador = false;
}

MenuNumeroJogadores::~MenuNumeroJogadores()
{
	delete titulo;
	delete jogadorUm;
	delete jogadorDois;
	delete sair;
}

void Menus::MenuNumeroJogadores::executar()
{
	gGraf->desenharTexto(titulo->getTxt());
	gGraf->desenharTexto(jogadorUm->getTxt());
	gGraf->desenharTexto(jogadorDois->getTxt());
	gGraf->desenharTexto(sair->getTxt());
}

void Menus::MenuNumeroJogadores::selecionar()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {

		if (getLista()[0]->getSelecionado()) {
			umJogador = true;
			doisJogadores = false;

			comecar = true;

			comando = true;
		}
		else if (getLista()[1]->getSelecionado()) {
			umJogador = false;
			doisJogadores = true;

			comecar = true;

			comando = true;
		}
		else if (getLista()[2]->getSelecionado()) {
			setEscolherJogadores(false);
			comecar = false;

			comando = true;
		}
	}

}

bool Menus::MenuNumeroJogadores::getUmJogadores()
{
	return umJogador;
}

bool Menus::MenuNumeroJogadores::getDoisJogadores()
{
	return doisJogadores;
}


