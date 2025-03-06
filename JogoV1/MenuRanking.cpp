#include "MenuRanking.h"

MenuRanking::MenuRanking()
{
	pegaNomePontos();

	titulo = new Texto("CURSED++", TAMANHO_MAX_TEXT, meioX, posicaoCentro.y - static_cast<float>(posicaoJanela.y / 2.2), font);
	primeiro = new Texto(teste[0], TAMANHO_TEXT, meioX / 2, posicaoCentro.y - static_cast<float>(posicaoJanela.y / 2.8) + TAMANHO_TEXT, font);
	segundo = new Texto(teste[1], TAMANHO_TEXT, meioX / 2, posicaoCentro.y - static_cast<float>(posicaoJanela.y / 2.8) + TAMANHO_TEXT * 2 + DISTANCIA_Y, font);
	terceiro = new Texto(teste[2], TAMANHO_TEXT, meioX / 2, posicaoCentro.y - static_cast<float>(posicaoJanela.y / 2.8) + TAMANHO_TEXT * 3 + DISTANCIA_Y * 2, font);
	quarto = new Texto(teste[3], TAMANHO_TEXT, meioX / 2, posicaoCentro.y - static_cast<float>(posicaoJanela.y / 2.8) + TAMANHO_TEXT * 4 + DISTANCIA_Y * 3, font);
	quinto = new Texto(teste[4], TAMANHO_TEXT, meioX / 2, posicaoCentro.y - static_cast<float>(posicaoJanela.y / 2.8) + TAMANHO_TEXT * 5 + DISTANCIA_Y * 4, font);
	sexto = new Texto(teste[5], TAMANHO_TEXT, meioX / 2, posicaoCentro.y - static_cast<float>(posicaoJanela.y / 2.8) + TAMANHO_TEXT * 6 + DISTANCIA_Y * 5, font);
	sair = new Texto("Sair", TAMANHO_TEXT, meioX, posicaoCentro.y - static_cast<float>(posicaoJanela.y / 2.8) + TAMANHO_TEXT * 7 + DISTANCIA_Y * 6, font);

	listaOpcoes = {sair};
	nAlternativas = 1;

	titulo->mudaCor("Yellow");

	primeiro->mudaCor("Magenta");
	segundo->mudaCor("Magenta");
	terceiro->mudaCor("Magenta");
	quarto->mudaCor("Magenta");
	quinto->mudaCor("Magenta");
	sexto->mudaCor("Magenta");

	voltar = false;
}

MenuRanking::~MenuRanking()
{
	delete titulo;
	delete primeiro;
	delete segundo;
	delete terceiro;
	delete quarto;
	delete quinto;
	delete sexto;
	delete sair;

	colocacoes.close();

	listaOpcoes.clear();
}

void MenuRanking::executar()
{

	gGraf->desenharTexto(titulo->getTxt());

	gGraf->desenharTexto(primeiro->getTxt());
	gGraf->desenharTexto(segundo->getTxt());
	gGraf->desenharTexto(terceiro->getTxt());
	gGraf->desenharTexto(quarto->getTxt());
	gGraf->desenharTexto(quinto->getTxt());
	gGraf->desenharTexto(sexto->getTxt());

	gGraf->desenharTexto(sair->getTxt());
}

void MenuRanking::selecionar()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
	{

		if (getLista()[0]->getSelecionado())
		{
			voltar = true;
			comando = true;
		}
	}
}

bool MenuRanking::getVoltar()
{
	return voltar;
}

void MenuRanking::setVoltar(bool vol)
{
	voltar = vol;
}

void MenuRanking::pegaNomePontos()
{

	// colocacoes.open("Ranking.txt");

	// if (colocacoes.is_open())
	// {
	// 	i = 0;
	// 	while (!colocacoes.eof())
	// 	{

	// 		getline(colocacoes, nomePonto);
	// 		teste.push_back(nomePonto);

	// 		cout << teste[i] << endl;
	// 		/*
	// 		colocacoes >> nomePonto;
	// 		posicao.push_back(nomePonto);
	// 		colocacoes >> nomePonto;
	// 		nomes.push_back(nomePonto);
	// 		colocacoes >> nomePonto;
	// 		pontos.push_back(nomePonto);

	// 		cout << posicao[i] << nomes[i] << " - "<< pontos[i] << endl;
	// 		*/
	// 		i++;
	// 	}
	// }
	// else
	// {
	// 	cout << "N�O FOI POSSIVEL LER ESSA MERDA" << endl;
	// }
	// colocacoes.close();
}