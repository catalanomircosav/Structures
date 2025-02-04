#pragma once
#include "Nodo.h"

namespace btree {
    template<typename T>
    class BTree {
        public:
            typedef Nodo<T> nodo;

            // costruttore
            BTree();
            BTree(nodo*);
            ~BTree();

            // observer
            bool BinAlberoVuoto() const;
            bool SinistroVuoto(nodo*) const;
            bool DestroVuoto(nodo*) const;

            // getter
            nodo* BinRadice() const;
            nodo* BinPadre(nodo*) const;
            nodo* FiglioSinistro(nodo*) const;
            nodo* FiglioDestro(nodo*) const;
            T LeggiNodo(nodo*);

            // setter
            void InsRadice(nodo*);
            void ScriviNodo(const T&, nodo*);

            // operazioni
            BTree<T> CostrBinAlbero(const BTree<T>&);
            void CancSottoBinAlbero(nodo*); 

            // utili
            bool TrovaNodo(nodo*);
            int CalcolaLivelloNodo(nodo*);

            // stampa
            void StampaAlberoPreOrder(nodo*, int) const;
            void StampaAlberoInOrder(nodo*, int) const;
            void StampaAlberoPostOrder(nodo*, int) const;

        private:
            // helper
            bool TrovaNodoRicorsivo(nodo*, nodo*);
            void CancSottoBinAlberoRicorsivo(nodo*);

            nodo* radice;
    };

    /*=================================*/
    /*========== COSTRUTTORE ==========*/
    /*=================================*/
    
    template<typename T>
    BTree<T>::BTree() : radice(nullptr) { }
    
    template<typename T>
    BTree<T>::BTree(nodo* r) : radice(r) { }

    template<typename T>
    BTree<T>::~BTree() { }

    /*=================================*/
    /*=========== OBSERVER ============*/
    /*=================================*/

    template<typename T>
    bool BTree<T>::BinAlberoVuoto() const { return (radice == nullptr); }  
    
    template<typename T>
    bool BTree<T>::SinistroVuoto(nodo* u) const {
        assert(!(this->BinAlberoVuoto()) && "L'albero e' vuoto.\n");
        assert(this->TrovaNodo(u) && "Il nodo non e' presente nell'albero.\n");

        return (u->FiglioSinistro() == nullptr);
    }
    
    template<typename T>
    bool BTree<T>::DestroVuoto(nodo* u) const {
        assert(!(this->BinAlberoVuoto()) && "L'albero e' vuoto.\n");
        assert(this->TrovaNodo(u) && "Il nodo non e' presente nell'albero.\n");
  
        return (u->FiglioDestro() == nullptr);
    }

    /*=================================*/
    /*============= GETTER ============*/
    /*=================================*/

    template<typename T>
    typename BTree<T>::nodo* BTree<T>::BinRadice() const {
        assert(!(this->BinAlberoVuoto()) && "L'albero e' vuoto.\n");
        
        return (radice);
    }
    
    template<typename T>
    typename BTree<T>::nodo* BTree<T>::BinPadre(nodo* u) const {
        assert(!(this->BinAlberoVuoto()) && "L'albero e' vuoto.\n");
        assert(this->TrovaNodo(u) && "Il nodo non e' presente nell'albero.\n");
        assert(this->CalcolaLivelloNodo(u) > 0 && "Il nodo non ha padre.\n");
        
        return (u->getPadre());
    }
    
    template<typename T>
    typename BTree<T>::nodo* BTree<T>::FiglioSinistro(nodo* s) const { 
        assert(!(this->BinAlberoVuoto()) && "L'albero e' vuoto.\n");
        assert(this->TrovaNodo(s) && "Il nodo non e' presente nell'albero.\n");
        assert(s->getSx() && "Il nodo non ha un figlio sinistro.\n");

        return (s->getSx());
    }
    
    template<typename T>
    typename BTree<T>::nodo* BTree<T>::FiglioDestro(nodo* d) const { 
        assert(this->BinAlberoVuoto() && "L'albero e' vuoto.\n");
        assert(this->TrovaNodo(d) && "Il nodo non e' presente nell'albero.\n");
        assert(d->getDx() && "Il nodo non ha un figlio destro.\n");
        
        return (d->getDx());
    }
    
