#include "DiccHash.h"

template<class V>
DiccHash<V>::DiccHash() : _cant_elems(0), _tam(TAM_TABLA_INI) {
		_tabla = new list<dato>[TAM_TABLA_INI];
}

template<class V>
DiccHash<V>::~DiccHash() {
		delete [] _tabla;
}
