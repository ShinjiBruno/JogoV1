#include "ListaEntidades.h"
using namespace Listas;

ListaEntidades::ListaEntidades() {}

ListaEntidades::~ListaEntidades() {}

void ListaEntidades::incluir(Entidade* ent) {
	this->listEnt.pushElem(ent);
}

void ListaEntidades::percorrer() {
	this->listEnt.executaLista();
}