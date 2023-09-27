#include <iostream>
#include "Lista.h"

using namespace std;

int main() {
	Listas::Lista<int> listaEx;

	for (int i = 0; i < 10; i++) {
		int* item = new int(i);
		listaEx.pushElem(item);
	}
	listaEx.executaLista();
	

	return 0;
}
