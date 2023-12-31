#pragma once
#include <iostream>
using std::cout;

namespace Listas {
    template <class T>
    class Lista {
    private:
        class Elemento {
        private:
            T pInfo;
            

        public:
            Elemento() : pInfo(NULL), elemProx(NULL) {}
            ~Elemento() { pInfo = NULL; elemProx = NULL; }

            void setInfo(T info) { pInfo = info; }

            T getInfo() { return pInfo; }

            void executa() { pInfo->executar(); }

            Elemento* elemProx;
        };

        Elemento* pPrim;
        Elemento* pAtual;

        int tam;

    public:
        Lista() : pPrim(NULL), pAtual(NULL), tam(0) {}
        ~Lista() {
            Elemento* temp = pPrim;
            while (temp != nullptr) {
                Elemento* next = temp->elemProx;
                delete temp->getInfo();
                delete temp;
                temp = next;
            }
            tam = 0;
        }

        void pushElem(T item) {
            Elemento* temp = new Elemento;
            temp->setInfo(item);

            if (pPrim == NULL && pAtual == NULL) {
                pPrim = temp;
                pAtual = temp;
            }
            else {
                pAtual->elemProx = temp;
                pAtual = temp;
                temp->elemProx = NULL;
            }
            tam += 1;
        }

        void executaLista() {
            Elemento* temp = pPrim;
            Elemento* tempP = temp->elemProx;
            while (temp != NULL) {
                /*if (tempP->getInfo()->getNeutralizado()) {
                    deletaElemento(temp, temp->elemProx);
                }*/
                temp->executa();
                temp = temp->elemProx;
            }
        }

        /*void deletaElemento(Elemento* elem, Elemento* eleP) {
            if (elem == pPrim && elem->getInfo()->getNeutralizado()) {
                pPrim = elem->elemProx;
                elem->elemProx = NULL;
                delete elem;
            }
            else {
                elem->elemProx = eleP->elemProx;
                eleP->elemProx = NULL;
                delete eleP;
            }
        }*/

        const int getSize() const { return tam; }
        //Elemento* getPPrim() { return pPrim; }
    };
}
