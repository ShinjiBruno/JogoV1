#pragma once
#include "Lista.h"
#include "Entidade.h"
using namespace Entidades;

namespace Listas {
	class ListaEntidades {

	private:
		Lista<Entidade*> listEnt;

	public:
		ListaEntidades();
		~ListaEntidades();

		void incluir(Entidade* ent);
		void percorrer();

		const int getSize() const { return listEnt.getSize(); }
	};

}