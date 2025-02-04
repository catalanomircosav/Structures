#pragma once
#include <iostream>
#include <cassert>

namespace ntree {
    template<typename T>
    class Nodo {
        public:
            typedef Nodo<T> nodo;

            // costruttore
            Nodo();
            Nodo(const T&);
            ~Nodo();

            // getters
            T getData() const;
            nodo *getPadre() const;
            nodo *getFiglio() const;
            nodo *getNext() const;

            // setters
            void setData(const T&);
            void setPadre(nodo *);
            void setFiglio(nodo *);
            void setNext(nodo *);

        private:
            T data;
            nodo *padre;
            nodo *figlio;
            nodo *next;
    };

    /*=================================*/
    /*========== COSTRUTTORE ==========*/
    /*=================================*/

    template<typename T>
    Nodo<T>::Nodo() : data(T()), padre(nullptr), figlio(nullptr), next(nullptr) { }

    template<typename T>
    Nodo<T>::Nodo(const T& d) : data(d), padre(nullptr), figlio(nullptr), next(nullptr) { }

    template<typename T>
    Nodo<T>::~Nodo() { }

    /*=================================*/
    /*============ GETTERS ============*/
    /*=================================*/

    template<typename T>
    T Nodo<T>::getData() const { return data; }

    template<typename T>
    Nodo<T> *Nodo<T>::getPadre() const { return padre; }

    template<typename T>
    Nodo<T> *Nodo<T>::getFiglio() const { return figlio; }

    template<typename T>
    Nodo<T> *Nodo<T>::getNext() const { return next; }

    /*=================================*/
    /*============ SETTERS ============*/
    /*=================================*/

    template<typename T>
    void Nodo<T>::setData(const T& d) { data = d; }
    
    template<typename T>
    void Nodo<T>::setPadre(Nodo<T> *p) { padre = p; }
    
    template<typename T>
    void Nodo<T>::setFiglio(Nodo<T> *f) { figlio = f; }
    
    template<typename T>
    void Nodo<T>::setNext(Nodo<T> *n) { next = n; }
}