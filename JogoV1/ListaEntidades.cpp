#include "ListaEntidades.h"
using namespace Listas;

ListaEntidades::ListaEntidades() {}

ListaEntidades::~ListaEntidades() {}

void ListaEntidades::incluir(Entidade* ent) {
	listEnt.pushElem(ent);
}

void ListaEntidades::percorrer() {
	listEnt.executaLista();
}