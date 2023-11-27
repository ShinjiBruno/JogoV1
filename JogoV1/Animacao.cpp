#include "Animacao.h"

Animacao::Animacao(sf::Texture* texture, sf::Vector2u corte, float tF)
{
	ultDir = false;
	this->cortaImg = corte;
	this->tempoFrame = tF;

	clock.restart();
	deltaTempo = 0.0f;

	tempoSoma = 0.0f;
	frameAtual.x = 0;
	srand(time(NULL));

	if (rand() % 2)
		molde.width = texture->getSize().x / float(corte.x);
	else
		molde.width = (- 1)*(texture->getSize().x / float(corte.x));

	molde.height = texture->getSize().y / float(corte.y);

}

Animacao::Animacao() {
	ultDir = false;
	clock.restart();
	deltaTempo = 0.0f;
	this->cortaImg = sf::Vector2u(1,1);
	this->tempoFrame = 3.0f;

	tempoSoma = 0.0f;
	frameAtual.x = 0;
	srand(time(NULL));
}

Animacao::~Animacao() {
}

void Animacao::Atualiza(int gif, bool direc)
{

	deltaTempo = clock.getElapsedTime().asMicroseconds() / 10000.0f;

	frameAtual.y = gif;
	tempoSoma += deltaTempo;

	if (tempoSoma >= tempoFrame) {
		tempoSoma = 0;
		frameAtual.x ++; //avanca um frame

		//reinicia o frame do gif escolhido
		if (frameAtual.x >= cortaImg.x) {
			frameAtual.x = 0;
		}
	}

	molde.top = frameAtual.y * molde.height;

	/***********************************/
	if (direc && ultDir) {
		molde.left = frameAtual.x * (molde.width);

		ultDir = true;

		if (molde.width > 0 && molde.left < 0) {
			molde.left = frameAtual.x * (molde.width);
			molde.width = abs(molde.width);
			ultDir = true;
		}
		else if (molde.width < 0 && molde.left < 0) {
			molde.left = (frameAtual.x - cortaImg.x) * (molde.width);
			molde.width = -abs(molde.width);
			ultDir = true;
		}
		molde.width = abs(molde.width);

	}

	else if (direc) {
		molde.left = frameAtual.x * (molde.width);

		ultDir = true;

		if (molde.width > 0 && molde.left < 0) {
			molde.left = frameAtual.x * (molde.width);
			molde.width = abs(molde.width);
			ultDir = true;
		}
		else if (molde.width < 0 && molde.left < 0) {
			molde.left = (frameAtual.x - cortaImg.x) * (molde.width);
			molde.width = -abs(molde.width);
			ultDir = true;
		}
		molde.width = abs(molde.width);

	}

	else if (ultDir) {
		molde.left = frameAtual.x * (molde.width);

		ultDir = false;

		if (molde.width > 0 && molde.left < 0) {
			molde.left = frameAtual.x * (molde.width);
			molde.width = abs(molde.width);
			ultDir = false;
		}
		else if (molde.width < 0 && molde.left < 0) {
			molde.left = (frameAtual.x - cortaImg.x) * (molde.width);
			molde.width = -abs(molde.width);
			ultDir = false;
		}
		molde.width = abs(molde.width);
	}

	else {
		molde.left = (frameAtual.x - cortaImg.x) * (molde.width);

		ultDir = false;

		if (molde.width > 0 && molde.left < 0) {
			molde.left = frameAtual.x * (molde.width);
			molde.width = abs(molde.width);
			ultDir = false;
		}
		else if (molde.width < 0 && molde.left < 0) {
			molde.left = (frameAtual.x - cortaImg.x) * (molde.width);
			molde.width = -abs(molde.width);
			ultDir = false;
		}
		molde.width = -abs(molde.width);
	}
	/***********************************/


	clock.restart();
}

sf::Texture* Animacao::animacaoFundo(vector<sf::Texture*> vecTexture, int* posicao) {

	deltaTempo = clock.getElapsedTime().asMilliseconds() / 10000.0f;

	tempoSoma += deltaTempo;

	if (tempoSoma >= tempoFrame) {
		if (*posicao + 1 >= (int)vecTexture.size()) {
			*posicao = 0;
		}
		else {
			*posicao += 1;;
		}
		tempoSoma = 0;
	}
	clock.restart();

	return vecTexture[*posicao];
}

void Animacao::Transicao(sf::RenderWindow* window) {

}
