#include "Array/Coda.h"

int main() {
    // Creazione di una coda vuota
    array::Coda<int> coda;
    std::cout << "Creazione di una coda vuota." << std::endl;

    // Inserimento di 10, 20, 30 nella coda
    std::cout << "Inserimento di 10, 20, 30 nella coda." << std::endl;
    coda.InCoda(10);
    coda.InCoda(20);
    coda.InCoda(30);

    // Stampa la coda
    coda.StampaLista();

    // Mostra l'elemento in testa alla coda
    std::cout << "L'elemento in testa alla coda è: " << coda.LeggiCoda() << std::endl;

    // Rimuovo l'elemento in testa alla coda
    std::cout << "Rimuovo l'elemento in testa alla coda." << std::endl;
    coda.FuoriCoda();

    // Mostra l'elemento in testa alla coda dopo la rimozione
    std::cout << "L'elemento in testa alla coda ora è: " << coda.LeggiCoda() << std::endl;

    // Inserimento di 40 nella coda
    std::cout << "Inserimento di 40 nella coda." << std::endl;
    coda.InCoda(40);

    // Stampa la coda dopo l'inserimento di 40
    std::cout << "Stato della coda dopo l'inserimento di 40:" << std::endl;
    coda.StampaLista();

    // Rimuovo tutti gli elementi dalla coda
    std::cout << "Rimuovo tutti gli elementi dalla coda." << std::endl;
    while (!coda.CodaVuota()) {
        std::cout << "Rimosso: " << coda.LeggiCoda() << std::endl;
        coda.FuoriCoda();
    }

    // Verifica se la coda è vuota
    if (coda.CodaVuota()) {
        std::cout << "La coda è ora vuota." << std::endl;
    }

    return 0;
}
