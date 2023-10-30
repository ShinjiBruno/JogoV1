#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window/Event.hpp"

namespace Gerenciadores {
	//implementado Singleton
	class GerenciadorGrafico {
	private:
		static GerenciadorGrafico* gGrafInstancia;
		GerenciadorGrafico();
		~GerenciadorGrafico();

		sf::RenderWindow* window;
		sf::Event* event;

	public:
		static GerenciadorGrafico* getInstancia() {
			if (gGrafInstancia == nullptr) {
				gGrafInstancia = new GerenciadorGrafico();
			}
			return gGrafInstancia;
			
		}

		sf::RenderWindow* getWindow() { return window; }
		sf::Event* getEvent() { return event; }
		void desenhar(sf::RectangleShape rec) { window->draw(rec); }

	};
}

