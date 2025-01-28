#include <iostream>
#include "Tree/BTree.h" // Assicurati che il percorso al file sia corretto
using namespace tree;

int main() {

    // Creazione di un albero binario di interi
    BTree<int> albero;

    std::cout << "Inserimento nodi nell'albero...\n";
    albero.InserisciNodo(10);
    albero.InserisciNodo(5);
    albero.InserisciNodo(15);
    albero.InserisciNodo(3);
    albero.InserisciNodo(7);

    // Stampa dell'albero in ordine diverso
    std::cout << "Stampa Pre-Order:\n";
    albero.StampaAlberoPreOrder(albero.BinRadice(), 0);

    std::cout << "Stampa In-Order:\n";
    albero.StampaAlberoInOrder(albero.BinRadice(), 0);

    std::cout << "Stampa Post-Order:\n";
    albero.StampaAlberoPostOrder(albero.BinRadice(), 0);

    // Verifica se l'albero è vuoto
    if (albero.BinAlberoVuoto()) {
        std::cout << "L'albero è vuoto.\n";
    } else {
        std::cout << "L'albero non è vuoto.\n";
    }

    // Lettura del valore della radice
    auto radice = albero.BinRadice();
    if (radice) {
        std::cout << "Valore della radice: " << albero.LeggiNodo(radice) << "\n";
    }

    // Stampa del figlio sinistro e destro della radice
    auto sinistro = albero.FiglioSinistro(radice);
    if (sinistro) {
        std::cout << "Figlio sinistro della radice: " << albero.LeggiNodo(sinistro) << "\n";
    } else {
        std::cout << "La radice non ha un figlio sinistro.\n";
    }

    auto destro = albero.FiglioDestro(radice);
    if (destro) {
        std::cout << "Figlio destro della radice: " << albero.LeggiNodo(destro) << "\n";
    } else {
        std::cout << "La radice non ha un figlio destro.\n";
    }

    // Cancella sottoalbero a partire da un nodo
    std::cout << "Cancellazione del sottoalbero radicato nel figlio sinistro della radice...\n";
    if (sinistro) {
        albero.CancellaSottoAlbero(sinistro);
    }

    std::cout << "Stampa In-Order dopo cancellazione:\n";
    albero.StampaAlberoInOrder(albero.BinRadice(), 0);

    return 0;
}