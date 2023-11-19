#pragma once
#include "Obstaculo.h"
#include "Inimigo.h"
#include <map>
using namespace Entidades;
using namespace Obstaculos;

//chave para protoObst: 1=plataforma, 2=obstaculo danoso, 3=obstaculo que lanca projetil
namespace Gerenciadores {
	class GerenciadorPrototipo {
	private:
		std::map<int, Obstaculo*> protoObst;
		std::map<int, Inimigo*> protoInim;
		int qnt_obst; //quantidade de prototipo obstaculo criado -> usar para deletar os objetos

	public:
		GerenciadorPrototipo() : qnt_obst(0) {}
		~GerenciadorPrototipo() {
			qnt_obst = 0;
		}
		/*******Prototipo de obstaculos******/
		void registraPrototipoObst(const int& tipo, Obstaculo* proto) {
			protoObst[tipo] = proto;
		}

		Obstaculo* criaObstaculo(const int& tipo) {
			if (protoObst.find(tipo) != protoObst.end()) {
				return protoObst[tipo]->clone();
				qnt_obst += 1;
			}
			return nullptr;
		}
		const int getQntObst() const { return qnt_obst; }

		/*******Prototipo de inimigos******/
		void registraPrototipoInim(const int& tipo, Inimigo* proto) {
			protoInim[tipo] = proto;
		}

		Inimigo* criaInimigo(const int& tipo) {
			if (protoInim.find(tipo) != protoInim.end()) {
				return protoInim[tipo]->clone();
				qnt_obst += 1;
			}
			return nullptr;
		}
	};
}