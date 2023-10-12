#pragma once
#include "Ente.h"
#include "SFML/Graphics.hpp"	

namespace Entidades {
	class Entidade : public Ente {
	protected:
		sf::Vector2f pos;	//posicao 
		float velocX;		//incrementar esse valor
		float velocY;
		double grav;		//"gravidade"
		bool neutralizado;

	public:
		Entidade();
		~Entidade();

		virtual void executar() = 0;
	};
}