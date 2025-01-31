#include <iostream>
#include "Array/Lista.h"
using namespace array;

/*
* Data una lista di elementi interi, implementare in C++ le seguenti funzioni:
*   - int freq(Lista<int> l, int k): restituisce il numero di occorrenze di multipli di k
*   - void hist(Lista<int>& l): stampa la frequenza di ogni elemento nella lista L;
*   - void remp(Lista<int>& l): rimuove dalla lista tutti gli elementi seguiti da un numero dispari
*/

int freq(const Lista<int>& l, int k) {
    int count = 0;
    
    for(int i = 1; i <= l.leggiSize(); i++)
        if(l.LeggiLista(i) % k == 0) count++;

    return count;
}

bool ricerca(const Lista<int>& l, int k) {
    bool trovato = false;

    for(int i = 1; i <= l.leggiSize() &&!trovato; i++)
        if(l.LeggiLista(i) == k) trovato = true;

    return trovato;
}

int count(const Lista<int>& l, int val) {
    int count = 0;

    for(int i = 1; i <= l.leggiSize(); i++) {
        if(l.LeggiLista(i) == val) count++;
    }

    return count;
}

void hist(const Lista<int>& l) {
    Lista<int> scritti;

    for(int i = 1; i <= l.leggiSize(); i++) {
        int val = l.LeggiLista(i);
        if(!ricerca(scritti, val)) {
            std::cout << val << ": " << count(l, val) << std::endl;
            scritti.InsLista(val, scritti.leggiSize() + 1);
        }
    }
}

void remp(Lista<int>& l) {
    int i = 0;
    while(i < l.leggiSize()) {
        if(l.LeggiLista(i + 1) % 2 != 0) 
            l.CancLista(i + 1);
        else i++;
    }
}

int main() {
    Lista<int> lista;

    // Inserimento di elementi nella lista
    lista.InsLista(4, 1);
    lista.InsLista(7, 2);
    lista.InsLista(2, 3);
    lista.InsLista(4, 4);
    lista.InsLista(3, 5);
    lista.InsLista(6, 6);
    lista.InsLista(4, 7);

    std::cout << "Lista iniziale: ";
    lista.StampaLista();

    // Test freq
    int k = 2;
    std::cout << "Numero di multipli di " << k << ": " << freq(lista, k) << std::endl;

    // Test hist
    std::cout << "Frequenza degli elementi:" << std::endl;
    hist(lista);

    // Test remp
    remp(lista);
    std::cout << "Lista dopo remp: ";
    lista.StampaLista();

    return 0;
}