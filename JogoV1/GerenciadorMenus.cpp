#include "GerenciadorMenus.h"



GerenciadorMenus::GerenciadorMenus()
{
	op = 0;
	i = 0;

	//principal = true;
	comando = false; 
	faseUm = false;
	faseDois = false;
	fimDeJogo = false;

	pressionado = true;
	//menu2 = false;

	fundoMenu = new BackGround(0);
}

GerenciadorMenus::~GerenciadorMenus(){

}

void GerenciadorMenus::executarMenu(bool primeiro) 
{
	Menu::setPrincipal(primeiro);
	Menu::setComecar(false);

	menuPrincipal.getGgraf()->getWindow()->clear(sf::Color::Black);

	sf::Clock relogioOp, tempo;
	sf::Clock* relogioEnter= &tempo;
	sf::Time tempoOp, tempoEnter;
	
	while (menuPrincipal.getGgraf()->getWindow()->isOpen() && !Menu::getComecar()) {

		//relogio para atrasar o comando de selecionar
		tempoOp = relogioOp.getElapsedTime();

		//se deu 0.2segundo
		if (tempoOp.asSeconds() >= 0.2) {
			comando = false;
		}

		sf::Event evento;
		while (menuPrincipal.getGgraf()->getWindow()->pollEvent(evento)) {
			if (evento.type == sf::Event::Closed) {
				menuPrincipal.getGgraf()->getWindow()->close();
			}
			if (sf::Event::Resized) {
				menuPrincipal.getGgraf()->redimensiona();
				break;
			}
		}

		menuPrincipal.getGgraf()->getWindow()->clear(sf::Color::Black);
		fundoMenu->fundoFase();

		//alterna as opções
		if (!comando) {
			selecionadorOp();

			//se fez comando
			if (comando) {
				relogioOp.restart();
			}
		}

		verificaComando(relogioEnter);

		//exibe e exexecuta de fato os menus
		//se é um dos menus principais
		if (Menu::getPrincipal()) {

			//verificaComando(relogioEnter);
			// verifica se é o primeiro menu o inicial
			if (Menu::getPrincipal() && !menuPrincipal.getEscolherFase()) {
				
				//exibe na tela
				menuPrincipal.executar();

				//recebe a opção delecionada e executa ela.
				if (!Menu::getComando()) {
					menuPrincipal.selecionar();

					verificaComando(relogioEnter);
					pressionado = true;
				}

			}

			// se passou do menu iniciar, em seguida é o menu pra escolher a fase
			else if (Menu::getPrincipal() && menuPrincipal.getEscolherFase()) {

				//delay de comando para evitar que a tecla seja pressionada mais de 1x
				verificaComando(relogioEnter);
				//pressionado = true;

				//verifica se ja escolheu a fase ou não, tendo em vista que somente o menu de fase altera se é um ou dois jogadores (marcado por uma flag)
				if (!Menu::getEscolherJogadores()) {

					//exibe na tela
					menuFase.executar(); 

					if (!Menu::getComando()) {
						//recebe a opção delecionada e executa ela.
						menuFase.selecionar();

						//delay de comando para evitar que a tecla seja pressionada mais de 1x
						verificaComando(relogioEnter);
						pressionado = true;
					}

				}
				//se passou do menu fase, em seguida é para escolher o numero de jogadores
				else if(menuPrincipal.getEscolherJogadores()){
					
					//delay de comando para evitar que a tecla seja pressionada mais de 1x
					verificaComando(relogioEnter);

					if (!Menu::getEscolherNome()) {
						//exibe na tela
						menuNumJogadores.executar();

						if (!Menu::getComando()) {
							//recebe a opção delecionada e executa ela.
							menuNumJogadores.selecionar();

							//delay de comando para evitar que a tecla seja pressionada mais de 1x
							verificaComando(relogioEnter);
							pressionado = true;
						}
					}
					else if (Menu::getEscolherNome()) {

					}


				}

			}

		}
		// mostra o ranking
		else if (menuPrincipal.getRank()) {

			menuRanking.executar();

			verificaComando(relogioEnter);

			if (!Menu::getComando()) {
				menuRanking.selecionar();

				verificaComando(relogioEnter);
				pressionado = true;
			}

			if(menuRanking.getVoltar())
			{
				menuPrincipal.setRank(false);
				menuPrincipal.setPrincipal(true);
				menuRanking.setVoltar(false);
			}


		}
		else if (fimDeJogo) {
			menuFimDeJogo.setDois(menuNumJogadores.getDoisJogadores());
			menuFimDeJogo.executar();

			verificaComando(relogioEnter);

			if (!Menu::getComando()) {
				menuFimDeJogo.selecionar();

				verificaComando(relogioEnter);
				pressionado = true;
			}

		}
		else {
			menuPause.executar();
			menuPause.selecionar();
		}

		
		menuPrincipal.getGgraf()->getWindow()->display();
	}
}

