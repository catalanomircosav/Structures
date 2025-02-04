#pragma once
#include "NTree_Nodo.h"

namespace ntree {
    template<typename T>
    class NTree {
        public:
            typedef Nodo<T> nodo;

            // costruttore
            NTree();
            NTree(nodo*);
            ~NTree();

            // observer
            bool AlberoVuoto() const;
            bool Foglia(nodo*);
            bool UltimoFratello(nodo*);

            // getter
            nodo* Radice() const;
            nodo* Padre(nodo*);
            nodo* PrimoFiglio(nodo*);
            nodo* SuccFratello(nodo*);

            // setter
            void InsRadice(nodo*);

            // operazioni
            void InsPrimoSottoAlbero(nodo*, const NTree<T>&);
            void InsSottoAlbero(nodo*, const NTree<T>&);

            // utili
            void CancSottoAlbero(nodo*);
            bool TrovaNodo(nodo*);
            int ContaLivelloNodo(nodo*);

            // stampa
            void StampaAlberoPreOrder() const;
            void StampaAlberoInOrder() const;
            void StampaAlberoPostOrder() const;

        private:
            nodo* radice;

            // helpers
            bool RicercaNodoRicorsivo(nodo*, nodo*);
            void CancSottoAlberoRicorsivo(nodo*);
    };

    /*=================================*/
    /*========== COSTRUTTORE ==========*/
    /*=================================*/

    template<typename T>
    NTree<T>::NTree() : radice(nullptr) {}

    template<typename T>
    NTree<T>::NTree(nodo* r) : radice(r) {}

    template<typename T>
    NTree<T>::~NTree() { }

    /*=================================*/
    /*=========== OBSERVER ============*/
    /*=================================*/

    template<typename T>
    bool NTree<T>::AlberoVuoto() const {
        return (radice == nullptr);
    }
    
    template<typename T>
    bool NTree<T>::Foglia(nodo* u) {
        assert(!(this->AlberoVuoto()) && "L'albero e' vuoto.\n");
        assert(this->TrovaNodo(u) && "Nodo non presente nell'albero.\n");
        
        return (u->getFiglio() == nullptr);
    }
    
    template<typename T>
    bool NTree<T>::UltimoFratello(nodo* u) {
        assert(!(this->AlberoVuoto()) && "L'albero e' vuoto.\n");
        assert(this->TrovaNodo(u) && "Nodo non presente nell'albero.\n");
        
        return (u->getNext() == nullptr);
    }

    /*=================================*/
    /*============= GETTER ============*/
    /*=================================*/

    template<typename T>
    typename NTree<T>::nodo* NTree<T>::Radice() const {
        assert(!(this->AlberoVuoto()) && "L'albero e' vuoto.\n");
        
        return radice;
    }

    template<typename T>
    typename NTree<T>::nodo* NTree<T>::Padre(nodo* u) {
        assert(!(this->AlberoVuoto()) && "L'albero e' vuoto.\n");
        assert(this->TrovaNodo(u) && "Nodo non presente nell'albero.\n");
        assert((this->ContaLivelloNodo(u) > 0) && "Il nodo non ha padre.\n");

        return (u->getPadre());
    }

    template<typename T>
    typename NTree<T>::nodo* NTree<T>::PrimoFiglio(nodo* u) {
        assert(!(this->AlberoVuoto()) && "L'albero e' vuoto.\n");
        assert(this->TrovaNodo(u) && "Nodo non presente nell'albero.\n");
        assert(!(this->Foglia(u)) && "Il nodo non e' una foglia.\n");

        return (u->getFiglio());
    }

    template<typename T>
    typename NTree<T>::nodo* NTree<T>::SuccFratello(nodo* u) {
        assert(!(this->AlberoVuoto()) && "L'albero e' vuoto.\n");
        assert(this->TrovaNodo(u) && "Nodo non presente nell'albero.\n");
        assert(!(this->UltimoFratello(u)) && "Il nodo non e' l'ultimo fratello.\n");

        return (u->getNext());
    }

