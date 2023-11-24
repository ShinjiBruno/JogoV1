#pragma once

#include "SFML/Graphics/Text.hpp"
#include <string>

using namespace sf;
using namespace std;

namespace Gerenciadores
{
	class Texto
	{
	private:
		Text txt;
		bool selecionado;
	public:
		Texto(string str, unsigned int tamanho, float posicao_x, float posicao_y, sf::Font* fonte);
		Texto();
		~Texto();


		void mudarPosicao(float x, float y);
		void mudarTamanho(unsigned int tam);
		void mudaCor(string cor);
		Text getTxt();

		void setSelecionado(bool estado);
		bool getSelecionado();
	};
}