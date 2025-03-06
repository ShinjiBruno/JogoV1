#include "MenuPrincipal.h"

using namespace Menus;

bool MenuPrincipal::rank = false;

MenuPrincipal::MenuPrincipal()
{
	// meio da tela
	cout << "Inicializando Menu Principal" << endl;
	meioX = static_cast<float>(posicaoCentro.x);

	// seta as op��es, o texto e posi��o
	titulo = new Texto("CURSED++", TAMANHO_MAX_TEXT, meioX, posicaoCentro.y - static_cast<float>(posicaoJanela.y / 2.2), font);
	iniciar = new Texto("Jogar", TAMANHO_TEXT, meioX, posicaoCentro.y - static_cast<float>(posicaoJanela.y) / 3 + TAMANHO_TEXT, font);
	carregar = new Texto("Carregar Jogo", TAMANHO_TEXT, meioX, posicaoCentro.y - static_cast<float>(posicaoJanela.y) / 3 + TAMANHO_TEXT * 2 + DISTANCIA_Y, font);
	ranking = new Texto("Ranking", TAMANHO_TEXT, meioX, posicaoCentro.y - static_cast<float>(posicaoJanela.y) / 3 + TAMANHO_TEXT * 3 + DISTANCIA_Y * 2, font);
	sair = new Texto("Sair", TAMANHO_TEXT, meioX, posicaoCentro.y - static_cast<float>(posicaoJanela.y) / 3 + TAMANHO_TEXT * 4 + DISTANCIA_Y * 3, font);

	nAlternativas = 4;
	listaOpcoes = {iniciar, carregar, ranking, sair};

	// seta a cor do titulo
	titulo->mudaCor("Yellow");
}

MenuPrincipal::~MenuPrincipal()
{

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
	// desenha na tela
	gGraf->desenharTexto(titulo->getTxt());
	gGraf->desenharTexto(iniciar->getTxt());
	gGraf->desenharTexto(carregar->getTxt());
	gGraf->desenharTexto(ranking->getTxt());
	gGraf->desenharTexto(sair->getTxt());
}

void MenuPrincipal::selecionar()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{

		if (getLista()[0]->getSelecionado())
		{
			setEscolherFase(true);
			setComando(true);
		}
		else if (getLista()[1]->getSelecionado())
		{
			// carrega o jogo
		}
		else if (getLista()[2]->getSelecionado())
		{
			rank = true;
			principal = false;

			comando = true;
		}
		else if (getLista()[3]->getSelecionado())
		{

			// menuConfirmar
			getGgraf()->getWindow()->close();
		}
	}
}

void MenuPrincipal::setRank(bool ran)
{
	rank = ran;
}

bool MenuPrincipal::getRank()
{
	return rank;
}
