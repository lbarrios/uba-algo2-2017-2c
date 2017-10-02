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

    ABB<T> &subarbolIzquierdo() const;
    //const ABB<T> &subarbolIzquierdo() const;

    ABB<T> &subarbolDerecho() const;
    //const ABB<T> &subarbolDerecho() const;

    /**
     * Cantidad de elementos en el arbol
     * @return la cantidad de elementos
     */
    const size_t cantidad() const;

    /**
     * Inserta un elemento
     * @param elem elemento a agregar
     */
    void insertar(const T &elem);

    /**
     * Remueve un elemento
     * @pre El elemento elem existe en el ABB
     * @param elem elemento a borrar
     */
    void remover(const T &elem);

    /**
     * Devuelve el elemento raíz
     * @return elemento en la raíz del arbol
     */
    const T &raiz() const;

    /**
     * Indica si el arbol tiene al menos un elemento
     * @return booleano indicando si tiene raíz
     */
    const bool tieneRaiz() const;

    /**
     * Indica si el arbol tiene un subarbol izquierdo
     * @return booleano indicando si tiene subarbol izquierdo
     */
    const bool tieneSubarbolIzquierdo() const;

    /**
     * Indica si el arbol tiene un subarbol derecho
     * @return booleano indicando si tiene subarbol derecho
     */
    const bool tieneSubarbolDerecho() const;

    /**
     * Dado un elemento, indica si este existe en el arbol
     * @param elem - elemento a buscar
     * @return booleano indicando si el elemento parámetro existe
     */
    const bool existe(const T &) const;

    /**
     * Devuelve la altura del arbol
     * @return size_t - la altura del arbol
     */
    const size_t altura() const;

    /**
     * Devuelve la altura del subarbol izquierdo
     * @return size_t - la altura del subarbol izquierdo
     */
    const size_t alturaSubarbolIzquierdo() const;

    /**
     * Devuelve la altura del subarbol derecho
     * @return size_t - la altura del subarbol derecho
     */
    const size_t alturaSubarbolDerecho() const;

    /**
     * Devuelve el mínimo elemento
     * @return T el mínimo elemento
     */
    const T &minimo() const;

    /**
     * Devuelve el máximo elemento
     * @return T el máximo elemento
     */
    const T &maximo() const;

private:
    unique_ptr<ABB> _subarbolIzquierdo = nullptr;
    unique_ptr<ABB> _subarbolDerecho = nullptr;
    unique_ptr<T> _raiz = nullptr;

    size_t _cantidad = 0;

    void _insertarSubarbolIzquierdo(const T &);

    void _insertarSubarbolDerecho(const T &);

    void _removerRaiz();

    void _reemplazaRaizPorMenorDeLosHijosDerechos();

    void _reemplazaRaizPorHijoIzquierdo();

    void _reemplazaRaizPorHijoDerecho();

    void _removerMinimo();

    void _removerMaximo();
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
const size_t ABB<T>::cantidad() const {
    return _cantidad;
}

template<class T>
ABB<T> &ABB<T>::subarbolIzquierdo() const {
    assert(tieneSubarbolIzquierdo());
    return *_subarbolIzquierdo;
}

