#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window/Event.hpp"
#include <iostream>

using namespace std;

static const float ALT_MAX = 1500.0f;

namespace Gerenciadores
{
	// implementado Singleton
	class GerenciadorGrafico
	{
	private:
		static GerenciadorGrafico *gGrafInstancia;
		GerenciadorGrafico();
		~GerenciadorGrafico();

		// Prevent copying and assignment
		GerenciadorGrafico(const GerenciadorGrafico &) = delete;
		GerenciadorGrafico &operator=(const GerenciadorGrafico &) = delete;

		sf::RenderWindow *window;
		sf::Event *event;
		sf::View *view;

	public:
		static GerenciadorGrafico *getInstancia()
		{
			if (gGrafInstancia == nullptr)
			{
				cout << "instanciando gerenciador grafico" << endl;
				gGrafInstancia = new GerenciadorGrafico();
			}
			return gGrafInstancia;
		}

		// Add method to clean up the singleton
		static void destroyInstancia()
		{
			if (gGrafInstancia != nullptr)
			{
				delete gGrafInstancia;
				gGrafInstancia = nullptr;
			}
		}

		sf::RenderWindow *getWindow() { return window; }
		sf::Event *getEvent() { return event; }
		sf::View *getView() { return view; }
		void redimensiona();
		void desenhar(sf::RectangleShape rec) { window->draw(rec); }
		void desenharTexto(sf::Text text) { window->draw(text); }
	};
}