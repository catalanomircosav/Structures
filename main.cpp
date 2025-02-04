#include <iostream>
#include "Tree/NTree.h"  // Assicurati che questo file includa la tua implementazione di NTree e Nodo
using namespace ntree;
using namespace std;

// Funzione di supporto per stampare l'albero in pre-order
template<typename T>
void StampaPreOrder(NTree<T>* tree, Nodo<T>* u, int livello = 0) {
    if (!u) return;
    // Indenta in base al livello
    for (int i = 0; i < livello; i++) cout << "  ";
    cout << u->getData() << endl;
    // Stampa il sottoalbero dei figli (usando getFiglio, che restituisce il primo figlio)
    StampaPreOrder(tree, u->getFiglio(), livello + 1);
    // Stampa i fratelli (usando getNext)
    StampaPreOrder(tree, u->getNext(), livello);
}

int main() {
    // ----- Test 1: Costruzione dell'albero e InsRadice -----
    cout << "Test 1: Inserimento della radice\n";
    // Creo nodi per l'albero principale
    Nodo<int>* n1 = new Nodo<int>(1);
    Nodo<int>* n2 = new Nodo<int>(2);
    Nodo<int>* n3 = new Nodo<int>(3);
    Nodo<int>* n4 = new Nodo<int>(4);
    Nodo<int>* n5 = new Nodo<int>(5);

    // Creo l'albero principale e inserisco la radice
    NTree<int> albero;
    albero.InsRadice(n1);
    
    // Collego n2 e n3 come figli di n1 (n2 come primo figlio, n3 come fratello successivo di n2)
    n1->setFiglio(n2);
    n2->setPadre(n1);      // Imposto il padre di n2
    n2->setNext(n3);
    n3->setPadre(n1);      // Imposto il padre di n3
    
    // Aggiungo n4 come figlio di n2 e n5 come fratello di n4
    n2->setFiglio(n4);
    n4->setPadre(n2);      // Imposto il padre di n4
    n4->setNext(n5);
    n5->setPadre(n2);      // Imposto il padre di n5

    cout << "Albero principale (Pre-Order):\n";
    StampaPreOrder(&albero, albero.Radice());

    // ----- Test 2: Verifica degli observer e getter -----
    cout << "\nTest 2: Observer e Getter\n";
    cout << "Albero vuoto? " << (albero.AlberoVuoto() ? "Si" : "No") << endl;
    cout << "Il nodo con valore 2 e' foglia? " 
         << (albero.Foglia(n2) ? "Si" : "No") << endl;  // n2 ha un figlio (n4), quindi NON è foglia
    cout << "Il nodo con valore 5 e' foglia? " 
         << (albero.Foglia(n5) ? "Si" : "No") << endl;  // n5 non ha figli
    cout << "Il livello del nodo 4 e': " << albero.ContaLivelloNodo(n4) << endl;
    cout << "Il padre del nodo 4 e': " << albero.Padre(n4)->getData() << endl;
    cout << "Il primo figlio del nodo 1 e': " << albero.PrimoFiglio(n1)->getData() << endl;
    cout << "Il fratello successivo di nodo 2 e': " << albero.SuccFratello(n2)->getData() << endl;

    // ----- Test 3: Ricerca nodo -----
    cout << "\nTest 3: Ricerca nodo\n";
    cout << "Il nodo con valore 3 e' presente? " 
         << (albero.TrovaNodo(n3) ? "Si" : "No") << endl;
    // Creo un nodo non inserito
    Nodo<int>* nNonPresente = new Nodo<int>(999);
    cout << "Il nodo con valore 999 e' presente? " 
         << (albero.TrovaNodo(nNonPresente) ? "Si" : "No") << endl;
    delete nNonPresente; // Pulizia

    // ----- Test 4: Inserimento di sottoalberi -----
    cout << "\nTest 4: Inserimento di sottoalberi\n";
    // Creiamo un piccolo sottoalbero
    Nodo<int>* s1 = new Nodo<int>(10);
    Nodo<int>* s2 = new Nodo<int>(20);
    Nodo<int>* s3 = new Nodo<int>(30);
    // Colleghiamo s2 e s3: s2 diventa il figlio di s1, s3 il fratello successivo di s2
    s1->setFiglio(s2);
    s2->setPadre(s1);
    s2->setNext(s3);
    s3->setPadre(s1);
    
    NTree<int> sottoalbero(s1);

    // Inseriamo il sottoalbero come primo sottoalbero del nodo 3
    albero.InsPrimoSottoAlbero(n3, sottoalbero);

    cout << "Albero dopo inserimento di sottoalbero (Pre-Order):\n";
    StampaPreOrder(&albero, albero.Radice());

    // Inseriamo un altro sottoalbero come fratello successivo di nodo 3
    Nodo<int>* s4 = new Nodo<int>(40);
    Nodo<int>* s5 = new Nodo<int>(50);
    s4->setFiglio(s5);
    s5->setPadre(s4);
    NTree<int> sottoalbero2(s4);

    albero.InsSottoAlbero(n3, sottoalbero2);

    cout << "\nAlbero dopo inserimento di un altro sottoalbero (Pre-Order):\n";
    StampaPreOrder(&albero, albero.Radice());

    // ----- Test 5: Cancellazione di un sottoalbero -----
    cout << "\nTest 5: Cancellazione di un sottoalbero\n";
    // Supponiamo di cancellare il sottoalbero con radice s1 (che era inserito come figlio di n3)
    albero.CancSottoAlbero(s1);
    cout << "Albero dopo cancellazione del sottoalbero con radice 10 (Pre-Order):\n";
    StampaPreOrder(&albero, albero.Radice());

    // ----- Test 6: Conta Livello Nodo -----
    cout << "\nTest 6: Livello di alcuni nodi\n";
    cout << "Livello del nodo 1 (radice): " << albero.ContaLivelloNodo(n1) << endl;
    cout << "Livello del nodo 2: " << albero.ContaLivelloNodo(n2) << endl;
    cout << "Livello del nodo 3: " << albero.ContaLivelloNodo(n3) << endl;
    cout << "Livello del nodo 40: " << albero.ContaLivelloNodo(s4) << endl;

    // Pulizia finale: in un'applicazione reale il distruttore di NTree dovrebbe liberare tutto l'albero.
    return 0;
}