#include "Lista.h"

template<typename T>
Lista<T>::Lista() {
    // Completar
}

template<typename T>
Lista<T>::Lista(const Lista<T> &l) : Lista() {
    *this = l;
}

template<typename T>
Lista<T>::~Lista() {
    while (_primerNodo != nullptr) {
        eliminar(0);
    }
}

template<typename T>
Lista<T> &Lista<T>::operator=(const Lista<T> &l) {
    this->~Lista();

    for (int i = 0; i < l.longitud(); i++) {
        agregarAtras(l.iesimo(i));
    }
}

template<typename T>
void Lista<T>::agregarAdelante(const T &elem) {
    shared_ptr<Nodo> nodo{new Nodo(elem)};

    if (_longitud == 0) {
        _primerNodo = nodo;
        _ultimoNodo = nodo;
    } else {
        _primerNodo->anterior = nodo;
        nodo->siguiente = _primerNodo;
        _primerNodo = nodo;
    }

    _longitud++;
}

template<typename T>
void Lista<T>::agregarAtras(const T &elem) {
    shared_ptr<Nodo> nodo{new Nodo(elem)};

    if (_longitud == 0) {
        _primerNodo = nodo;
        _ultimoNodo = nodo;
    } else {
        _ultimoNodo->siguiente = nodo;
        nodo->anterior = _ultimoNodo;
        _ultimoNodo = nodo;
    }

    _longitud++;
}

template<typename T>
void Lista<T>::eliminar(Nat i) {
    shared_ptr<Nodo> t = _primerNodo;

    while (i > 0) {
        t = t->siguiente;
        --i;
    }

    if (t == _primerNodo) {
        _primerNodo = t->siguiente;
    } else {
        t->anterior->siguiente = t->siguiente;
    }

    if (t == _ultimoNodo) {
        _ultimoNodo = t->anterior;
    } else {
        t->siguiente->anterior = t->anterior;
    }

    _longitud--;
}

template<typename T>
int Lista<T>::longitud() const {
    return _longitud;
}

template<typename T>
const T &Lista<T>::iesimo(Nat i) const {
    shared_ptr<Nodo> t = _primerNodo;
    while (i > 0) {
        t = t->siguiente;
        --i;
    }
    return t->_elem;
}

template<typename T>
T &Lista<T>::iesimo(Nat i) {
    shared_ptr<Nodo> t = _primerNodo;
    while (i > 0) {
        t = t->siguiente;
        --i;
    }
    return t->_elem;
}

template<typename T>
void Lista<T>::mostrar(ostream &o) {
    shared_ptr<Nodo> t = _primerNodo;
    o << "[";
    while (t != nullptr) {
        o << t->_elem << ",";
        t = t->siguiente;
    }
    o << "]";
}
