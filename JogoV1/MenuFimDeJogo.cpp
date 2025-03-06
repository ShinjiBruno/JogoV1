#include "MenuFimDeJogo.h"

MenuFimDeJogo::MenuFimDeJogo()
{
	cout << "Inicializando Menu Fim" << endl;

	escala = 1.2f;

	dois = false;
	ganhou = false;

	pontuacao1 = "Pontos Jogador 1 = ";
	pontuacao2 = "Pontos Jogador 2 = ";

	titulo = new Texto("FIM DE JOGO", TAMANHO_MAX_TEXT, posicaoCentro.x, posicaoCentro.y - static_cast<float>(posicaoJanela.y / 2.2), font);
	mensagem = new Texto("Voce foi neutralizado", TAMANHO_TEXT, posicaoCentro.x, posicaoCentro.y - static_cast<float>(posicaoJanela.y / 3), font);
	pontosUm = new Texto(pontuacao1, TAMANHO_TEXT, posicaoCentro.x, posicaoCentro.y - static_cast<float>(posicaoJanela.y / 3) + TAMANHO_TEXT, font);
	pontosDois = new Texto(pontuacao2, TAMANHO_TEXT, posicaoCentro.x, posicaoCentro.y - static_cast<float>(posicaoJanela.y / 3) + TAMANHO_TEXT * 2, font);

	sair = new Texto("Sair", TAMANHO_TEXT * escala, posicaoCentro.x, posicaoCentro.y - static_cast<float>(posicaoJanela.y / 3 + TAMANHO_TEXT * 3 + DISTANCIA_Y * 2), font);

	nAlternativas = 1;
	listaOpcoes = {sair};

	titulo->mudaCor("Red");

	pontosUm->mudaCor("Green");
	pontosDois->mudaCor("Green");
}

MenuFimDeJogo::~MenuFimDeJogo()
{

	delete titulo;
	delete mensagem;
	delete pontosUm;
	delete pontosDois;
	delete sair;

	listaOpcoes.clear();
}

void MenuFimDeJogo::executar()
{
	posicaoCentro = gGraf->getView()->getCenter();
	posicaoJanela = gGraf->getView()->getSize();
	tamJanela = gGraf->getWindow()->getSize();

	titulo->mudarPosicao(posicaoCentro.x, posicaoCentro.y - static_cast<float>(posicaoJanela.y / 2.5));
	mensagem->mudarPosicao(posicaoCentro.x, posicaoCentro.y - static_cast<float>(posicaoJanela.y / 3.5));
	pontosUm->mudarPosicao(posicaoCentro.x, posicaoCentro.y - static_cast<float>(posicaoJanela.y / 3.5) + TAMANHO_TEXT * 2);

	sair->mudarPosicao(posicaoCentro.x, posicaoCentro.y - static_cast<float>(posicaoJanela.y / 3.5) + TAMANHO_TEXT * 4 + DISTANCIA_Y * 3);

	if (ganhou)
	{
		titulo->mudaPalavra("CONCLUIDO");
		mensagem->mudaPalavra("VOCE TERMINOU A FASE");
	}

	gGraf->desenharTexto(titulo->getTxt());
	gGraf->desenharTexto(mensagem->getTxt());
	gGraf->desenharTexto(pontosUm->getTxt());

	if (dois)
	{

		pontosDois->mudarPosicao(posicaoCentro.x, posicaoCentro.y - static_cast<float>(posicaoJanela.y / 3.5) + TAMANHO_TEXT * 3);
		gGraf->desenharTexto(pontosDois->getTxt());
	}

	gGraf->desenharTexto(sair->getTxt());
}

void MenuFimDeJogo::selecionar()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{

		if (getLista()[0]->getSelecionado())
		{
			gGraf->getWindow()->close();
		}
	}
}

void Menus::MenuFimDeJogo::setPontos2(int pontuac)
{
	pontuacao2 += to_string(pontuac);

	pontosDois->mudaPalavra(pontuacao2);
}

void Menus::MenuFimDeJogo::setGanhou(bool win)
{
	ganhou = win;
}

void Menus::MenuFimDeJogo::setDois(bool two)
{
	dois = two;
}

void MenuFimDeJogo::setPontos1(int pontuac)
{

	pontuacao1 += to_string(pontuac);
	pontosUm->mudaPalavra(pontuacao1);
}