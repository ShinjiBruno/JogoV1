#include "BackGround.h"

using namespace Gerenciadores;

BackGround::BackGround(int f): fundoJogo(f) {
	gerGraf = GerenciadorGrafico::getInstancia();
	sf::Texture* texture = new sf::Texture();
	animFundo = new Animacao(texture, sf::Vector2u(1,1), 0.005f);

	posVec = 0;

	sf::RectangleShape* fundo = new sf::RectangleShape();
	fundo->setSize(sf::Vector2f(2000.0f, 2000.0f));
	fundo->setOrigin(sf::Vector2f(fundo->getSize().x / 2, fundo->getSize().y / 2));
	fundo->setPosition(0.0f, 0.0f);
	fundo->setTexture(texture);


	for (int i = 1; i < 8; i++) {

		vecRec.push_back(fundo);

		fundo = new sf::RectangleShape();
		fundo->setSize(sf::Vector2f(2000.0f, 2000.f));
		fundo->setOrigin(sf::Vector2f(fundo->getSize().x / 2, fundo->getSize().y / 2));
		fundo->setTexture(texture);
		sf::Vector2f auxVec = vecRec[i - 1]->getPosition();

		fundo->setPosition(sf::Vector2f(auxVec.x + fundo->getSize().x, auxVec.y));


	}

	setUpFundo();
}

void BackGround::setUpFundo() {
	if (fundoJogo == 0) {
		std::string nomeImg = "frame_00_delay-0.08s.jpg";
		for (int i = 0; i < FRAMES_MENU; i++) {
			sf::Texture* texGif = new sf::Texture();
			if (texGif->loadFromFile(nomeImg)) {
				vecTex.push_back(texGif);
			}

			if (nomeImg[7] == '9') {
				nomeImg[6] += 1;
				nomeImg[7] = '0';
			}
			else {
				nomeImg[7] += 1;
			}
		}
	}

	else if (fundoJogo == 1) {
		std::string nomeImg = "frame_00_delay-0.06s.gif";
		for (int i = 0; i < FRAMES_FASE1; i++) {
			sf::Texture* texGif = new sf::Texture();
			if (texGif->loadFromFile(nomeImg)) {
				vecTex.push_back(texGif);
			}

			if (nomeImg[7] == '9') {
				nomeImg[6] += 1;
				nomeImg[7] = '0';
			}
			else {
				nomeImg[7] += 1;
			}
		}

	}
	
	else if (fundoJogo == 2) {
		std::string nomeImg = "frame_00_delay-0.06s.jpg";
		for (int i = 0; i < FRAMES_FASE2; i++) {
			sf::Texture* texGif = new sf::Texture();
			if (texGif->loadFromFile(nomeImg)) {
				vecTex.push_back(texGif);
			}

			if (nomeImg[7] == '9') {
				nomeImg[6] += 1;
				nomeImg[7] = '0';
			}
			else {
				nomeImg[7] += 1;
			}
		}
	}
}

void BackGround::fundoFase() {

	if (fundoJogo != 0) {

		sf::Texture* texAux = animFundo->animacaoFundo(vecTex, &posVec);

		fundoRect.left = texAux->getSize().x;
		fundoRect.top = 0;
		fundoRect.width = texAux->getSize().x;
		fundoRect.height = texAux->getSize().y;


		for (int i = 0; i < vecRec.size(); i++) {
			fundoRect.width *= -1; //inverte a texture
			if (fundoRect.width > 0) {
				fundoRect.left = 0;
			}
			else {
				fundoRect.left = texAux->getSize().x;
			}
			vecRec[i]->setTexture(texAux);
			vecRec[i]->setTextureRect(fundoRect);
			gerGraf->desenhar(*vecRec[i]);
		}
	}
	else {
		sf::Texture* texAux = animFundo->animacaoFundo(vecTex, &posVec);

		fundoRect.left = texAux->getSize().x;
		fundoRect.top = 0;
		fundoRect.width = texAux->getSize().x;
		fundoRect.height = texAux->getSize().y;


		for (int i = 0; i < vecRec.size(); i++) {
			fundoRect.width *= -1; //inverte a texture
			if (fundoRect.width > 0) {
				fundoRect.left = 0;
			}
			else {
				fundoRect.left = texAux->getSize().x;
			}
			vecRec[i]->setTexture(texAux);
			vecRec[i]->setTextureRect(fundoRect);
			gerGraf->desenhar(*vecRec[i]);
		}
	}
}