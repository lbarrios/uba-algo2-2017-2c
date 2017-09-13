#ifndef ALGO2_LABO_CLASE5_ALGORITMOS_H
#define ALGO2_LABO_CLASE5_ALGORITMOS_H

#include <utility>
#include <iterator>
#include <vector>

// Nombres de las operaciones a implementar en el Taller
// Ver ../tests/algo-tests.cpp para ejemplos de uso de estas operaciones.

// minimo: minimo valor del contenedor pasado como parámetro.
// El contenedor debe almacenar valores ordenables

// maximo : maximo valor del contenedor pasado como parámetro
// El contenedor debe almacenar valores ordenables

// promedio: valor promedio del contenedor pasado como parámetro
// El contenedor debe almacenar uno o mas valores sumables entre si y divisibles por un Nat

// ordenado: chequea si estan ordenados los elementos del contenedor pasado como parametro
// un segundo parametro bool controla si el orden es creciente (true) o decreciente (false)

// minimoIter: retorna el minimo valor a partir de dos iteradores, pasados como parámetros,
// que representan un rango [desde,hasta)

// maximoIter: retorna el maximo valor a partir de dos iteradores, pasados como parámetros,
// que representan un rango [desde,hasta)

// promedioIter: retorna el valor promedio a partir de dos iteradores, pasados como parámetros,
// que representan un rango [desde,hasta)

// filtrar: quita las apariciones de un elemento en un contenedor

// split: dado un valor, parte un contenedor en dos contenedores del mismo tipo que el recibido
// que almacenen los elementos menores y los mayores al elemento recibido
// Devuelve el resultado en un std::pair con (menores, mayores).

// merge: dados dos contenedores cuyos valores están ordenados,
// los combina de manera ordenada, agregandolos **al final** de un tercer contenedor
// pasado como parámetro por referencia (su contenido previo no se pisa).

#endif //ALGO2_LABO_CLASE5_ALGORITMOS_H
