#include "MenuPause.h"

using namespace Menus;

MenuPause::MenuPause()
{
	cout << "Inicializando Menu Pause" << endl;
	// reescala o tamanho do texto para o pause
	escalaPause = static_cast<unsigned int>(TAMANHO_MAX_TEXT * 1.3);
	escalaOpPause = static_cast<unsigned int>(TAMANHO_TEXT * 1.3);

	// seta as op��es, o texto e posi��o
	titulo = new Texto("PAUSE", escalaPause, posicaoCentro.x, posicaoCentro.y - static_cast<float>(posicaoJanela.y) / 2, font);
	iniciar = new Texto("Retornar", escalaOpPause, posicaoCentro.x, posicaoCentro.y - static_cast<float>(posicaoJanela.y) / 2, font);
	carregar = new Texto("Salvar", escalaOpPause, posicaoCentro.x, posicaoCentro.y - static_cast<float>(posicaoJanela.y) / 2, font);
	sair = new Texto("Sair", escalaOpPause, posicaoCentro.x, posicaoCentro.y - static_cast<float>(posicaoJanela.y) / 2, font);

	nAlternativas = 3;
	listaOpcoes = {iniciar, carregar, sair};

	// muda a cor do pause
	titulo->mudaCor("Yellow");
}

MenuPause::~MenuPause()
{
	delete titulo;
	delete iniciar;
	delete carregar;
	delete sair;

	delete font;
	listaOpcoes.clear();
}

void MenuPause::executar()
{
	// pega os novos valores da janela e da visualiza��o
	posicaoCentro = gGraf->getView()->getCenter();
	posicaoJanela = gGraf->getView()->getSize();
	tamJanela = gGraf->getWindow()->getSize();

	// seta as novas posi��es
	titulo->mudarPosicao(posicaoCentro.x, posicaoCentro.y - static_cast<float>(posicaoJanela.y / 2.3));
	iniciar->mudarPosicao(posicaoCentro.x, posicaoCentro.y - static_cast<float>(posicaoJanela.y) / 3 + TAMANHO_TEXT * 2 + DISTANCIA_Y);
	carregar->mudarPosicao(posicaoCentro.x, posicaoCentro.y - static_cast<float>(posicaoJanela.y) / 3 + TAMANHO_TEXT * 4 + DISTANCIA_Y * 2);
	sair->mudarPosicao(posicaoCentro.x, posicaoCentro.y - static_cast<float>(posicaoJanela.y) / 3 + TAMANHO_TEXT * 6 + DISTANCIA_Y * 3);

	// desenha na tela
	gGraf->desenharTexto(titulo->getTxt());
	gGraf->desenharTexto(iniciar->getTxt());
	gGraf->desenharTexto(carregar->getTxt());
	gGraf->desenharTexto(sair->getTxt());
}

void MenuPause::selecionar()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{

		if (getLista()[0]->getSelecionado())
		{
			comecar = true;
		}
		else if (getLista()[1]->getSelecionado())
		{
			// salva o jogo
		}
		else if (getLista()[2]->getSelecionado())
		{
			getGgraf()->getWindow()->close();
		}
	}
}