    template<typename T>
    T BTree<T>::LeggiNodo(nodo* u) {
        assert(TrovaNodo(u) && "Il nodo non e' presente nell'albero.\n");

        return (u->getData());
    }

    /*=================================*/
    /*============= SETTER ============*/
    /*=================================*/

    template<typename T>
    void BTree<T>::InsRadice(nodo* r) { 
        assert(this->BinAlberoVuoto() && "L'albero non e' vuoto.\n");
        (this->radice = r);
    }
    
    template<typename T>
    void BTree<T>::ScriviNodo(const T& d, nodo* u) { 
        assert(this->TrovaNodo(u) && "Il nodo non e' presente nell'albero.\n");

        (u.setData(d));
    }
    
    /*=================================*/
    /*=========== OPERAZIONI ==========*/
    /*=================================*/

    template<typename T>
    BTree<T> BTree<T>::CostrBinAlbero(const BTree<T>& alb) {
        BTree<T>* nuovo = new BTree<T>();
        nodo* r = new nodo();
        nuovo->InsRadice(r);

        if (this->BinRadice())
            r->setSx(this->BinRadice());

        if (alb.BinRadice())
            r->setDx(alb.BinRadice());

        return *nuovo;
    }


    template<typename T>
    void BTree<T>::CancSottoBinAlbero(nodo*) {
        assert(!(this->BinAlberoVuoto()) && "L'albero e' vuoto.\n");
        assert(this->TrovaNodo(u) && "Il nodo non e' presente nell'albero.\n");

        CancSottoBinAlberoRicorsivo(u);
    }

    /*=================================*/
    /*=========== OPERAZIONI ==========*/
    /*=================================*/

    template<typename T>
    bool BTree<T>::TrovaNodo(nodo* u) {
        assert(!(this->BinAlberoVuoto()) && "L'albero e' vuoto.\n");

        return TrovaNodoRicorsivo(radice, u);
    }

    template<typename T>
    int BTree<T>::CalcolaLivelloNodo(nodo* u) {
        int livello = 0;

        nodo* tmp = u;
        while(tmp != radice) {
            tmp = this->BinPadre(tmp);
            livello++;
        }

        return livello;
    }

    /*=================================*/
    /*============ HELPERS ============*/
    /*=================================*/

    template<typename T>
    bool BTree<T>::TrovaNodoRicorsivo(nodo* corrente, nodo* u) {
        if(!corrente) return false;

        if(corrente == u) return true;

        return (this->TrovaNodoRicorsivo(corrente->getSx(), u) || this->TrovaNodoRicorsivo(corrente->getDx(), u));
    }

    template<typename T>
    void BTree<T>::CancSottoBinAlberoRicorsivo(nodo* u) {
        if(!u) return;

        CancSottoBinAlberoRicorsivo(u->getSx());
        CancSottoBinAlberoRicorsivo(u->getDx());

        delete u; u = nullptr;
    }

    /*=================================*/
    /*============= STAMPA ============*/
    /*=================================*/
    
    template<typename T>
    void BTree<T>::StampaAlberoPreOrder(nodo* n, int livello) const {
        if (!n) return;

        for (int i = 0; i < livello; ++i)
            std::cout << "  ";
        
        std::cout << n->getData() << std::endl;

        StampaAlberoPreOrder(n->getSx(), livello + 1);
        StampaAlberoPreOrder(n->getDx(), livello + 1);
    }

    template<typename T>
    void BTree<T>::StampaAlberoInOrder(nodo* n, int livello) const {
        if (!n) return;

        StampaAlberoInOrder(n->getSx(), livello + 1);

        for (int i = 0; i < livello; ++i)
            std::cout << "  ";

        std::cout << n->getData() << std::endl;

        StampaAlberoInOrder(n->getDx(), livello + 1);
    }

    template<typename T>
    void BTree<T>::StampaAlberoPostOrder(nodo* n, int livello) const {
        if (!n) return;

        StampaAlberoPostOrder(n->getSx(), livello + 1);
        StampaAlberoPostOrder(n->getDx(), livello + 1);

        for (int i = 0; i < livello; ++i)
            std::cout << "  ";

        std::cout << n->getData() << std::endl;
    }
} // namespace btree