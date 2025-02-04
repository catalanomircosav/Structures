#pragma once
#include <iostream>
#include <cassert>

namespace btree {
    template<typename T>
    class Nodo {
        public:
            typedef Nodo<T> nodo;

            // costruttore
            Nodo();                 // costruttore di default
            Nodo(const T&);         // costruttore parametrico
            Nodo(const nodo&);      // costruttore di copia
            Nodo(nodo&&) noexcept;  // costruttore di spostamento
            ~Nodo();

            // getter
            T getData() const;
            nodo* getPadre() const;
            nodo* getSx() const;
            nodo* getDx() const;

            // setter
            void setData(T*);
            void setPadre(nodo*);
            void setSx(nodo*);
            void setDx(nodo*);

            // utils
            void stampaNodo();

            // overload di operatori
            nodo& operator=(const nodo&);       // assegnamento per copia
            nodo& operator=(nodo&&) noexcept;   // assegnamento per spostamento

            bool operator==(const nodo&);
            bool operator!=(const nodo&);

        
        private:
            T data;
            nodo *padre;
            nodo *sx, *dx;
    };

    /*=================================*/
    /*========== COSTRUTTORE ==========*/
    /*=================================*/
    
    template<typename T>
    Nodo<T>::Nodo() : data(T()), padre(nullptr), sx(nullptr), dx(nullptr) {}

    template<typename T>
    Nodo<T>::Nodo(const T& data) : data(data), padre(nullptr), sx(nullptr), dx(nullptr) {}

    template<typename T>
    Nodo<T>::Nodo(const nodo& other);

    template<typename T>
    Nodo<T>::Nodo(nodo&& other) noexcept;

    /*=================================*/
    /*========== DISTRUTTORE ==========*/
    /*=================================*/
    
    template<typename T>
    Nodo<T>::~Nodo() { }

    /*=================================*/
    /*============ GETTER =============*/
    /*=================================*/
    
    template<typename T>
    T Nodo<T>::getData() const { return data; }

    template<typename T>
    typename Nodo<T>::nodo* Nodo<T>::getPadre() const { return padre; }

    template<typename T>
    typename Nodo<T>::nodo* Nodo<T>::getDx() const { return dx; }

    template<typename T>
    typename Nodo<T>::nodo* Nodo<T>::getSx() const { return sx; }

    /*=================================*/
    /*============ SETTER =============*/
    /*=================================*/
    
    template<typename T>
    void Nodo<T>::setData(T* d) { this->data = d; }
    
    template<typename T>
    void Nodo<T>::setPadre(nodo* p) { this->padre = p; }
    
    template<typename T>
    void Nodo<T>::setSx(nodo* s) { this->sx = s; }
    
    template<typename T>
    void Nodo<T>::setDx(nodo* d) { this->dx = d; }

    /*=================================*/
    /*============= UTILS =============*/
    /*=================================*/

    template<typename T>
    void Nodo<T>::stampaNodo() { std::cout << data << std::endl; }

    /*=================================*/
    /*=========== OPERATORI ===========*/
    /*=================================*/

    template<typename T>
    typename Nodo<T>::nodo& Nodo<T>::operator=(const nodo& other) {
        if(this != other) {
            this->setData(other.getData());
            this->setPadre(other.getPadre());
            this->setSx(other.getSx());
            this->setDx(other.getDx());
        }
        return *this;
    }

    template<typename T>
    typename Nodo<T>::nodo& Nodo<T>::operator=(nodo&& other) noexcept {
        if(this != other) {
            data = std::move(other.data);
            this->setPadre(other.getPadre());
            this->setSx(other.getSx());
            this->setDx(other.getDx());

            other.setPadre(nullptr);
            other.setSx(nullptr);
            other.setDx(nullptr);
        }
        return *this;
    }

    template<typename T>
    bool Nodo<T>::operator==(const nodo& n) {
        return (this->getData() == n.getData());
    }

    template<typename T>
    bool Nodo<T>::operator!=(const nodo& n) {
        return (this->getData() != n.getData());
    }
    
} // namespace btree