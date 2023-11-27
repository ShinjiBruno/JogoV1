#pragma once
#include "Animacao.h"
#include "GerenciadorGrafico.h"
#include "SFML/Graphics.hpp"
#include <vector>
#include <string>
#define FRAMES_FASE1 39 //numero de frames
#define FRAMES_FASE2 31
#define FRAMES_MENU 31


using namespace Gerenciadores;

class BackGround {
private:
	sf::IntRect fundoRect;
	std::vector<sf::Texture*> vecTex;
	std::vector<sf::RectangleShape*> vecRec;
	GerenciadorGrafico* gerGraf;
	Animacao* animFundo;
	int posVec;			//posicao no vector
	int fundoJogo; //==0 menu; ==1 fase um; ==2 fase 2
public:
	BackGround(int f);

	void setUpFundo();
	
	void fundoFase();

};