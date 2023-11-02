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

	iniAux = static_cast<Inimigo*>(inim);
	if (inim != NULL) {
		LIs.push_back(iniAux);
	}
	else { return; }
}

void GerenciadorColisoes::incluirJogadores(Entidade* jog) {
	Jogador* jogAux = new Jogador();
	
	jogAux = static_cast<Jogador*>(jog);
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

/******************GERENCIAMENTO DE COLISAO*****************/

void GerenciadorColisoes::colisaoJogInim() {
	for (int i = 0; i < LJs.size(); i++) {
		float jog_size_x = this->LJs[i]->getFigura()->getSize().x; //largura do jog
		float jog_size_y = this->LJs[i]->getFigura()->getSize().y; //altura do jog
		sf::Vector2f jogPos = this->LJs[i]->getFigura()->getPosition();

		for (int j = 0; j < LIs.size(); j++) {
			float inim_size_x = this->LIs[j]->getFigura()->getSize().x; //largura do inim
			float inim_size_y = this->LIs[j]->getFigura()->getSize().y; //altura do inim
			sf::Vector2f inimPos = LIs[j]->getFigura()->getPosition();

			float delta_x = abs(jogPos.x - inimPos.x);
			float delta_y = abs(jogPos.y - inimPos.y);

			//colisao horizontal
			if ((delta_x < (jog_size_x / 2) + (inim_size_x / 2)) && (delta_x >= jog_size_x / 2) &&
				((delta_y < (jog_size_y / 2) + (inim_size_y / 2)))) {
				if (inimPos.x <= jogPos.x) {
					this->LJs[j]->getFigura()->move(sf::Vector2f(50.0f, -20.0f));
				}
				if (inimPos.x > jogPos.x) {
					this->LJs[j]->getFigura()->move(sf::Vector2f(-50.0f, -20.0f));
				}
			}

			else if (((delta_y < (inim_size_y / 2) + (jog_size_y / 2)) && (delta_y >= jog_size_y / 2)) &&
				(delta_x < (jog_size_x / 2) + (inim_size_x / 2))) {
				if (jogPos.y <= inimPos.y) {
					if (jogPos.x <= inimPos.x) {
						this->LJs[j]->getFigura()->move(sf::Vector2f(-70.0f, -10.0f));
					}
					else {
						this->LJs[j]->getFigura()->move(sf::Vector2f(70.0f, -10.0f));
					}
				}
				if (jogPos.y > inimPos.y) {
					if (jogPos.x <= inimPos.x) {
						this->LJs[j]->getFigura()->move(sf::Vector2f(-70.0f, -10.0f));
					}
					else {
						this->LJs[j]->getFigura()->move(sf::Vector2f(70.0f, -10.0f));
					}
				}
			}

		}
	}
}

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

			float jog_size_x = this->LJs[j]->getFigura()->getSize().x; //largura do jog
			float jog_size_y = this->LJs[j]->getFigura()->getSize().y; //altura do jog

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
			else { LJs[j]->setChao(false); }
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

void GerenciadorColisoes::colisaoVisaoInimigo() {
	for (int i = 0; i < LIs.size(); i++) {
		sf::Vector2f posVisao = LIs[i]->getVisao().getPosition();
		float raio = LIs[i]->getVisao().getRadius();

		for (int j = 0; j < LJs.size(); j++) {
			sf::Vector2f posJog = LJs[j]->getFigura()->getPosition();
			float dist_x = abs(posVisao.x - posJog.x);
			float dist_y = abs(posVisao.y - posJog.y);

			float dist = sqrt(dist_x*dist_x + dist_y*dist_y);

			if (dist <= raio) {
				if (posVisao.x - 1.0f >= posJog.x) { //5.0f eh a tolerancia da visao para nao bugar qnd o jogar estiver exatamnete acima de um inim
					LIs[i]->setDetectaJog(true, 0);
				}
				else if (posVisao.x + 1.0f < posJog.x) {
					LIs[i]->setDetectaJog(true, 1);
				}
			}
			else {
				LIs[i]->setDetectaJog(false, -1);
			}

		}
	}
}