template<class T>
ABB<T> &ABB<T>::subarbolDerecho() const {
    assert(tieneSubarbolDerecho());
    return *_subarbolDerecho;
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
void ABB<T>::_reemplazaRaizPorHijoIzquierdo() {
    unique_ptr<ABB> hijoIzquierdo = move(_subarbolIzquierdo);
    _subarbolIzquierdo = move(hijoIzquierdo->_subarbolIzquierdo);
    _subarbolDerecho = move(hijoIzquierdo->_subarbolDerecho);
    _raiz = move(hijoIzquierdo->_raiz);
}

template<class T>
void ABB<T>::_reemplazaRaizPorHijoDerecho() {
    unique_ptr<ABB> hijoDerecho = move(_subarbolDerecho);
    _subarbolIzquierdo = move(hijoDerecho->_subarbolIzquierdo);
    _subarbolDerecho = move(hijoDerecho->_subarbolDerecho);
    _raiz = move(hijoDerecho->_raiz);
}

template<class T>
void ABB<T>::_reemplazaRaizPorMenorDeLosHijosDerechos() {
    assert(tieneSubarbolDerecho());
    _raiz = unique_ptr<T>(new T(subarbolDerecho().minimo()));
    _subarbolDerecho->_removerMinimo();
}

template<class T>
void ABB<T>::_removerMinimo() {
    if (tieneSubarbolIzquierdo()) {
        _subarbolIzquierdo->_removerMinimo();
    } else {
        _removerRaiz();
    }
}

template<class T>
void ABB<T>::_removerMaximo() {
    if (tieneSubarbolDerecho()) {
        _subarbolDerecho->_removerMaximo();
    } else {
        _removerRaiz();
    }
}

template<class T>
void ABB<T>::_removerRaiz() {
    if (not tieneSubarbolIzquierdo() and not tieneSubarbolDerecho()) {
        // No tiene hijos
        _raiz.reset();
    }
    if (not tieneSubarbolIzquierdo() and tieneSubarbolDerecho()) {
        // Solo tiene hijos derechos
        _reemplazaRaizPorHijoDerecho();
    }
    if (tieneSubarbolIzquierdo() and not tieneSubarbolDerecho()) {
        // Solo tiene hijos izquierdos
        _reemplazaRaizPorHijoIzquierdo();
    }
    if (tieneSubarbolIzquierdo() and tieneSubarbolDerecho()) {
        // Tiene hijos izquierdos y derechos
        _reemplazaRaizPorMenorDeLosHijosDerechos();
    }
}

template<class T>
void ABB<T>::remover(const T &elem) {
    assert(existe(elem));
    if (raiz() == elem) {
        _removerRaiz();
    } else {
        if (elem < raiz()) {
            subarbolIzquierdo().remover(elem);
            if (not subarbolIzquierdo().tieneRaiz()) {
                _subarbolIzquierdo.reset();
            }
        } else {
            subarbolDerecho().remover(elem);
            if (not subarbolDerecho().tieneRaiz()) {
                _subarbolDerecho.reset();
            }
        }
    }
    _cantidad--;
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
const bool ABB<T>::tieneSubarbolIzquierdo() const {
    return _subarbolIzquierdo != nullptr;
}

template<class T>
const bool ABB<T>::tieneSubarbolDerecho() const {
    return _subarbolDerecho != nullptr;
}

template<class T>
const bool ABB<T>::tieneRaiz() const {
    return (_cantidad > 0 and _raiz != nullptr);
}

template<class T>
const T &ABB<T>::raiz() const {
    assert(tieneRaiz());
    return *_raiz;
}

template<class T>
const bool ABB<T>::existe(const T &elem) const {
    if (not tieneRaiz()) {
        return false;
    }
    if (*_raiz == elem) {
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
const size_t ABB<T>::altura() const {
    if (not tieneRaiz()) {
        return 0;
    }
    return 1 + max(alturaSubarbolIzquierdo(), alturaSubarbolDerecho());
}

template<class T>
const size_t ABB<T>::alturaSubarbolIzquierdo() const {
    return tieneSubarbolIzquierdo() ? subarbolIzquierdo().altura() : 0;
}

template<class T>
const size_t ABB<T>::alturaSubarbolDerecho() const {
    return tieneSubarbolDerecho() ? subarbolDerecho().altura() : 0;
}

template<class T>
const T &ABB<T>::minimo() const {
    return tieneSubarbolIzquierdo() ? subarbolIzquierdo().minimo() : raiz();
}

template<class T>
const T &ABB<T>::maximo() const {
    return tieneSubarbolDerecho() ? subarbolDerecho().maximo() : raiz();
}

#endif //ALGO2_LABO_CLASE3_ABB_H_H