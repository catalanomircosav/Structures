#include "Nodo.h"
#include <cassert>
#include <iostream>

namespace array {
    template<typename T>
    class Lista {
    public:
        typedef Nodo<T> nodo;
        typedef int pos;

        // costruttore e distruttore
        Lista();
        ~Lista();

        // osservatori
        bool ListaVuota() const;
        pos PrimoLista() const;
        pos UltimoLista() const;
        bool FineLista(pos) const;

        // getters
        T LeggiLista(pos) const;
        pos SuccLista(pos) const;
        pos PredLista(pos) const;

        // setters
        void ScriviLista(T, pos);
        void InsLista(T, pos);
        void CancLista(pos);

        // utili
        void StampaLista() const;

    private:
        int size;
        nodo* testa;
        nodo* coda;
    };

    /*=================================*/
    /*========== COSTRUTTORI ==========*/
    /*=================================*/

    template<typename T>
    Lista<T>::Lista() : testa(nullptr), coda(nullptr), size(0) {}

    template<typename T>
    Lista<T>::~Lista() {
        while (!ListaVuota()) {
            CancLista(PrimoLista());
        }
    }

    /*=================================*/
    /*========== OSSERVATORI ==========*/
    /*=================================*/

    template<typename T>
    bool Lista<T>::ListaVuota() const {
        return (size == 0);
    }

    template<typename T>
    typename Lista<T>::pos Lista<T>::PrimoLista() const {
        assert(!ListaVuota() && "La lista è vuota. Nessun primo elemento.");
        return 1;
    }

    template<typename T>
    typename Lista<T>::pos Lista<T>::UltimoLista() const {
        assert(!ListaVuota() && "La lista è vuota. Nessun ultimo elemento.");
        return size;
    }

    template<typename T>
    bool Lista<T>::FineLista(pos p) const {
        assert(p >= 0 && p <= size + 1 && "Posizione non valida.");
        return (p == 0 || p == size + 1);
    }

    /*=================================*/
    /*============ GETTERS ============*/
    /*=================================*/

    template<typename T>
    T Lista<T>::LeggiLista(pos p) const {
        assert(p >= 1 && p <= size && "Posizione non valida.");

        nodo* current = testa;
        for (int i = 1; i < p; ++i) {
            current = current->leggiSucc();
        }
        return current->leggiDato();
    }

    template<typename T>
    typename Lista<T>::pos Lista<T>::SuccLista(pos p) const {
        assert(p >= 1 && p < size && "Posizione non valida per succLista.");
        return p + 1;
    }

    template<typename T>
    typename Lista<T>::pos Lista<T>::PredLista(pos p) const {
        assert(p > 1 && p <= size && "Posizione non valida per predLista.");
        return p - 1;
    }

    /*=================================*/
    /*============ SETTERS ============*/
    /*=================================*/

    template<typename T>
    void Lista<T>::ScriviLista(T data, pos p) {
        assert(p >= 1 && p <= size && "Posizione non valida.");

        nodo* current = testa;
        for (int i = 1; i < p; ++i) {
            current = current->leggiSucc();
        }
        current->scriviDato(data);
    }

    template<typename T>
    void Lista<T>::InsLista(T data, pos p) {
        assert(p >= 1 && p <= size + 1 && "Posizione non valida.");

        nodo* nuovoNodo = new nodo(data);

        if (p == 1) {
            // Inserimento in testa
            nuovoNodo->scriviSucc(testa);
            if (testa != nullptr) {
                testa->scriviPrec(nuovoNodo);
            }
            testa = nuovoNodo;
            if (size == 0) {
                coda = nuovoNodo;
            }
        } else if (p == size + 1) {
            // Inserimento in coda
            nuovoNodo->scriviPrec(coda);
            if (coda != nullptr) {
                coda->scriviSucc(nuovoNodo);
            }
            coda = nuovoNodo;
        } else {
            // Inserimento in mezzo
            nodo* nodoPrecedente = testa;
            for (int i = 1; i < p - 1; ++i) {
                nodoPrecedente = nodoPrecedente->leggiSucc();
            }
            nodo* nodoSuccessivo = nodoPrecedente->leggiSucc();

            nuovoNodo->scriviPrec(nodoPrecedente);
            nuovoNodo->scriviSucc(nodoSuccessivo);
            nodoPrecedente->scriviSucc(nuovoNodo);
            if (nodoSuccessivo != nullptr) {
                nodoSuccessivo->scriviPrec(nuovoNodo);
            }
        }

        size++;
    }

    template<typename T>
    void Lista<T>::CancLista(pos p) {
        assert(p >= 1 && p <= size && "Posizione non valida.");

        nodo* daCancellare;

        if (p == 1) {
            // Cancellazione in testa
            daCancellare = testa;
            testa = testa->leggiSucc();
            if (testa != nullptr) {
                testa->scriviPrec(nullptr);
            } else {
                coda = nullptr;
            }
        } else if (p == size) {
            // Cancellazione in coda
            daCancellare = coda;
            coda = coda->leggiPrec();
            if (coda != nullptr) {
                coda->scriviSucc(nullptr);
            } else {
                testa = nullptr;
            }
        } else {
            // Cancellazione in mezzo
            nodo* nodoPrecedente = testa;
            for (int i = 1; i < p - 1; ++i) {
                nodoPrecedente = nodoPrecedente->leggiSucc();
            }
            daCancellare = nodoPrecedente->leggiSucc();
            nodo* nodoSuccessivo = daCancellare->leggiSucc();

            nodoPrecedente->scriviSucc(nodoSuccessivo);
            if (nodoSuccessivo != nullptr) {
                nodoSuccessivo->scriviPrec(nodoPrecedente);
            }
        }

        delete daCancellare;
        size--;
    }

    /*=================================*/
    /*============= UTILI =============*/
    /*=================================*/

    template<typename T>
    void Lista<T>::StampaLista() const {
        nodo* current = testa;
        while (current != nullptr) {
            std::cout << current->leggiDato() << " -> ";
            current = current->leggiSucc();
        }
        std::cout << "NULL" << std::endl;
    }
}
