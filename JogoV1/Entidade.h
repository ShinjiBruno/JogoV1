#pragma once
#include "Ente.h"
#include "SFML/Graphics.hpp"	

namespace Entidades {
	class Entidade : public Ente {
	protected:
		sf::Vector2f pos;	//posicao 
		float andar;		//veloc em x
		float danar;
		double grav;		//"gravidade"
		bool neutralizado;
		bool chao; //se true, ativa o pulo

	public:
		Entidade();
		~Entidade();

		void setDanar(float d) { danar = d; }
		float getDanar() { return danar; }

		bool getNeutralizado() { return neutralizado; }
		void setChao(bool c) { chao = c; }
		void setAndar(float a) { andar = a; }

		float getAndar() { return andar; }
		virtual void executar() = 0;
	};
}