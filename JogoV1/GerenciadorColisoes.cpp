#include "GerenciadorColisoes.h"
#include <math.h>

using namespace Gerenciadores;

GerenciadorColisoes::GerenciadorColisoes() {
}

GerenciadorColisoes::~GerenciadorColisoes() {
}

/*******************INCLUSAO*********************/
void GerenciadorColisoes::incluirInimigos(Entidade* inim) {
	Inimigo* iniAux;
	iniAux = static_cast<Inimigo*>(inim);
	if (inim != NULL) {
		LIs.push_back(iniAux);
	}
	else { return; }
}

void GerenciadorColisoes::incluirJogadores(Entidade* jog) {
	Jogador* jogAux;
	jogAux =  static_cast<Jogador*>(jog);
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

void GerenciadorColisoes::incluirProjeteis(std::vector<Projetil*>& proj) {
	for (Projetil* p : proj) {
		LPs.push_back(p);
	}
	/*if (proj != NULL) {
		LPs.push_back(proj);
	}
	else { return; }*/
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

			float move_x = abs((inim_size_x / 2) - abs((jog_size_x / 2) - delta_x));
			float move_y = abs((inim_size_y / 2) - abs((jog_size_y / 2) - delta_y));

			//VERTICAL
			if (((delta_y < (inim_size_y / 2) + (jog_size_y / 2)) && (delta_y >= jog_size_y / 2)) &&
			(delta_x < (jog_size_x / 2) + (inim_size_x / 2))) {
				LJs[i]->setChao(false);
				if (jogPos.y <= inimPos.y) {
					this->LJs[i]->getFigura()->move(sf::Vector2f(0.0f, -move_y));//-10.0f));
					this->LJs[i]->setTempoLoop(LJs[i]->getTempoLoop()); //faz o jogador saltar 
					LIs[j]->tomaDano(LJs[i]->getDanar());
					/*if (jogPos.x <= inimPos.x) {
						this->LJs[i]->getFigura()->move(sf::Vector2f(0.0f, -move_y));//-10.0f));
						this->LJs[i]->setTempoLoop(LJs[i]->getTempoLoop()); //faz o jogador saltar 
						LIs[j]->tomaDano(LJs[i]->getDanar());
					}
					else {
						this->LJs[i]->getFigura()->move(sf::Vector2f(70.0f, 0));//-10.0f));
					}*/
				}
				if (jogPos.y > inimPos.y) {
					LJs[i]->tomaDano(LIs[j]->getDanar());
					if (jogPos.x <= inimPos.x) {
						this->LJs[i]->getFigura()->move(sf::Vector2f(-70.0f, -5.0f));//-10.0f));
					}
					else {
						this->LJs[i]->getFigura()->move(sf::Vector2f(70.0f, -5.0f));//-10.0f));
					}
				}
			}
			//colisao horizontal
			else if ((delta_x < (jog_size_x / 2) + (inim_size_x / 2)) && (delta_x >= jog_size_x / 2) &&
				((delta_y < (jog_size_y / 2) + (inim_size_y / 2)))) {

				printf("Inimigo %d: (%f; %f)\n", j, inimPos.x, inimPos.y);
				LJs[i]->tomaDano(LIs[j]->getDanar());
				LJs[i]->setChao(false);
				if (inimPos.x <= jogPos.x) {
					this->LJs[i]->getFigura()->move(sf::Vector2f(50.0f, -5.0f));
				}
				if (inimPos.x > jogPos.x) {
					this->LJs[i]->getFigura()->move(sf::Vector2f(-50.0f, -5.0f));
				}
			}

		}
	}
}

