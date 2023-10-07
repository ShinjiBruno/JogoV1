// Lista.h
#pragma once
#include <iostream>
using std::cout;

namespace Listas {
    template <class T>
    class Lista {
    private:
        class Elemento {
        private:
            T* pInfo;
            

        public:
            Elemento() : pInfo(NULL), elemProx(NULL) {}
            ~Elemento() { pInfo = NULL; elemProx = NULL; }

            void setInfo(T* info) { pInfo = info; }

            T* getInfo() { return pInfo; }

            void executa() { cout << *pInfo << " "; } //teste

            Elemento* elemProx;
        };

        Elemento* pPrim;
        Elemento* pAtual;

    public:
        Lista() : pPrim(NULL), pAtual(NULL) {}
        ~Lista() {
            Elemento* temp = pPrim;
            while (temp != nullptr) {
                Elemento* next = temp->elemProx;
                delete temp->getInfo();
                delete temp;
                temp = next;
            }
        }

        void pushElem(T* item) {
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
        }

        void executaLista() {
            Elemento* temp = pPrim;
            while (temp != NULL) {
                temp->executa();
                temp = temp->elemProx;
            }
        }

        //Elemento* getPPrim() { return pPrim; }
    };
}
