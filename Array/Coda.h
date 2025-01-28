#pragma once
#include "Lista.h"

namespace array {
    template<typename T>
    class Coda : public Lista<T> {
        public:
            // costruttore e distruttore
            Coda();
            ~Coda();

            // observer
            bool CodaVuota() const;

            // operazioni
            void FuoriCoda();
            void InCoda(const T&);

            // utils
            T LeggiCoda() const;
    };

    /*=================================*/
    /*========== COSTRUTTORE ==========*/
    /*=================================*/
    
    template<typename T>
    Coda<T>::Coda() : Lista<T>() {}

    /*=================================*/
    /*========== DISTRUTTORE ==========*/
    /*=================================*/

    template<typename T>
    Coda<T>::~Coda() {}

    /*=================================*/
    /*========== OSSERVATORI ==========*/
    /*=================================*/
    
    template<typename T>
    bool Coda<T>::CodaVuota() const {
        return (this->ListaVuota());
    }

    /*=================================*/
    /*=========== OPERAZIONI ==========*/
    /*=================================*/
    
    template<typename T>
    void Coda<T>::FuoriCoda() {
        assert(!CodaVuota() && "Coda vuota.");

        this->CancLista(this->PrimoLista());
    }
    
    template<typename T>
    void Coda<T>::InCoda(const T& d) {
        // Aggiunge l'elemento in coda (alla fine della lista)
        this->InsLista(d, this->UltimoLista() + 1);
    }
    
    /*=================================*/
    /*=========== OPERAZIONI ==========*/
    /*=================================*/

    template<typename T>
    T Coda<T>::LeggiCoda() const {
        assert(!CodaVuota() && "Coda vuota.");

        // Restituisce l'elemento in testa alla coda
        return (this->LeggiLista(this->PrimoLista()));
    }
}