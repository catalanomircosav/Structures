#pragma once
#include <iostream>
#include <cassert>
#include "Nodo.h"

namespace tree {

template<typename T>
class BTree {
public:
    typedef Nodo<T> nodo;

    // Costruttore e Distruttore
    BTree();
    ~BTree();

    // Osservatori
    bool BinAlberoVuoto() const;
    bool SinistroVuoto(nodo* u) const;
    bool DestroVuoto(nodo* u) const;
    bool TrovaNodo(nodo* u) const;

    // Operazioni
    void InserisciNodo(const T& valore);
    void ScriviNodo(const T& valore, nodo* u);

    // Getters
    nodo* BinRadice() const;
    nodo* BinPadre(nodo* u) const;
    nodo* FiglioSinistro(nodo* u) const;
    nodo* FiglioDestro(nodo* u) const;
    T LeggiNodo(nodo* u) const;

    // Utils
    void StampaAlberoPreOrder(nodo* current, int livello) const;
    void StampaAlberoInOrder(nodo* current, int livello) const;
    void StampaAlberoPostOrder(nodo* current, int livello) const;

    void CancellaSottoAlbero(nodo* u);

private:
    void CancellaRicorsivo(nodo* u);
    nodo* radice;
};

/*=================================*/
/*========== COSTRUTTORE ==========*/
/*=================================*/
template<typename T>
BTree<T>::BTree() : radice(nullptr) {}

/*=================================*/
/*========== DISTRUTTORE ==========*/
/*=================================*/
template<typename T>
BTree<T>::~BTree() {
    CancellaRicorsivo(radice);
}

/*=================================*/
/*=========== OSSERVATORI ==========*/
/*=================================*/
template<typename T>
bool BTree<T>::BinAlberoVuoto() const {
    return radice == nullptr;
}

template<typename T>
bool BTree<T>::SinistroVuoto(nodo* u) const {
    assert(u && "Nodo non valido.");
    return u->getSx() == nullptr;
}

template<typename T>
bool BTree<T>::DestroVuoto(nodo* u) const {
    assert(u && "Nodo non valido.");
    return u->getDx() == nullptr;
}

template<typename T>
bool BTree<T>::TrovaNodo(nodo* u) const {
    if (BinAlberoVuoto()) return false;

    nodo* current = radice;
    while (current) {
        if (current == u) return true;
        current = (current->getData() < u->getData()) ? current->getDx() : current->getSx();
    }
    return false;
}

/*=================================*/
/*========== OPERAZIONI ===========*/
/*=================================*/
template<typename T>
void BTree<T>::InserisciNodo(const T& valore) {
    nodo* nuovoNodo = new nodo(valore);

    if (BinAlberoVuoto()) {
        radice = nuovoNodo;
        return;
    }

    nodo* current = radice;
    nodo* parent = nullptr;

    while (current) {
        parent = current;
        if (valore < current->getData()) {
            current = current->getSx();
        } else {
            current = current->getDx();
        }
    }

    if (valore < parent->getData()) {
        parent->setSx(nuovoNodo);
    } else {
        parent->setDx(nuovoNodo);
    }
    nuovoNodo->setPadre(parent);
}

template<typename T>
void BTree<T>::ScriviNodo(const T& valore, nodo* u) {
    assert(u && "Nodo non valido.");
    u->setData(valore);
}

/*=================================*/
/*============ GETTERS ============*/
/*=================================*/
template<typename T>
typename BTree<T>::nodo* BTree<T>::BinRadice() const {
    return radice;
}

template<typename T>
typename BTree<T>::nodo* BTree<T>::BinPadre(nodo* u) const {
    assert(u && "Nodo non valido.");
    return u->getPadre();
}

template<typename T>
typename BTree<T>::nodo* BTree<T>::FiglioSinistro(nodo* u) const {
    assert(u && "Nodo non valido.");
    return u->getSx();
}

template<typename T>
typename BTree<T>::nodo* BTree<T>::FiglioDestro(nodo* u) const {
    assert(u && "Nodo non valido.");
    return u->getDx();
}

template<typename T>
T BTree<T>::LeggiNodo(nodo* u) const {
    assert(u && "Nodo non valido.");
    return u->getData();
}

/*=================================*/
/*========== UTILITA' ============*/
/*=================================*/
template<typename T>
void BTree<T>::StampaAlberoPreOrder(nodo* current, int livello) const {
    if (current != nullptr) {
        std::cout << std::string(livello * 4, ' ') << current->getData() << std::endl;
        StampaAlberoPreOrder(current->getSx(), livello + 1);
        StampaAlberoPreOrder(current->getDx(), livello + 1);
    }
}

template<typename T>
void BTree<T>::StampaAlberoInOrder(nodo* current, int livello) const {
    if (current != nullptr) {
        StampaAlberoInOrder(current->getSx(), livello + 1);
        std::cout << std::string(livello * 4, ' ') << current->getData() << std::endl;
        StampaAlberoInOrder(current->getDx(), livello + 1);
    }
}

template<typename T>
void BTree<T>::StampaAlberoPostOrder(nodo* current, int livello) const {
    if (current != nullptr) {
        StampaAlberoPostOrder(current->getSx(), livello + 1);
        StampaAlberoPostOrder(current->getDx(), livello + 1);
        std::cout << std::string(livello * 4, ' ') << current->getData() << std::endl;
    }
}

template<typename T>
void BTree<T>::CancellaSottoAlbero(nodo* u) {
    if (u == nullptr) return;

    CancellaSottoAlbero(u->getSx());
    CancellaSottoAlbero(u->getDx());

    if (u->getPadre() != nullptr) {
        if (u->getPadre()->getSx() == u) {
            u->getPadre()->setSx(nullptr);
        } else if (u->getPadre()->getDx() == u) {
            u->getPadre()->setDx(nullptr);
        }
    }

    delete u;

    if (u == radice) {
        radice = nullptr;
    }
}

template<typename T>
void BTree<T>::CancellaRicorsivo(nodo* u) {
    if (!u) return;
    CancellaRicorsivo(u->getSx());
    CancellaRicorsivo(u->getDx());
    delete u;
}

}