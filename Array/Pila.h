#pragma once
#include "Lista.h"

namespace array {
    template<typename T>
    class Pila : public Lista<T> {
        public:

            // costruttore e distruttore
            Pila();
            ~Pila();

            // observer
            bool PilaVuota() const;

            // operazioni
            void FuoriPila();
            void InPila(const T&);

            // utils
            T LeggiPila();
    };

    /*=================================*/
    /*========== COSTRUTTORE ==========*/
    /*=================================*/
    
    template<typename T>
    Pila<T>::Pila() : Lista<T>() { }
    
    template<typename T>
    Pila<T>::~Pila() {}

    /*=================================*/
    /*============ OBSERVER ===========*/
    /*=================================*/
    
    template<typename T>
    bool Pila<T>::PilaVuota() const {
        return (this->ListaVuota());
    }

    /*=================================*/
    /*=========== OPERAZIONI ==========*/
    /*=================================*/
    
    template<typename T>
    void Pila<T>::FuoriPila() {
        this->CancLista(this->PrimoLista());
    }

    template<typename T>
    void Pila<T>::InPila(const T& d) {
        this->InsLista(d, this->PrimoLista());
    }

    /*=================================*/
    /*============= UTILI =============*/
    /*=================================*/
    
    template<typename T>
    T Pila<T>::LeggiPila() {
        return this->LeggiLista(this->UltimoLista());
    }
}