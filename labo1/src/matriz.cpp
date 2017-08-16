#include "matriz.h"

/// Implementaciones de operaciones básicas de Matriz


using namespace std;

void mostrar(Matriz A, ostream & os) {
    for (const Fila & fi : A) {
        for (const double & n : fi)
            os << n << "\t";
        os << std::endl;
    }
}

ostream& operator<< (ostream& os, const Matriz& M) {
    mostrar(M,os);
    return os;
}

unsigned dim(Fila A) { return A.size(); }

unsigned filas(Matriz A) { return A.size(); }

unsigned columnas(Matriz A) { return dim(A[0]); }

Matriz crear_matriz(unsigned filas, unsigned columnas, double valor_default) {
    return Matriz(filas, Fila(columnas, valor_default) );
}

Fila crear_fila(unsigned dim, double valor_default) {
    return Fila(dim, valor_default);
}