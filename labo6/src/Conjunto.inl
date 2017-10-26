template<class T>
bool Conjunto<T>::operator==(const Conjunto &otro) const {
    const ABB<T> &abbOtro = otro._abb;
    return _todosExistenEn(_abb, abbOtro) and _todosExistenEn(abbOtro, _abb);
}

template<class T>
bool Conjunto<T>::_todosExistenEn(const ABB<T> &abb, const ABB<T> &abbOtro) const {
    if (not abbOtro.existe(abb.raiz())) {
        return false;
    }
    if (abb.tieneSubarbolIzquierdo() and not _todosExistenEn(abb.subarbolIzquierdo(), abbOtro)) {
        return false;
    }
    if (abb.tieneSubarbolDerecho() and not _todosExistenEn(abb.subarbolDerecho(), abbOtro)) {
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

template<class T>
std::ostream &Conjunto<T>::mostrar(std::ostream &os) const {
    os << "Conjunto(";
    mostrar(os, _abb);
    os << ")";
    return os;
}

template<class T>
std::ostream &Conjunto<T>::mostrar(std::ostream &os, const ABB<T> &abb) const {
    os << abb.raiz();
    if(abb.tieneSubarbolIzquierdo()){
        os << ", ";
        mostrar(os, abb.subarbolIzquierdo());
    }
    if(abb.tieneSubarbolDerecho()){
        os << ", ";
        mostrar(os, abb.subarbolDerecho());
    }
    return os;
}