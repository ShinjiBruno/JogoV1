#pragma once
#include <SFML\Graphics.hpp>
#include <time.h>
#include <cmath>
#include <vector>

using std::vector;


class Animacao
{
private:
	sf::Vector2u cortaImg;
	sf::Vector2u frameAtual;

	sf::Clock clock;
	float deltaTempo;

	float tempoSoma;
	float tempoFrame;

	bool ultDir; //se true, direita. Se false, esquerda

	sf::IntRect molde;

public:
	Animacao(sf::Texture* texture, sf::Vector2u corte, float tF);
	~Animacao();

	sf::IntRect getMolde() { return molde; }
	bool getDir() { return ultDir; }

	sf::Texture* animacaoFundo(vector<sf::Texture*> vecTexture, int* posicao);
	void Transicao(sf::RenderWindow* window);
	void Atualiza(int gif, bool direc);
	sf::Clock getClock() { return clock; }

};
