#include <iostream>
#include "Jogo.h"

using namespace std;

int main() {
	Jogo jogo;
	/******TESTE-verificar o funcionamento da lista******
	Listas::Lista<int> listaEx;

	for (int i = 0; i < 10; i++) {
		int* item = new int(i);
		listaEx.pushElem(item);
	}
	listaEx.executaLista();
	/******************/
	
	return 0;
}
