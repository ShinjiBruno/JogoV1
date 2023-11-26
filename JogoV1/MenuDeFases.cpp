#include "MenuDeFases.h"

MenuDeFases::MenuDeFases() {

	titulo = new Texto("MENU", TAMANHO_MAX_TEXT, meioX, posicaoCentro.y - static_cast<float>(posicaoJanela.y / 2.2), font);

	fase1 = new Texto("Fase 1", TAMANHO_TEXT, meioX, posicaoCentro.y - static_cast<float>(posicaoJanela.y) / 3 + TAMANHO_TEXT, font);
	fase2 = new Texto("Fase 2", TAMANHO_TEXT, meioX, posicaoCentro.y - static_cast<float>(posicaoJanela.y) / 3 + TAMANHO_TEXT * 2 + DISTANCIA_Y, font);
	sair = new Texto("Voltar", TAMANHO_TEXT, meioX, posicaoCentro.y - static_cast<float>(posicaoJanela.y) / 3 + TAMANHO_TEXT * 3 + DISTANCIA_Y * 2, font);

	titulo->mudaCor("Yellow");

	listaOpcoes = { fase1, fase2, sair};
	nAlternativas = 3;

	fasePrimeira = false;
	faseSegunda = false;
}

MenuDeFases::~MenuDeFases() {

	delete titulo;
	delete fase1;
	delete fase2;
	delete sair;

	listaOpcoes.clear();
}

void MenuDeFases::executar() {

	gGraf->desenharTexto(titulo->getTxt());
	gGraf->desenharTexto(fase1->getTxt());
	gGraf->desenharTexto(fase2->getTxt());
	gGraf->desenharTexto(sair->getTxt());
}

void MenuDeFases::selecionar() {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {

		if (getLista()[0]->getSelecionado()) {
			fasePrimeira = true;
			faseSegunda = false;
			setEscolherJogadores(true);

			//comecar = true;
			
			comando = true;
			//voltar = false;
		}
		else if (getLista()[1]->getSelecionado()) {
			fasePrimeira = false;
			faseSegunda = true;
			setEscolherJogadores(true);

			//comecar = true;
			
			comando = true;
			//voltar = false;
		}
		else if (getLista()[2]->getSelecionado()) {
			setEscolherFase(false);
			comecar = false;
			
			comando = true;
			//gGraf->getWindow()->close();
			//voltar = true;
		}

	}
}

bool Menus::MenuDeFases::getFasePrimeira()
{
	return fasePrimeira;
}

bool MenuDeFases::getFaseSegunda() {
	return faseSegunda;
}