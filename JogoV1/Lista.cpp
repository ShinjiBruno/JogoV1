/*#include "Lista.h"
#include <stdio.h>


template<class T>
Listas::Lista<T>::Lista() {
	pPrim = NULL;
	pAtual = NULL;
}


template<class T>
Listas::Lista<T>::~Lista() {


	Lista<int>::Elemento* temp = pPrim;
	while (temp != nullptr) {
		Lista<int>::Elemento* next = temp->elemProx;
		delete temp->getInfo();
		delete temp;
		temp = next;
	}
}


template<class T>
Listas::Lista<T>::Elemento::Elemento() :
	pInfo(NULL)
{
	elemProx = NULL;

}

template<class T>
Listas::Lista<T>::Elemento::~Elemento()
{
	pInfo = NULL;
	elemProx = NULL;
}*/