#ifndef ALGO2_LABO_HASH_DICCHASH_H
#define ALGO2_LABO_HASH_DICCHASH_H

#include <string>
#include <iostream>
#include <set>
#include <list>

using namespace std;

#ifndef TAM_TABLA_INI
#define TAM_TABLA_INI 100
#endif
#ifndef UMBRAL_FC
#define UMBRAL_FC	  0.75
#endif

template<class V>
class DiccHash {
public:

    /**
     * Chequeo de igualdad entre dos instancias de Diccionario
     * @param otro Diccionario a comparar
     * @return true si ambos Diccionario son iguales: si tienen las
     * mismas claves y para cada clave el significado es el mismo
     */
    bool operator==(const DiccHash& otro) const;


    /**
   * Constructor sin parámetros de la clase
   */
    DiccHash();

    /**
     * Destructor
     */
    ~DiccHash();


    /**
    * Chequea si la clave está definida en el diccionario
    * @param clav clave a buscar
    * @return true si la clave esta definida
    */
    bool Definido(const string& clav) const;


    /**
   * Agrega una clave y su significado al Diccionario.
   * Si la clave a agregar ya esta, entonces se redefine el significado
   * @param clav clave a agregar
   * @param sig significado de la clave a agregar
   * Recordar que si el factor de carga es mayor a UMBRAL_FC, hay que redimensionar la tabla
   */
    void Definir(const string& clav, const V& sig);


    /**
     * Busca en el diccionario el significado de la clave clav.
     * @param clav clave a buscar
     * @return el significado de clav
     */
    V& Significado(const string& clav);


    /**
    * Borra la clave del diccionario
    * @param clav clave a borrar
    * @pre: clav está definida en el diccionario
    */
    void Borrar(const string& clav);


    /**
    * Calcula la cantidad de claves del diccionario
    * @param clav clave a borrar
    * @return cantidad de claves el diccionario
    */
    unsigned int CantClaves() const;


    /**
    * Devuelve las claves del diccionario
    * @return Devuelve un conjunto con las claves del diccionario
    */
    set<string> Claves() const;



    /**
     *  // SOLO PARA TEST
     * Calcula el factor de carga del hash
     * Factor de carga : cantidad de claves definidas / tamaño de la tabla
    * @return Devuelve el factor de carga del diccionario
    */
    float factorCarga() const;



    /**
   * // SOLO PARA TEST
   * @return la cantidad de coliciones que tiene el diccionario
   */
    unsigned int colisiones() const;


private:
    /**
     * Completar con lo que sea necesario...
    */

    typedef pair<string,V> dato;
    list<dato>*   _tabla;
    unsigned int _cant_elems;
    unsigned int _tam;



    /**
    * Función de hash
    * Recordar usar  hash = hash % _tam (El operador '%' es 'módulo'!)
    * @return posición de la tabla donde se va a guardar el dato
   */
    unsigned int fn_hash (const string& str) const;


    /**
    * Redimensiona la tabla de hash.
    * Recordar:
    * Duplicar el tamaño de  la tabla, guardar el valor en _tam (para utilizar luego en el hash)
    * Insertar las claves anteriores
    * Eliminar toda la memoria utilizada en la tabla vieja!!!
    *
    */
    void redimensionarTabla();
};


#include "DiccHash.inl"


#endif //ALGO2_LABO_HASH_DICCHASH_H