//movimenta a opção selecionada
void GerenciadorMenus::selecionadorOp() {
	int max;

	//verifica se é o menu principal ou o pause
	if (Menu::getPrincipal()) {

		if (!Menu::getEscolherFase()){

			max = menuPrincipal.getNumOp() - 1;
			movimentaOp(max);

			//percorre a lista dizendo qual é a opção selecionada.
			menuPrincipal.setSelecionado(max, op);
		}
		else {

			if (!Menu::getEscolherJogadores()) {

				max = menuFase.getNumOp() - 1;
				movimentaOp(max);

				menuFase.setSelecionado(max, op);
			}
			else {

				max = menuNumJogadores.getNumOp() - 1;
				movimentaOp(max);

				menuNumJogadores.setSelecionado(max, op);
			}
			
		}
		
	}
	else if (menuPrincipal.getRank()) {
		op = 0;
		max = menuRanking.getNumOp() - 1;

		movimentaOp(max);

		menuRanking.setSelecionado(max, op);
	}
	else if (fimDeJogo) {
		op = 0;
		max = menuFimDeJogo.getNumOp() - 1;

		movimentaOp(max);

		menuFimDeJogo.setSelecionado(max, op);
	}
	else {

		max = menuPause.getNumOp() - 1;
		movimentaOp(max);

		//percorre a lista dizendo qual é a opção selecionada.
		menuPause.setSelecionado(max, op);
	}

}

void GerenciadorMenus::movimentaOp(int max) {
	//movimenta para cima
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		op--;

		if (op < 0) {
			op = max;
		}
		comando = true;
	}

	//movimenta para baixo
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		op++;

		if (op > max) {
			op = 0;
		}
		comando = true;
	}
}


bool GerenciadorMenus::getFaseUm() {
	return menuFase.getFasePrimeira();
}

bool GerenciadorMenus::getFaseDois() {
	return menuFase.getFaseSegunda();
}


void GerenciadorMenus::atrasoComando(sf::Clock* relogio) {
	sf::Time tempo;
	tempo = relogio->getElapsedTime();

	if (tempo.asSeconds() >= 0.3f)
	{
		Menu::setComando(false);
	}

}

void GerenciadorMenus::verificaComando(sf::Clock* relogioEnter) {

	if (Menu::getComando() && pressionado) {
		relogioEnter->restart();
		pressionado = false;
	}
	atrasoComando(relogioEnter);
}

bool GerenciadorMenus::getJogadorUm() {
	return menuNumJogadores.getUmJogadores();
}

bool GerenciadorMenus::getJogadorDois() {
	return menuNumJogadores.getDoisJogadores();
}

void GerenciadorMenus::setFimDeJogo(bool fim){
	fimDeJogo = fim;
}

void GerenciadorMenus::setPontuacao1(int pont) {
	menuFimDeJogo.setPontos1(pont);
}

void Menus::GerenciadorMenus::setPontuacao2(int pont){
	menuFimDeJogo.setPontos2(pont);
}

void GerenciadorMenus::setGanhou(bool win) {
	menuFimDeJogo.setGanhou(win);
}