    /*=================================*/
    /*============ SETTER =============*/
    /*=================================*/

    template<typename T>
    void NTree<T>::InsRadice(nodo* r) {
        assert(this->AlberoVuoto() && "L'albero non e' vuoto.\n");

        radice = r;
    }

    template<typename T>
    void NTree<T>::InsPrimoSottoAlbero(nodo* u, const NTree<T>& alb) {
        assert(!(this->AlberoVuoto()) && "L'albero e' vuoto.\n");
        assert(!(alb.AlberoVuoto()) && "L'albero da aggiungere e' vuoto.\n");
        assert(this->TrovaNodo(u) && "Nodo non presente nell'albero.\n");

        nodo* tmp = u->getFiglio();

        u->setFiglio(alb.Radice());
        alb.Radice()->setPadre(u);
        alb.Radice()->setNext(tmp);
    }

    template<typename T>
    void NTree<T>::InsSottoAlbero(nodo* u, const NTree<T>& alb) {
        assert(!(this->AlberoVuoto()) && "L'albero e' vuoto.\n");
        assert(!(alb.AlberoVuoto()) && "L'albero da aggiungere e' vuoto.\n");
        assert(this->TrovaNodo(u) && "Nodo non presente nell'albero.\n");
        assert(!(this->ContaLivelloNodo(u) <= 0) && "Il nodo e' radice.\n");

        nodo* tmp = u->getNext();

        u->setNext(alb.Radice());
        alb.Radice()->setPadre(u);
        alb.Radice()->setNext(tmp);
    }

    /*=================================*/
    /*============= UTILI =============*/
    /*=================================*/

    template<typename T>
    void NTree<T>::CancSottoAlbero(nodo* u) {
        assert(!(this->AlberoVuoto()) && "L'albero e' vuoto.\n");
        assert(this->TrovaNodo(u) && "Nodo non presente nell'albero.\n");

        this->CancSottoAlberoRicorsivo(u);
    }
    
    template<typename T>
    bool NTree<T>::TrovaNodo(nodo* u) {
        assert(!(this->AlberoVuoto()) && "L'albero e' vuoto.\n");

        return (this->RicercaNodoRicorsivo(radice, u));
    }

    template<typename T>
    int NTree<T>::ContaLivelloNodo(Nodo<T>* u) {
        int livello = 0;

        Nodo<T>* tmp = u;
        while (tmp != radice) {  // Fino a quando il nodo non è la radice
            tmp = tmp->getPadre();  // Ottieni il padre del nodo corrente
            livello++;  // Aumenta il livello
        }

        return livello;
    }

    /*=================================*/
    /*============ HELPERS ============*/
    /*=================================*/

    template<typename T>
    bool NTree<T>::RicercaNodoRicorsivo(nodo* u, nodo* v) {
        assert(!(this->AlberoVuoto()) && "L'albero e' vuoto.\n");
        
        if(!u) return false;
        if(u == v) return true;

        return (this->RicercaNodoRicorsivo(u->getFiglio(), v) ||
                this->RicercaNodoRicorsivo(u->getNext(), v));
    }

    template<typename T>
    void NTree<T>::CancSottoAlberoRicorsivo(nodo* u) {
        assert(!(this->AlberoVuoto()) && "L'albero e' vuoto.\n");

        if(!u) return;

        this->CancSottoAlberoRicorsivo(u->getFiglio());
        this->CancSottoAlberoRicorsivo(u->getNext());

        delete u; u = nullptr;
    }

    /*=================================*/
    /*============ STAMPA =============*/
    /*=================================*/
    template<typename T>
    void NTree<T>::StampaAlberoPreOrder() const {
        assert(!(this->AlberoVuoto()) && "L'albero e' vuoto.\n");
    }

    template<typename T>
    void NTree<T>::StampaAlberoInOrder() const {
        assert(!(this->AlberoVuoto()) && "L'albero e' vuoto.\n");
    }

    template<typename T>
    void NTree<T>::StampaAlberoPostOrder() const {
        assert(!(this->AlberoVuoto()) && "L'albero e' vuoto.\n");
    }
}