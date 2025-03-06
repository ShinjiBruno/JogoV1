#include "Menu.h"

using namespace Menus;

bool Menu::principal = false;
bool Menu::comecar = false;
bool Menu::escolherFase = false;
bool Menu::escolherJogadores = false;
bool Menu::escolherNome = false;
bool Menu::comando = false;

// classe abstrata
Menu::Menu()
{

	// endere�o da fonte
	endereco = "fonts/Thalia.otf";
	font = new Font;

	font->loadFromFile(endereco);

	// definindo posi��es
	posicaoCentro = gGraf->getView()->getCenter();
	posicaoJanela = gGraf->getView()->getSize();
	tamJanela = gGraf->getWindow()->getSize();

	nAlternativas = 0;
	i = 0;

	// seleciona o meio da janela(funciona apenas no menu principal)
	meioX = static_cast<float>(posicaoCentro.x);

	comando = false;
}

Menu::~Menu()
{
}

// muda a cor para representar a op��o selecionada
void Menu::representaSelecionado()
{
	for (i = 0; i < getNumOp(); i++)
	{
		if (listaOpcoes[i]->getSelecionado())
		{
			listaOpcoes[i]->mudaCor("Blue");
		}
		else
		{
			listaOpcoes[i]->mudaCor("White");
		}
	}
}

// percorre a lista dizendo qual � a op��o selecionada.
void Menu::setSelecionado(int max, int opcao)
{

	for (i = 0; i <= max; i++)
	{
		listaOpcoes[i]->setSelecionado(false);
	}
	listaOpcoes[opcao]->setSelecionado(true);
	representaSelecionado();
}

vector<Texto *> Menu::getLista()
{
	return listaOpcoes;
}

int Menu::getNumOp()
{
	return nAlternativas;
}

void Menus::Menu::selecionar()
{
}

GerenciadorGrafico *Menu::getGgraf()
{
	return gGraf;
}

sf::Font *Menu::getFonte()
{
	return font;
}

bool Menu::getComecar()
{
	return comecar;
}

void Menu::setComecar(bool comec)
{
	comecar = comec;
}

bool Menu::getPrincipal()
{
	return principal;
}

bool Menu::getComando()
{
	return comando;
}

bool Menu::getEscolherFase()
{
	return escolherFase;
}

bool Menu::getEscolherJogadores()
{
	return escolherJogadores;
}

bool Menu::getEscolherNome()
{
	return escolherNome;
}

void Menu::setComando(bool pressionado)
{
	comando = pressionado;
}

void Menu::setEscolherFase(bool escolhido)
{
	escolherFase = escolhido;
}

void Menu::setEscolherJogadores(bool escolhido)
{
	escolherJogadores = escolhido;
}

void Menu::setEscolherNome(bool escolhido)
{
	escolherNome = escolhido;
}

void Menu::setPrincipal(bool primeiro)
{
	principal = primeiro;
}