#include "GerenciadorColisoes.h"
#include <math.h>

using namespace Gerenciadores;

GerenciadorColisoes::GerenciadorColisoes() {
}

GerenciadorColisoes::~GerenciadorColisoes() {
}

/*******************INCLUSAO*********************/
void GerenciadorColisoes::incluirInimigos(Entidade* inim) {
	Inimigo* iniAux = new Inimigo();

	iniAux = dynamic_cast<Inimigo*>(inim);
	if (inim != NULL) {
		LIs.push_back(iniAux);
	}
	else { return; }
}

void GerenciadorColisoes::incluirJogadores(Entidade* jog) {
	Jogador* jogAux = new Jogador();
	
	jogAux = dynamic_cast<Jogador*>(jog);
	if (jogAux) { printf("O typecast foi bem-sucedido, e jog eh uma instancia de Jogador\n"); }
	else { printf("jog nao eh uma instancia de Jogador\n"); }

	if (jog != NULL) {
		LJs.push_back(jogAux);
	}
	else { return; }

}

void GerenciadorColisoes::incluirObstaculos(Obstaculo* obst) {
	if (obst != NULL) {
		LOs.push_back(obst);
	}
	else { return; }
}
/***********************************/

void GerenciadorColisoes::colisaoPersoObst() {
	list<Obstaculo*>::iterator itObst; //iterador obstaculo
	itObst = this->LOs.begin();

	for (itObst; itObst != this->LOs.end(); ++itObst) {
		Obstaculo* obstAux = *itObst;
		//tamanho do obstaculo
		float obst_size_x = obstAux->getFigura()->getSize().x; //largura do obst
		float obst_size_y = obstAux->getFigura()->getSize().y; //altura do obst
		//posicao do obstaculo
		sf::Vector2f obstPos = obstAux->getFigura()->getPosition();

		//COLISAO ENTRE OBSTACULO E INIMIGO
		for (int j = 0; j < this->LIs.size(); j++) {
			//posicao do inimigo
			sf::Vector2f inimPos = LIs[j]->getFigura()->getPosition();

			float inim_size_x = this->LIs[j]->getFigura()->getSize().x; //largura do inim
			float inim_size_y = this->LIs[j]->getFigura()->getSize().y; //altura do inim

			float delta_x = abs(obstPos.x - inimPos.x);
			float delta_y = abs(obstPos.y - inimPos.y);

			float move_x = abs((inim_size_x / 2) - abs((obst_size_x / 2) - delta_x));
			float move_y = abs((inim_size_y / 2) - abs((obst_size_y / 2) - delta_y));

			//colisao vertical
			if ((delta_y < (obst_size_y / 2) + (inim_size_y / 2)) && (delta_x < obst_size_x / 2)) {
				if (inimPos.y <= obstPos.y) {
					LIs[j]->setChao(true);  //pulo so eh ativado estando sobre uma plataforma
					this->LIs[j]->getFigura()->move(sf::Vector2f(0.0f, -move_y));
				}
				if (inimPos.y > obstPos.y) {
					this->LIs[j]->getFigura()->move(sf::Vector2f(0.0f, move_y));
				}
			}
			//colisao horizontal
			if ((delta_x < (obst_size_x / 2) + (inim_size_x / 2)) && (delta_x >= obst_size_x / 2)) {
				if (inimPos.x <= obstPos.y) {
					this->LIs[j]->getFigura()->move(sf::Vector2f(-move_x, 0.0f));
				}
				if (inimPos.x > obstPos.x) {
					this->LIs[j]->getFigura()->move(sf::Vector2f(move_x, 0.0f));
				}
			}

		}
		//COLISAO ENTRE OBSTACULO E JOGADOR
		for (int j = 0; j < this->LJs.size(); j++) {
			sf::Vector2f jogPos = this->LJs[j]->getFigura()->getPosition();

			float jog_size_x = this->LJs[j]->getFigura()->getSize().x; //largura do inim
			float jog_size_y = this->LJs[j]->getFigura()->getSize().y; //altura do inim

			float delta_x = abs(obstPos.x - jogPos.x);
			float delta_y = abs(obstPos.y - jogPos.y);

			float move_x = abs((jog_size_x/2)- abs((obst_size_x/2) - delta_x));
			float move_y = abs((jog_size_y / 2) - abs((obst_size_y / 2) - delta_y));
			//colisao vertical
			if ((delta_y < (obst_size_y / 2) + (jog_size_y / 2)) && (delta_x < obst_size_x / 2)) {
				if (jogPos.y <= obstPos.y) {
					LJs[j]->setChao(true);  //pulo so eh ativado estando sobre uma plataforma
					this->LJs[j]->getFigura()->move(sf::Vector2f(0.0f,  (- 1)*move_y));
				}
				if (jogPos.y > obstPos.y) {
					this->LJs[j]->getFigura()->move(sf::Vector2f(0.0f, move_y));
				}
			}
			//colisao horizontal
			if (((delta_x < (obst_size_x / 2) + (jog_size_x / 2)) && (delta_x >= obst_size_x / 2)) &&
				((delta_y < (obst_size_y / 2) + (jog_size_y / 2))))
			{
				if (jogPos.x <= obstPos.y) {
					this->LJs[j]->getFigura()->move(sf::Vector2f(-move_x, 0.0f));
				}
				if (jogPos.x > obstPos.x) {
					this->LJs[j]->getFigura()->move(sf::Vector2f(move_x, 0.0f));
				}
			}
		}
	}
}
