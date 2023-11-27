#include "Texto.h"

using namespace Gerenciadores;


Texto::Texto(string str, unsigned int tamanho, float posicao_x, float posicao_y, sf::Font* fonte) {

	txt.setFont(*fonte);
	txt.setString(str);
	txt.setCharacterSize(tamanho);
	txt.setPosition(sf::Vector2f(posicao_x, posicao_y));
	txt.setStyle(sf::Text::Bold);
	txt.setFillColor(sf::Color::White);
	txt.setOrigin(sf::Vector2f(txt.getLocalBounds().width / 2, txt.getLocalBounds().height/2));
	txt.setOutlineThickness(1.0f);
	txt.setOutlineColor(sf::Color::Black);
	txt.setScale(1, 1);

	selecionado= false;
}

Texto::Texto() {
	selecionado = false;
}

Texto::~Texto() {

}


void Texto::mudarTamanho(unsigned int tam){
	this->txt.setCharacterSize(tam);
}

void Texto::mudarPosicao(float x, float y){
	
	this->txt.setPosition(sf::Vector2f(x, y));
}

void Texto::mudaCor(string cor) {

	if (cor == "Yellow") {
		this->txt.setFillColor(sf::Color::Yellow);
	}
	else if (cor == "Blue") {
		this->txt.setFillColor(sf::Color::Blue);
	}
	else if (cor == "Magenta") {
		this->txt.setFillColor(sf::Color::Magenta);
	}
	else if (cor == "Red") {
		this->txt.setFillColor(sf::Color::Red);
	}
	else if (cor == "Green") {
		this->txt.setFillColor(sf::Color::Green);
	}
	else if (cor == "White") {
		this->txt.setFillColor(sf::Color::White);
	}
	else if (cor == "Black") {
		this->txt.setFillColor(sf::Color::Black);
	}
	else if (cor == "Transparent") {
		this->txt.setFillColor(sf::Color::Transparent);
	}
	else if (cor == "Cyan") {
		this->txt.setFillColor(sf::Color::Cyan);
	}

}


Text Texto::getTxt() {
	return Texto::txt;
}

void Texto::setSelecionado(bool estado) {
	this->selecionado = estado;
}

bool Texto::getSelecionado() {
	return this->selecionado;
}

void Texto::mudaPalavra(string palavra) {
	this->txt.setString(palavra);
}