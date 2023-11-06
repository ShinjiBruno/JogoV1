#pragma once
#include "Obstaculo.h"
#include <map>
using namespace Entidades;
using namespace Obstaculos;

//chave para protoObst: 1=plataforma, 2=obstaculo danoso, 3=obstaculo que lanca projetil
namespace Gerenciadores {
	class GerenciadorPrototipo {
	private:
		std::map<int, Obstaculo*> protoObst;
	public:
		void registraPrototipoObst(const int& tipo, Obstaculo* proto) {
			protoObst[tipo] = proto;
		}

		Obstaculo* criaObstaculo(const int& tipo) {
			if (protoObst.find(tipo) != protoObst.end()) {
				return protoObst[tipo]->clone();
			}
			return nullptr;
		}
	};
}