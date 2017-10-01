#ifndef ALGO2_LABO_CLASE3_ABB_H_H
#define ALGO2_LABO_CLASE3_ABB_H_H

#include <memory>

using namespace std;

template<class T>
class ABB {
public:

    ABB() {
    }

    ABB(const T &elem) : _raiz(new T(elem)), _cantidad(1) {
    }

    void mostrar(ostream &os);

    friend ostream &operator<<(ostream &os, ABB &a) {
        a.mostrar(os);
        return os;
    }

    ABB<T> &subarbolIzquierdo() {
        assert(tieneSubarbolIzquierdo());
        return *_subarbolIzquierdo;
    }

    ABB<T> &subarbolDerecho() {
        assert(tieneSubarbolDerecho());
        return *_subarbolDerecho;
    }

    /**
     * Cantidad de elementos en el arbol
     * @return la cantidad de elementos
     */
    const size_t

    cantidad();

    /**
     * Inserta un elemento
     * @param elem elemento a agregar
     */
    void insertar(const T &elem);

    /**
     * Devuelve el elemento raíz
     * @return elemento en la raíz del arbol
     */
    const T &raiz();

    /**
     * Indica si el arbol tiene al menos un elemento
     * @return booleano indicando si tiene raíz
     */
    bool tieneRaiz();

    /**
     * Indica si el arbol tiene un subarbol izquierdo
     * @return booleano indicando si tiene subarbol izquierdo
     */
    bool tieneSubarbolIzquierdo();

    /**
     * Indica si el arbol tiene un subarbol derecho
     * @return booleano indicando si tiene subarbol derecho
     */
    bool tieneSubarbolDerecho();

    /**
     * Dado un elemento, indica si este existe en el arbol
     * @param elem - elemento a buscar
     * @return booleano indicando si el elemento parámetro existe
     */
    bool existe(const T &);

    /**
     * Devuelve la altura del arbol
     * @return size_t - la altura del arbol
     */
    size_t altura();

    /**
     * Devuelve la altura del subarbol izquierdo
     * @return size_t - la altura del subarbol izquierdo
     */
    size_t alturaSubarbolIzquierdo();

    /**
     * Devuelve la altura del subarbol derecho
     * @return size_t - la altura del subarbol derecho
     */
    size_t alturaSubarbolDerecho();

private:
    shared_ptr<ABB> _subarbolIzquierdo = nullptr;
    shared_ptr<ABB> _subarbolDerecho = nullptr;
    unique_ptr<T> _raiz = nullptr;

    size_t _cantidad = 0;

    void _insertarSubarbolIzquierdo(const T &elem);

    void _insertarSubarbolDerecho(const T &elem);

    /*
    bool operator<(const T &elem) {
        assert(tieneRaiz());
        return _raiz < elem;
    };

    bool operator==(const T &elem) {
        assert(tieneRaiz());
        _raiz == elem;
    }

    bool operator>(const T &elem) {
        assert(tieneRaiz());
        return not(_raiz < elem) and not(_raiz == elem);
    };

    bool operator!=(const T &elem) {
        assert(tieneRaiz());
        _raiz != elem;
    }
    struct Nodo {

        void mostrar(ostream &os) {
            os << "[" << izquierda << "," << derecha << "]";
        }

        friend ostream &operator<<(ostream &os, Nodo &n) {
            n.mostrar(os);
            return os;
        }
    };
    */
};

template<class T>
void ABB<T>::mostrar(ostream &os) {
    if (_raiz != nullptr) {
        os << *_raiz;
    } else {
        os << "Vacío";
    }
}

template<class T>
const size_t ABB<T>::cantidad() {
    return _cantidad;
}

template<class T>
void ABB<T>::insertar(const T &elem) {
    if (not tieneRaiz()) {
        _raiz = unique_ptr<T>(new T(elem));
    } else {
        if (elem < *_raiz) {
            _insertarSubarbolIzquierdo(elem);
        } else {
            _insertarSubarbolDerecho(elem);
        }
    }
    _cantidad++;
}

template<class T>
void ABB<T>::_insertarSubarbolIzquierdo(const T &elem) {
    if (tieneSubarbolIzquierdo()) {
        _subarbolIzquierdo->insertar(elem);
    } else {
        _subarbolIzquierdo = unique_ptr<ABB>(new ABB(elem));
    }
}

template<class T>
void ABB<T>::_insertarSubarbolDerecho(const T &elem) {
    if (tieneSubarbolDerecho()) {
        _subarbolDerecho->insertar(elem);
    } else {
        _subarbolDerecho = unique_ptr<ABB>(new ABB(elem));
    }
}

template<class T>
bool ABB<T>::tieneSubarbolIzquierdo() {
    return _subarbolIzquierdo != nullptr;
}

template<class T>
bool ABB<T>::tieneSubarbolDerecho() {
    return _subarbolDerecho != nullptr;
}

template<class T>
bool ABB<T>::tieneRaiz() {
    return (_cantidad > 0 and _raiz != nullptr);
}

template<class T>
const T &ABB<T>::raiz() {
    assert(tieneRaiz());
    return *_raiz;
}

template<class T>
bool ABB<T>::existe(const T &elem) {
    if (not tieneRaiz()) {
        return false;
    }
    if (raiz() == elem) {
        return true;
    }
    if (tieneSubarbolIzquierdo() and subarbolIzquierdo().existe(elem)) {
        return true;
    }
    if (tieneSubarbolDerecho() and subarbolDerecho().existe(elem)) {
        return true;
    }
    return false;
}

template<class T>
size_t ABB<T>::altura() {
    if (not tieneRaiz()) {
        return 0;
    }
    return 1 + max(alturaSubarbolIzquierdo(), alturaSubarbolDerecho());
}

template<class T>
size_t ABB<T>::alturaSubarbolIzquierdo() {
    return tieneSubarbolIzquierdo() ? subarbolIzquierdo().altura() : 0;
}

template<class T>
size_t ABB<T>::alturaSubarbolDerecho() {
    return tieneSubarbolDerecho() ? subarbolDerecho().altura() : 0;
}

#endif //ALGO2_LABO_CLASE3_ABB_H_H