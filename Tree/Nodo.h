#pragma once
#include <iostream>
#include <cassert>

namespace tree {
    template<typename T>
    class Nodo {
        public:
            typedef Nodo<T> pos;
            // costruttore e distruttore
            Nodo();
            Nodo(const T&);
            ~Nodo();

            // getters
            pos* getPadre() const;
            pos* getSx() const;
            pos* getDx() const;
            T getData() const;

            // setters
            void setPadre(pos*);
            void setSx(pos*);
            void setDx(pos*);
            void setData(const T&);

        private:
            T data;
            pos* padre;
            pos *sx, *dx;
    };
    /*=================================*/
    /*========== COSTRUTTORI ==========*/
    /*=================================*/

    template<typename T>
    Nodo<T>::Nodo() : padre(nullptr), sx(nullptr), dx(nullptr), data{} {}

    template<typename T>
    Nodo<T>::Nodo(const T& d) : padre(nullptr), sx(nullptr), dx(nullptr), data(d) {}

    /*=================================*/
    /*========== DISTRUTTORE ==========*/
    /*=================================*/

    template<typename T>
    Nodo<T>::~Nodo() { }

    /*=================================*/
    /*============ GETTERS ============*/
    /*=================================*/

    template<typename T>
    typename Nodo<T>::pos* Nodo<T>::getPadre() const {
        return padre;
    }
    
    template<typename T>
    typename Nodo<T>::pos* Nodo<T>::getSx() const {
        return sx;
    }
    
    template<typename T>
    typename Nodo<T>::pos* Nodo<T>::getDx() const {
        return dx;
    }

    template<typename T>
    T Nodo<T>::getData() const {
        return data;
    }

    /*=================================*/
    /*============ SETTERS ============*/
    /*=================================*/

    template<typename T>
    void Nodo<T>::setPadre(pos* p) {
        this->padre = p;
    }
    
    template<typename T>
    void Nodo<T>::setSx(pos* sx) {
        this->sx = sx;
    }
    
    template<typename T>
    void Nodo<T>::setDx(pos* dx) {
        this->dx = dx;
    }
    
    template<typename T>
    void Nodo<T>::setData(const T& d) {
        this->data = d;
    }
}