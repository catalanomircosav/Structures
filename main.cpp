#include <iostream>
#include "Tree/BTree.h"
using namespace btree;

int main() {
    // Creo alcuni nodi (ipotizzando che la classe Nodo abbia un costruttore che accetta un dato)
    Nodo<int>* root = new Nodo<int>(1);        // Nodo radice con valore 1
    Nodo<int>* leftChild = new Nodo<int>(2);   // Nodo sinistro con valore 2
    Nodo<int>* rightChild = new Nodo<int>(3);  // Nodo destro con valore 3
    Nodo<int>* leftLeft = new Nodo<int>(4);    // Nodo sinistro sinistro con valore 4
    Nodo<int>* rightLeft = new Nodo<int>(5);   // Nodo destro sinistro con valore 5

    Nodo<int>* root1 = new Nodo<int>(6);

    // Collegamento tra i nodi
    root->setSx(leftChild);
    root->setDx(rightChild);
    leftChild->setSx(leftLeft);
    rightChild->setDx(rightLeft);

    // Creo l'albero con la radice
    BTree<int> albero(root);

    // Test delle funzioni di stampa
    BTree<int> albero1(root1);

    BTree<int> risult = albero.CostrBinAlbero(albero1);

    std::cout << "Albero completo:\n";
    risult.StampaAlberoPostOrder(risult.BinRadice(), 0);  // Pre-order stampa
    
    std::cout << "Stampa in Pre-Order:\n";
    risult.StampaAlberoPreOrder(risult.BinRadice(), 0);  // Pre-order stampa

    std::cout << "\nStampa in In-Order:\n";
    risult.StampaAlberoInOrder(risult.BinRadice(), 0);   // In-order stampa

    std::cout << "\nStampa in Post-Order:\n";
    risult.StampaAlberoPostOrder(risult.BinRadice(), 0);  // Post-order stampa

    // Test altre funzioni
    std::cout << "\nVerifica se l'albero è vuoto: " << (albero.BinAlberoVuoto() ? "Sì" : "No") << std::endl;

    std::cout << "\nLeggi dato del nodo radice: " << albero.LeggiNodo(albero.BinRadice()) << std::endl;

    return 0;
}
