#ifndef ALGO2_LABO_CLASE3_CONJUNTO_H
#define ALGO2_LABO_CLASE3_CONJUNTO_H

#include <string>
#include <iostream>
#include <memory>

using namespace std;

template<class T>
class Conjunto {

public:

    /**
     * Chequeo de igualdad entre dos instancias de conjunto
     * @param otro conjunto a comparar
     * @return true si ambos conjuntos son iguales: todos los elementos
     */
    bool operator==(const Conjunto &otro) const;

    void mostrar(ostream &os){
        if(_raiz != nullptr) {
            os << _raiz;
        } else {
            os << "Vacío";
        }
    }

    friend ostream &operator<<(ostream &os, Conjunto &c) {
        c.mostrar(os);
        return os;
    }

    /**
     * Constructor sin parámetros de la clase
     */
    Conjunto();

    /**
     * Destructor
     */
    ~Conjunto();

    /**
     * Inserta un elemento
     * @param elem elemento a agregar
     */
    void insertar(const T &elem);

    /**
     * Chequeo de pertenecia
     * @param elem elemento a buscar
     * @return true si el elemento se encuentra en el conjunto
     */
    bool pertenece(const T &elem) const;

    /**
     * Siguiente en orden en conjunto
     * @param elem Elemento al que le quiero encontrar el siguiente
     */
    const T &siguiente(const T &elem);

    /**
     * Remueve elem del conjunto
     * @param elem elemento a remover
     */
    void remover(const T &elem);

    /**
     * Obtiene una puntero al nodo con valor minimo, devuelve nullptr si el nodo no existe
     * @return el minimo del conjunto
     */
    const T &minimo() const;

    /**
     * Obtiene una puntero al nodo con valor maximo, devuelve nullptr si el nodo no existe
     * @return el maximo del conjunto
     */
    const T &maximo() const;

    /**
     * Cardinal de conjunto
     * @return devuelve la cardinalidad del conjunto
     */
    size_t cardinal() const;


private:
    struct Nodo {
        shared_ptr<Nodo> izquierda = nullptr;
        shared_ptr<Nodo> derecha = nullptr;
        T _elem;

        bool operator<(const T &elem) {
            return _elem < elem;
        };

        bool operator==(const T &elem) {
            _elem == elem;
        }

        bool operator!=(const T &elem) {
            _elem != elem;
        }

        Nodo() : _elem() {
        }

        Nodo(const T &elem) : _elem(elem) {
        }

        void mostrar(ostream &os){
            os << "[" << izquierda << "," << derecha << "]";
        }
        friend ostream &operator<<(ostream &os, Nodo& n) {
            n.mostrar(os);
            return os;
        }
    };

    shared_ptr<Nodo> _raiz = nullptr;
    size_t _longitud = 0;

    shared_ptr<Conjunto<T>::Nodo> _buscarMaximoElementoMenor(const T &);

    shared_ptr<Conjunto<T>::Nodo> _buscarMinimoElementoMayor(const T &);

    /**
     * Completar con lo que sea necesario...
     * reutilizar codigo y clases ya implementadas
     */
};

template<class T>
Conjunto<T>::Conjunto() {

}

template<class T>
Conjunto<T>::~Conjunto() {

}

template<class T>
bool Conjunto<T>::operator==(const Conjunto &otro) const {
    return false;
}

template<class T>
shared_ptr<typename Conjunto<T>::Nodo> Conjunto<T>::_buscarMaximoElementoMenor(const T &elem) {
    shared_ptr<Nodo> nodo = _raiz;
    while (nodo->derecha != nullptr and nodo->derecha < elem) {
        nodo = nodo->derecha;
    }
    return nodo;
}

template<class T>
void Conjunto<T>::insertar(const T &elem) {
    shared_ptr<Nodo> nodoAInsertar{new Nodo(elem)};
    if (_longitud == 0) {
        _raiz = nodoAInsertar;
        _longitud++;
    } else {
        shared_ptr<Nodo> nodo = _raiz;
        while (nodo->derecha != nullptr or nodo->izquierda != nullptr) {
            if (nodo == elem) {
                // No inserto nada
                break;
            }
            if (elem < nodo) {
                // El nodo va a ser insertado a la izquierda
                if (nodo->izquierda != nullptr) {
                    nodo = nodo->izquierda;
                } else {
                    nodo->izquierda = nodoAInsertar;
                }
            }
            if (elem > nodo) {
                // El nodo va a ser insertado a la derecha
                if (nodo->derecha != nullptr) {
                    nodo = nodo->derecha;
                } else {
                    nodo->derecha = nodoAInsertar;
                }
            }

        }
    }
}

template<class T>
bool Conjunto<T>::pertenece(const T &elem) const {
    return false;
}

template<class T>
const T &Conjunto<T>::siguiente(const T &elem) {
    return elem;
}

template<class T>
void Conjunto<T>::remover(const T &elem) {

}

/*
template<class T>
const T &Conjunto<T>::minimo() const {
    return initializer;
}
*/

/*
template<class T>
const T &Conjunto<T>::maximo() const {
    return <#initializer#>;
}
*/

template<class T>
std::size_t Conjunto<T>::cardinal() const {
    return 0;
}


#include "Conjunto.inl"

#endif //ALGO2_LABO_CLASE3_CONJUNTO_H