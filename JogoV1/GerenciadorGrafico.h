#pragma once
#include "SFML/Graphics.hpp"

namespace Gerenciadores {
	//implementado Singleton
	class GerenciadorGrafico {
	private:
		static GerenciadorGrafico* gGrafInstancia;
		GerenciadorGrafico();
		~GerenciadorGrafico();

		sf::RenderWindow* window;

	public:
		static GerenciadorGrafico* getInstancia() {
			if (gGrafInstancia == nullptr) {
				gGrafInstancia = new GerenciadorGrafico();
			}
			return gGrafInstancia;
			
		}

		sf::RenderWindow* getWindow() { return window; }

		void desenhar(sf::RectangleShape rec) { window->draw(rec); }

	};
}

