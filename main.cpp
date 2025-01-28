#include "Array/Pila.h"

int main() {
    array::Pila<int> pila;

    std::cout << "Creazione di una pila vuota." << std::endl;

    std::cout << "Inserimento di 10, 20, 30 nella pila." << std::endl;
    pila.InPila(10);
    pila.InPila(20);
    pila.InPila(30);

    pila.StampaLista();

    std::cout << "L'elemento in cima alla pila è: " << pila.LeggiPila() << std::endl;

    std::cout << "Rimuovo l'elemento in cima alla pila." << std::endl;
    pila.FuoriPila();

    std::cout << "L'elemento in cima alla pila ora è: " << pila.LeggiPila() << std::endl;

    std::cout << "Rimuovo tutti gli elementi dalla pila." << std::endl;
    while (!pila.PilaVuota()) {
        std::cout << "Rimosso: " << pila.LeggiPila() << std::endl;
        pila.FuoriPila();
    }

    if (pila.PilaVuota()) {
        std::cout << "La pila è ora vuota." << std::endl;
    }

    return 0;
}
