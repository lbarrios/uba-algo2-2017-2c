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

    friend std::ostream &operator<<(std::ostream &os, Conjunto<T> &c) {
        return c.mostrar(os);
    }

    std::ostream &mostrar(std::ostream &) const;

private:
    ABB<T> _abb;

    const T &_siguienteEn(const T &, ABB<T> &);

    bool _todosExistenEn(const ABB<T> &, const ABB<T> &) const;

    std::ostream &mostrar(std::ostream &, const ABB<T> &) const;
};

#include "Conjunto.inl"

#endif //ALGO2_LABO_CLASE3_CONJUNTO_H
