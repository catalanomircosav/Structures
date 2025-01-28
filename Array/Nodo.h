#pragma once
#include <iostream>
#include <cassert>

namespace array {
    template<typename T>
    class Nodo {
        public:
            typedef Nodo<T> pos;

            // costruttore e distruttore
            Nodo();
            Nodo(const T&);
            ~Nodo();

            // getters
            pos* leggiSucc() const;
            pos* leggiPrec() const;
            T leggiDato() const;

            // setters
            void scriviSucc(pos*);
            void scriviPrec(pos*);
            void scriviDato(const T&);

        private:

            pos *next, *prev;
            
            T dato;
    };

    /*=================================*/
    /*========== COSTRUTTORI ==========*/
    /*=================================*/
    
    template<typename T>
    Nodo<T>::Nodo() : next(nullptr), dato{} {}

    template<typename T>
    Nodo<T>::Nodo(const T& d) : next(nullptr), dato(d) {}

    template<typename T>
    Nodo<T>::~Nodo() { }

    /*=================================*/
    /*============ GETTERS ============*/
    /*=================================*/

    template<typename T>
    typename Nodo<T>::pos* Nodo<T>::leggiSucc() const {
        return next;
    }

    template<typename T>
    typename Nodo<T>::pos* Nodo<T>::leggiPrec() const {
        return prev;
    }

    template<typename T>
    T Nodo<T>::leggiDato() const {
        return dato;
    }
    
    /*=================================*/
    /*============ SETTERS ============*/
    /*=================================*/

    template<typename T>
    void Nodo<T>::scriviSucc(pos* p) {
        next = p;
    }
    
    template<typename T>
    void Nodo<T>::scriviPrec(pos* p) {
        prev = p;
    }
    
    template<typename T>
    void Nodo<T>::scriviDato(const T& d) {
        dato = d;
    }

};