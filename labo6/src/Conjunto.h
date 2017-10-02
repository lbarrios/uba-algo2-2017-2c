#ifndef ALGO2_LABO_CLASE3_CONJUNTO_H
#define ALGO2_LABO_CLASE3_CONJUNTO_H

#include <string>
#include <iostream>
#include <memory>
#include "ABB.h"

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

    bool operator!=(const Conjunto &otro) const {
        return not(*this == otro);
    }

    /**
     * Constructor sin parámetros de la clase por defecto
     */
    Conjunto() = default;

    /**
     * Destructor por defecto
     */
    ~Conjunto() = default;

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
    ABB<T> _abb;

    const T &_siguienteEn(const T &, ABB<T> &);

    bool _todosExistenEn(const ABB<T> &, const ABB<T> &) const;
};

template<class T>
bool Conjunto<T>::operator==(const Conjunto &otro) const {
    const ABB<T> &abbOtro = otro._abb;
    return _todosExistenEn(_abb, abbOtro) and _todosExistenEn(abbOtro, _abb);
}

template<class T>
bool Conjunto<T>::_todosExistenEn(const ABB<T> &abb, const ABB<T> &abbOtro) const {
    if(not abbOtro.existe(abb.raiz())){
        return false;
    }
    if(abb.tieneSubarbolIzquierdo() and not _todosExistenEn(abb.subarbolIzquierdo(), abbOtro)){
        return false;
    }
    if(abb.tieneSubarbolDerecho() and not _todosExistenEn(abb.subarbolDerecho(), abbOtro)){
        return false;
    }
    return true;
}

template<class T>
void Conjunto<T>::insertar(const T &elem) {
    if (not _abb.existe(elem)) {
        _abb.insertar(elem);
    }
}

template<class T>
bool Conjunto<T>::pertenece(const T &elem) const {
    return _abb.existe(elem);
}

template<class T>
const T &Conjunto<T>::siguiente(const T &elem) {
    return _siguienteEn(elem, _abb);
}

template<class T>
const T &Conjunto<T>::_siguienteEn(const T &elem, ABB<T> &abb) {
    if (elem == abb.raiz()) {
        if (abb.tieneSubarbolDerecho()) {
            return abb.subarbolDerecho().minimo();
        }
    }
    if (elem > abb.raiz()) {
        if (abb.tieneSubarbolDerecho()) {
            return _siguienteEn(elem, abb.subarbolDerecho());
        } else {
            return elem;
        }
    } else {
        if (abb.tieneSubarbolIzquierdo()) {
            const T &siguienteEnIzquierdo = _siguienteEn(elem, abb.subarbolIzquierdo());
            if (siguienteEnIzquierdo == elem) {
                return abb.raiz();
            } else {
                return siguienteEnIzquierdo;
            }
        } else {
            return abb.raiz();
        }
    }
}

template<class T>
void Conjunto<T>::remover(const T &elem) {
    _abb.remover(elem);
}

template<class T>
const T &Conjunto<T>::minimo() const {
    return _abb.minimo();
}

template<class T>
const T &Conjunto<T>::maximo() const {
    return _abb.maximo();
}

template<class T>
std::size_t Conjunto<T>::cardinal() const {
    return _abb.cantidad();
}

#endif //ALGO2_LABO_CLASE3_CONJUNTO_H
