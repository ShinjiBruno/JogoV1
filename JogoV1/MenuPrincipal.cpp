#include "MenuPrincipal.h"

using namespace Menus;

MenuPrincipal::MenuPrincipal() {
	//meio da tela
	meioX = static_cast<float>(tamJanela.x / 2);

	//seta as opções, o texto e posição
	titulo = new Texto("MENU", TAMANHO_MAX_TEXT, meioX, posicaoCentro.y - static_cast<float>(posicaoJanela.y / 2.2), font);
	iniciar = new Texto("Jogar", TAMANHO_TEXT, meioX, posicaoCentro.y - static_cast<float>(posicaoJanela.y) / 3 + TAMANHO_TEXT, font);
	carregar = new Texto("Carregar Jogo", TAMANHO_TEXT, meioX, posicaoCentro.y - static_cast<float>(posicaoJanela.y) / 3 + TAMANHO_TEXT * 2 +DISTANCIA_Y, font);
	ranking = new Texto("Ranking", TAMANHO_TEXT, meioX, posicaoCentro.y - static_cast<float>(posicaoJanela.y) / 3 + TAMANHO_TEXT * 3 + DISTANCIA_Y * 2, font);
	sair = new Texto("Sair", TAMANHO_TEXT, meioX, posicaoCentro.y - static_cast<float>(posicaoJanela.y) / 3 + TAMANHO_TEXT * 4 + DISTANCIA_Y *3, font);

	nAlternativas = 4;
	listaOpcoes = { iniciar, carregar, ranking, sair };

	//seta a cor do titulo
	titulo->mudaCor("Yellow");

}

MenuPrincipal::~MenuPrincipal() {

	delete titulo;
	delete iniciar;
	delete carregar;
	delete ranking;
	delete sair;

	listaOpcoes.clear();

	delete font;
}


void MenuPrincipal::executar()
{
	//desenha na tela
	gGraf->desenharTexto(titulo->getTxt());
	gGraf->desenharTexto(iniciar->getTxt());
	gGraf->desenharTexto(carregar->getTxt());
	gGraf->desenharTexto(ranking->getTxt());
	gGraf->desenharTexto(sair->getTxt());
}

void MenuPrincipal::selecionar()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {

		if (getLista()[0]->getSelecionado()) {
			setEscolherFase(true);
			setComando(true);
		}
		else if (getLista()[1]->getSelecionado()) {
			//carrega o jogo
		}
		else if (getLista()[2]->getSelecionado()) {
			//carrega o menu ranking
		}
		else if (getLista()[3]->getSelecionado()) {

			//menuConfirmar
			getGgraf()->getWindow()->close();
		}
	}

}