void GerenciadorColisoes::colisaoPersoObst() {
	list<Obstaculo*>::iterator itObst; //iterador obstaculo
	itObst = this->LOs.begin();
	int i = 0;
	for (itObst; itObst != this->LOs.end(); ++itObst) {
		Obstaculo* obstAux = *itObst;
		//printf("Obstaculo %d: (%f, %f) \n", i, obstAux->getFigura()->getPosition().x, obstAux->getFigura()->getPosition().y);
		i += 1;
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

			float move_x;
			float move_y;

			move_x = abs((obst_size_x / 2) - abs((inimPos.x - inim_size_x / 2) - obstPos.x));
			move_y = abs((obst_size_y / 2) - abs((inimPos.y - inim_size_y / 2) - obstPos.y));

			//colisao vertical
			if (((delta_y < (obst_size_y / 2) + (inim_size_y / 2)) && (delta_y >= obst_size_y / 2)) &&
				(delta_x < (inim_size_x / 2) + (obst_size_x / 2))) {
				if (inimPos.y <= obstPos.y) {
					move_y = abs((obst_size_y / 2) - abs((inimPos.y + inim_size_y / 2) - obstPos.y));

					LIs[j]->setChao(true);  //pulo so eh ativado estando sobre uma plataforma
					this->LIs[j]->getFigura()->move(sf::Vector2f(0.0f, -move_y));
				}
				if (inimPos.y > obstPos.y) {
					this->LIs[j]->getFigura()->move(sf::Vector2f(0.0f, move_y));
				}
			}
			//colisao horizontal
			else if (((delta_x < (obst_size_x / 2) + (inim_size_x / 2)) && //(delta_x >= obst_size_x / 2)) &&
			((delta_y < (obst_size_y / 2) + (inim_size_y / 2)))))
			{
				if (inimPos.x <= obstPos.x) {
					move_x = abs((obst_size_x / 2) - abs((inimPos.x + inim_size_x / 2) - obstPos.x));
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

			//float move_x = abs((jog_size_x/2)- abs((obst_size_x/2) - delta_x));
			//float move_y = abs((jog_size_y / 2) - abs((obst_size_y / 2) - delta_y));
			float move_x;
			float move_y;

			move_x = abs((obst_size_x / 2) - abs((jogPos.x - jog_size_x / 2) - obstPos.x));
			move_y = abs((obst_size_y / 2) - abs((jogPos.y - jog_size_y / 2) - obstPos.y));
			
			//colisao vertical
			if (((delta_y < (obst_size_y / 2) + (jog_size_y / 2)) && (delta_y >= obst_size_y / 2)) &&
				(delta_x < (jog_size_x / 2) + (obst_size_x / 2))) {
				if (jogPos.y <= obstPos.y) {
					move_y = abs((obst_size_y / 2) - abs((jogPos.y + jog_size_y / 2) - obstPos.y));
					LJs[j]->setAfetado(true);
					LJs[j]->setChao(true);  //pulo so eh ativado estando sobre uma plataforma
					int id = obstAux->getId();
					LJs[j]->efeitoNegativo(id, obstAux);
					printf("Obstaculo id: %d\n", id);

					if (id == 5) {
						LJs[j]->estadoPadrao();
					}
					this->LJs[j]->getFigura()->move(sf::Vector2f(0.0f, (-1) * move_y));
				}
				if (jogPos.y > obstPos.y) {
					this->LJs[j]->getFigura()->move(sf::Vector2f(0.0f, move_y));
					LJs[j]->setPulo(false);
				}
			}
			//colisao horizontal
			else if (((delta_x < (obst_size_x / 2) + (jog_size_x / 2)) && //(delta_x >= obst_size_x / 2)) &&
			((delta_y < (obst_size_y / 2) + (jog_size_y / 2)))))
			{
				printf("Colisao com a plataforma: (%f, %f)\n", move_x, move_y);
				if (jogPos.x <= obstPos.x) {
					move_x = abs((obst_size_x / 2) - abs((jogPos.x + jog_size_x / 2) - obstPos.x));

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
	if (LJs.size() == 1) {
		for (int i = 0; i < LIs.size(); i++) {
			sf::Vector2f posVisao = LIs[i]->getVisao().getPosition();
			float raio = LIs[i]->getVisao().getRadius();

			for (int j = 0; j < LJs.size(); j++) {
				sf::Vector2f posJog = LJs[j]->getFigura()->getPosition();
				float dist_x = abs(posVisao.x - posJog.x);
				float dist_y = abs(posVisao.y - posJog.y);

				float dist = sqrt(dist_x * dist_x + dist_y * dist_y);

				if (dist <= raio) {
					if (posVisao.x - 10.0f >= posJog.x) { //5.0f eh a tolerancia da visao para nao bugar qnd o jogar estiver exatamnete acima de um inim
						LIs[i]->setDetectaJog(true, 0);
					}
					else if (posVisao.x + 10.0f < posJog.x) {
						LIs[i]->setDetectaJog(true, 1);
					}
				}
				else {
					LIs[i]->setDetectaJog(false, -1);
				}

			}
		}
	}
	else {
		for (int i = 0; i < LIs.size(); i++) {
			sf::Vector2f posVisao = LIs[i]->getVisao().getPosition();
			float raio = LIs[i]->getVisao().getRadius();

			sf::Vector2f posJog1 = LJs[0]->getFigura()->getPosition();
			sf::Vector2f posJog2 = LJs[1]->getFigura()->getPosition();
			float dist_x1 = abs(posVisao.x - posJog1.x);
			float dist_y1 = abs(posVisao.y - posJog1.y);
			float dist_x2 = abs(posVisao.x - posJog2.x);
			float dist_y2 = abs(posVisao.y - posJog2.y);

			float dist1 = sqrt(dist_x1 * dist_x1 + dist_y1 * dist_y1);
			float dist2 = sqrt(dist_x2 * dist_x2 + dist_y2 * dist_y2);

			if (dist1 <= raio) {
				if (dist1 < dist2) {
					if (posVisao.x - 5.0f >= posJog1.x) { //5.0f eh a tolerancia da visao para nao bugar qnd o jogar estiver exatamnete acima de um inim
						LIs[i]->setDetectaJog(true, 0);
					}
					else if (posVisao.x + 5.0f < posJog1.x) {
						LIs[i]->setDetectaJog(true, 1);
					}
				}
				else {
					if (posVisao.x - 5.0f >= posJog2.x) { //5.0f eh a tolerancia da visao para nao bugar qnd o jogar estiver exatamnete acima de um inim
						LIs[i]->setDetectaJog(true, 0);
					}
					else if (posVisao.x + 5.0f < posJog2.x) {
						LIs[i]->setDetectaJog(true, 1);
					}
				}
			}
			else if (dist2 <= raio) {
				if (posVisao.x - 5.0f >= posJog2.x) { //5.0f eh a tolerancia da visao para nao bugar qnd o jogar estiver exatamnete acima de um inim
					LIs[i]->setDetectaJog(true, 0);
				}
				else if (posVisao.x + 5.0f < posJog2.x) {
					LIs[i]->setDetectaJog(true, 1);
				}
			}
			else {
				LIs[i]->setDetectaJog(false, -1);
			}

			
		}
	
	}
}

void GerenciadorColisoes::colisaoProjetil() {
	std::vector<Projetil*>::iterator itProj = LPs.begin();

	for (itProj; itProj != LPs.end(); ++itProj) {
		Projetil* projAux = *itProj;
		float proj_size_x = projAux->getFigura()->getSize().x;
		float proj_size_y = projAux->getFigura()->getSize().y;
		sf::Vector2f projPos = projAux->getFigura()->getPosition();

		std::list<Obstaculo*>::iterator it = LOs.begin();
		//COLISAO COM OBSTACULO
		while (it != LOs.end()) {
			Obstaculo* obstAux = *it;
			//printf("Obstaculo %d: (%f, %f) \n", i, obstAux->getFigura()->getPosition().x, obstAux->getFigura()->getPosition().y);
			//tamanho do obstaculo
			float obst_size_x = obstAux->getFigura()->getSize().x; //largura do obst
			float obst_size_y = obstAux->getFigura()->getSize().y; //altura do obst
			//posicao do obstaculo
			sf::Vector2f obstPos = obstAux->getFigura()->getPosition();

			float delta_x = abs(obstPos.x - projPos.x);
			float delta_y = abs(obstPos.y -	projPos.y);

			if (((delta_x < (obst_size_x / 2) + (proj_size_x / 2)) && //(delta_x >= obst_size_x / 2)) &&
				((delta_y < (obst_size_y / 2) + (proj_size_y / 2))))){
				projAux->Atingiu(true);
			}
			++it;
		}

		//COLISAO COM JOGADOR
		for (int j = 0; j < LJs.size(); j++) {
			float jog_size_x = LJs[j]->getFigura()->getSize().x; //largura do obst
			float jog_size_y = LJs[j]->getFigura()->getSize().y; //altura do obst
			//posicao do obstaculo
			sf::Vector2f jogPos = LJs[j]->getFigura()->getPosition();

			float delta_x = abs(jogPos.x - projPos.x);
			float delta_y = abs(jogPos.y - projPos.y);

			if (((delta_y < (proj_size_y / 2) + (jog_size_y / 2)) && (delta_y >= proj_size_y / 2)) &&
			(delta_x < (jog_size_x / 2) + (proj_size_x / 2))) {
				LJs[j]->tomaDano(projAux->getDanar());
				projAux->Atingiu(true);
				if (jogPos.x <= projPos.x) {
					LJs[j]->getFigura()->move(sf::Vector2f(-10.0f, 1.0f));
				}
				if (jogPos.x > projPos.x) {
					LJs[j]->getFigura()->move(sf::Vector2f(10.0f, 1.0f));
				}
			}

			//COLISAO HORIZONTAL
			else if (((delta_x < (proj_size_x / 2) + (jog_size_x / 2)) &&
			((delta_y < (proj_size_y / 2) + (jog_size_y / 2))))) {
				LJs[j]->tomaDano(projAux->getDanar());
				projAux->Atingiu(true);
				if (jogPos.x <= projPos.x) {
					LJs[j]->getFigura()->move(sf::Vector2f(-10.0f, 1.0f));
				}
				if (jogPos.x > projPos.x) {
					LJs[j]->getFigura()->move(sf::Vector2f(10.0f, 1.0f));
				}
			}
		}
	}
}