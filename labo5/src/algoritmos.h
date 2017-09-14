#ifndef ALGO2_LABO_CLASE5_ALGORITMOS_H
#define ALGO2_LABO_CLASE5_ALGORITMOS_H

#include <utility>
#include <iterator>
#include <vector>
#include <algorithm>    // std::min

// Nombres de las operaciones a implementar en el Taller
// Ver ../tests/algo-tests.cpp para ejemplos de uso de estas operaciones.

// minimo: minimo valor del contenedor pasado como parámetro.
// El contenedor debe almacenar valores ordenables
template<typename C>
typename C::value_type minimo(const C &c) {
    auto minIt = c.begin();
    for (auto it = c.begin(); it != c.end(); it++) {
        minIt = (*it) < (*minIt) ? it : minIt;
    }
    return (*minIt);
}


// maximo : maximo valor del contenedor pasado como parámetro
// El contenedor debe almacenar valores ordenables
template<typename C>
typename C::value_type maximo(const C &c) {
    auto maxIt = c.begin();
    for (auto it = c.begin(); it != c.end(); it++) {
        maxIt = (*it) > (*maxIt) ? it : maxIt;
    }
    return (*maxIt);
}

// promedio: valor promedio del contenedor pasado como parámetro
// El contenedor debe almacenar uno o mas valores sumables entre si y divisibles por un Nat
template<typename C>
typename C::value_type promedio(const C &c) {
    double total = 0;
    for (auto el:c) {
        total += el;
    }
    return total / c.size();
}

// ordenado: chequea si estan ordenados los elementos del contenedor pasado como parametro
// un segundo parametro bool controla si el orden es creciente (true) o decreciente (false)
template<typename C>
bool ordenado(const C &c, bool creciente) {
    auto lastEl = *(c.begin());
    for (auto el:c) {
        if ((creciente and lastEl > el) or (not creciente and lastEl < el)) {
            return false;
        }
        lastEl = el;
    }
    return true;
}

// minimoIter: retorna el minimo valor a partir de dos iteradores, pasados como parámetros,
// que representan un rango [desde,hasta)
template<typename Iterador>
typename Iterador::value_type minimoIter(Iterador start, Iterador end) {
    Iterador minimo = start;
    while (start != end) {
        minimo = *start < *minimo ? start : minimo;
        start++;
    }
    return *minimo;
}

// maximoIter: retorna el maximo valor a partir de dos iteradores, pasados como parámetros,
// que representan un rango [desde,hasta)
template<typename Iterador>
typename Iterador::value_type maximoIter(Iterador start, Iterador end) {
    Iterador maximo = start;
    while (start != end) {
        maximo = *start > *maximo ? start : maximo;
        start++;
    }
    return *maximo;
}

// promedioIter: retorna el valor promedio a partir de dos iteradores, pasados como parámetros,
// que representan un rango [desde,hasta)
template<typename Iterador>
typename Iterador::value_type promedioIter(Iterador start, Iterador end) {
    typename Iterador::value_type total = 0;
    int cantidad = 0;
    while (start != end) {
        total += *start;
        cantidad++;
        start++;
    }
    return total / cantidad;
}

// filtrar: quita las apariciones de un elemento en un contenedor
template<typename C>
void filtrar(C &c, const typename C::value_type &anElem) {
    for (auto it = c.begin(); it != c.end(); ++it) {
        while (*it == anElem) {
            it = c.erase(it);
        }
    }
}

// split: dado un valor, parte un contenedor en dos contenedores del mismo tipo que el recibido
// que almacenen los elementos menores y los mayores al elemento recibido
// Devuelve el resultado en un std::pair con (menores, mayores).
template<typename C>
std::pair<C, C> split(const C &c, const typename C::value_type &val) {
    C menores, mayores;
    for (auto it = c.begin(); it != c.end(); it++) {
        if (*it <= val) {
            menores.insert(menores.end(), *it);
        } else {
            mayores.insert(mayores.end(), *it);
        }
    }
    return std::make_pair(menores, mayores);
};

// merge: dados dos contenedores cuyos valores están ordenados,
// los combina de manera ordenada, agregandolos **al final** de un tercer contenedor
// pasado como parámetro por referencia (su contenido previo no se pisa).
template<typename C>
void merge(const C &c1, const C &c2, C &res) {
    auto it1 = c1.begin();
    auto it2 = c2.begin();
    while (it1 != c1.end() and it2 != c2.end()) {
        if (*it1 < *it2) {
            res.insert(res.end(), *it1);
            it1++;
        } else {
            res.insert(res.end(), *it2);
            it2++;
        }
    }
    while (it1 != c1.end()) {
        res.insert(res.end(), *it1);
        it1++;
    }
    while (it2 != c2.end()) {
        res.insert(res.end(), *it2);
        it2++;
    }
};
#endif //ALGO2_LABO_CLASE5_ALGORITMOS_H
