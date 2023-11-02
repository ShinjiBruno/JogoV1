#pragma once
#include "Ente.h"
#include "SFML/Graphics.hpp"	

namespace Entidades {
	class Entidade : public Ente {
	protected:
		sf::Vector2f pos;	//posicao 
		float andar;		//veloc em x
		double grav;		//"gravidade"
		bool neutralizado;
		bool chao; //se true, ativa o pulo

	public:
		Entidade();
		~Entidade();

		void setChao(bool c) { chao = c; }
		virtual void executar() = 0;
	};
}