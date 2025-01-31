#include <iostream>
#include "Array/Pila.h"
using namespace array;

/*
*   Data una pila di interi, implementare in C++ una funzione che restituisca una nuova pila i cui elementi corrispondano a quelli presenti nella pila  data e siano ordinati dall'alto (top dello stack) al basso.
*   Prevedere una funzione nel main che contenga una procedura di inserimento automatico e succesivamente il test della funzione implementata.
*/

Pila<int> order_top_to_bottom(Pila<int>& input) {
    Pila<int> output;

    // Inserimento dei nodi nella pila di output
    while(!input.PilaVuota()) {
        output.InPila(input.LeggiPila());
        input.FuoriPila();
    }

    return output;
}

int main() {
    // Creazione della pila di esempio
    Pila<int> pila;
    pila.InPila(10);
    pila.InPila(20);
    pila.InPila(30);
    pila.InPila(40);

    std::cout << "Pila originale:" << std::endl;
    pila.StampaLista();  // stampa la pila originale

    // Ordina la pila dal top al bottom
    Pila<int> pilaOrdinata = order_top_to_bottom(pila);

    std::cout << "\nPila ordinata (dall'alto verso il basso):" << std::endl;
    pilaOrdinata.StampaLista();  // stampa la pila ordinata

    return 0;
}
