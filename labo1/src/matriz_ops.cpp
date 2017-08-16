#include "matriz.h"

// implementacion de operaciones aritméticas de Matriz

Matriz suma(Matriz A, Matriz B) {
    Matriz C = crear_matriz(filas(A),columnas(A));
    for (int fi=0; fi < A.size(); fi++) {
        for (int co = 0; co < A.size(); co++) {
            C[fi][co] += A[fi][co] + B[fi][co];
        }
    }
    return C;
}

Matriz producto(Matriz A, Matriz B) {
    Matriz C = crear_matriz(filas(A), columnas(B));
    for (int fi=0; fi < filas(A); fi++) {
        for (int co = 0; co < columnas(B); co++) {
            C[fi][co] += producto_fila_columna(A[fi], B, co);
        }
    }
    return C;
}

double producto_fila_columna(Fila A, Matriz B, int co) {
    double d = 0;
    for (int i = 0; i < dim(A); ++i) {
        d += A[i] * B[i][co];
    }
    return d;
}

// Triangula la matriz A, si es diagonalizable
Matriz eliminacion_gaussiana(Matriz A) {
        Matriz C = A;
        for (int i = 0; i < filas(A); ++i) {
            for (int j = i + 1; j < filas(A); ++j) {
                if (C[j][i] != 0.0) {
                    C[j] = sumar_filas_con_escalar(C[j], C[i], -C[i][i] / C[j][i]);
                }
            }
        }
        return C;
}

Fila sumar_filas_con_escalar(Fila A, Fila B, double e) {
    Fila res = crear_fila(dim(A));
    for (int i=0; i < dim(A); ++i) {
        res[i] = A[i] + B[i] * e;
    }
    return res;
}
