#include "Menu.h"

using namespace Menus;
using namespace Gerenciadores;

Menu::Menu() {

	//endereço da fonte
	endereco = "Thalia.otf";
	font.loadFromFile(endereco);

	//definindo posições
	topoY = gGraf->getView()->getCenter().y / 10;  // TAMANHO_TEXT;

	//definindo o meio da janela
	meioX = gGraf->getWindow()->getSize().x / 2.0f;

	//as posições são apartir do canto superior esquerdo
	Texto* pausar= new Texto("PAUSE", TAMANHO_MAX_TEXT, meioX, 10.0f, &font);
	Texto* nomeJ = new Texto("MENU", TAMANHO_MAX_TEXT, meioX, 10.0f, &font);

	Texto* inici = new Texto("Jogar", TAMANHO_TEXT, meioX, DISTANCIA_Y, &font);
	Texto* carre = new Texto("Carregar Jogo", TAMANHO_TEXT, meioX, DISTANCIA_Y, &font);
	Texto* rank = new Texto("Ranking", TAMANHO_TEXT, meioX, DISTANCIA_Y, &font);

	Texto* abandonar = new Texto("Retornar", TAMANHO_TEXT, meioX, DISTANCIA_Y, &font);
	//Texto* retornar = new Texto("voltar", TAMANHO_TEXT, meioX, DISTANCIA_Y, &font);

	// definindo os ponteiros, contendo o texto que aparece no jogo
	pause = pausar;
	nomeJogo = nomeJ;

	iniciar = inici;
	carregar = carre;
	ranking = rank;

	sair = abandonar;
	//voltar = retornar;

	//redefine as posições
	pause->mudarPosicao(meioX, topoY);
	nomeJogo->mudarPosicao(meioX, topoY);

	iniciar->mudarPosicao(meioX,(topoY + DISTANCIA_Y + iniciar->getTxt().getGlobalBounds().height));
	carregar->mudarPosicao(meioX, (topoY + DISTANCIA_Y * 2 + carregar->getTxt().getGlobalBounds().height));
	ranking->mudarPosicao(meioX, (topoY + DISTANCIA_Y * 3 + ranking->getTxt().getGlobalBounds().height));

	sair->mudarPosicao(meioX, (topoY + DISTANCIA_Y * 4 + sair->getTxt().getGlobalBounds().height));



	//voltar->mudarPosicao(meioX, (topoY + DISTANCIA_Y * 4 + voltar->getTxt().getGlobalBounds().height));

	nomeJogo->mudaCor("Yellow");
	pause->mudaCor("Yellow");

	op = 0;
	i = 0;
	comando = false;
	comecar = false;

	listaOpcoes = { iniciar , carregar, ranking, sair };
}

Menu::~Menu() {

	delete pause;
	delete nomeJogo;
	delete iniciar;
	delete carregar;
	delete ranking;
	delete sair;

	listaOpcoes.clear();
}

void Menu::executeMenu(bool Principal)
{
	comecar = false;

	gGraf->getWindow()->clear(sf::Color::Black);

	sf::Clock relogio;
	sf::Time time;


	while (gGraf->getWindow()->isOpen() && !comecar) {

		time = relogio.getElapsedTime();
		
		//se deu 0.2segundo
		if (time.asSeconds() >= 0.2) {
			comando = false;
		}


		sf::Event evento;
		while (gGraf->getWindow()->pollEvent(evento)) {
			if (evento.type == sf::Event::Closed) {
				gGraf->getWindow()->close();
			}
		}

		gGraf->getWindow()->clear(sf::Color::Black);

		//Faz as opções
		if (!comando) {
			selecionadorOp();

			if (comando) {
				relogio.restart();
			}
		}

		//desenha as opcoes
		if (Principal) {
			desenharMenuPrincipal();
		}
		else {
			desenharMenuPause();
		}

		executar();

		gGraf->getWindow()->display();

	}
}

void Menu::executar()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {

		if (listaOpcoes[0]->getSelecionado()) {
			comecar = true;
		}
		else if (listaOpcoes[1]->getSelecionado()) {
				//carrega o jogo
		}
		else if (listaOpcoes[2]->getSelecionado()) {
				//carrega o menu ranking
		}
		else if (listaOpcoes[3]->getSelecionado()) {
			gGraf->getWindow()->close();
		}
	}
}

void Menu::desenharMenuPause() {
	//setar com base na janela do gGraf!
	
	const sf::Vector2f posicao = gGraf->getView()->getCenter();

	sf::Vector2u tamanhoJanela = gGraf->getWindow()->getSize();

	
	// utilizando valores estáticos
	pause->mudarPosicao(posicao.x, static_cast<float>(posicao.y - tamanhoJanela.y/1.6) );
	iniciar->mudarPosicao(posicao.x, posicao.y - static_cast<float>(tamanhoJanela.y)/2  + DISTANCIA_Y );
	carregar->mudarPosicao(posicao.x, posicao.y - static_cast<float>(tamanhoJanela.y)/2 + DISTANCIA_Y*2);
	ranking->mudarPosicao(posicao.x, posicao.y - static_cast<float>(tamanhoJanela.y)/2 + DISTANCIA_Y*3);
	sair->mudarPosicao(posicao.x, posicao.y - static_cast<float>(tamanhoJanela.y)/2 + DISTANCIA_Y*4);
	
	gGraf->desenharTexto(pause->getTxt());
	gGraf->desenharTexto(iniciar->getTxt());
	gGraf->desenharTexto(carregar->getTxt());
	gGraf->desenharTexto(ranking->getTxt());
	gGraf->desenharTexto(sair->getTxt());
}


void Menu::desenharMenuPrincipal() {

	gGraf->desenharTexto(nomeJogo->getTxt());
	gGraf->desenharTexto(iniciar->getTxt());
	gGraf->desenharTexto(carregar->getTxt());
	gGraf->desenharTexto(ranking->getTxt());
	gGraf->desenharTexto(sair->getTxt());
}

void Menu::opSelecionado() {

	for (i = 0; i <= OPCOES_MAX; i++)
	{
		if (listaOpcoes[i]->getSelecionado())
		{
			listaOpcoes[i]->mudaCor("Blue");
		}
		else {
			listaOpcoes[i]->mudaCor("White");
		}
	}
}

void Menu::selecionadorOp() {

	sf::Clock relogio;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		op--;

		if (op < OPCOES_MIN) {
			op = OPCOES_MAX;
		}
		comando = true;
	}

	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		op++;
		
		if (op > OPCOES_MAX) {
			op = OPCOES_MIN;
		}
		comando = true;
	}

	for (i = 0; i <= OPCOES_MAX; i++) {
		listaOpcoes[i]->setSelecionado(false);
	}
	listaOpcoes[op]->setSelecionado(true);


	opSelecionado();
	
}

/*
bool Menu::getComecar() {
	return comecar;
}
*/

