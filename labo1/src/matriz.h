#ifndef MATRIZ_H
#define MATRIZ_H

#include <vector>
#include <ostream>

typedef std::vector<double> Fila;
typedef std::vector<Fila> Matriz;

// Ejemplos de matrices escritas de manera literal
//
//    Fila f1 = {1,2,3,4};
//
//    Matriz M = {
//        { 1, 1 ,1 },
//        { 0, 2, 1 },
//        { 1, 0 ,1 } };
//
//    Matriz vector columna
//    Matriz N = {
//        { 1, },
//        { 0, },
//        { 0, } },
//
//    Matriz I = { {1, 0, 1},
//              {0, 1, 0},
//              {0, 0, 1}};

// observadores de fila y matriz
/// Observa la dimensión de A
/// @param A vector fila
/// @returns dimensión N del vector
unsigned dim(Fila A);

/// Devuelve la cantidad de filas de una matriz
/// @param A matriz de NxM
/// @returns N
unsigned filas(Matriz A);

/// Devuelve la cantidad de columnas de una matriz
/// @param A matriz de NxM
/// @returns M
unsigned columnas(Matriz A);

/// Generador de filas
/// @param dim
/// @param valor_default
/// @returns Una fila de dimension "dim" y "valor_default" en todas sus posiciones
Fila crear_fila(unsigned dim, double valor_default = 0.0);

// generador de matriz
/// Crea una matriz de N filas por M columnas
/// @param filas parámetro N
/// @param columnas parámetro M
/// @returns una nueva matriz, por copia
Matriz crear_matriz(unsigned filas, unsigned columnas, double valor_default = 0.0);

///
/// @brief suma dos matrices A y B de la misma dimensión
/// @param A matriz de N x N
/// @param B matriz de N x N
/// @returns C matriz de N x N, C = A + B
Matriz suma(Matriz A, Matriz B);

/// @brief multiplica dos matrices A y B de dimensión compatible
/// @param A matriz de N x M
/// @param B matriz de M x K
/// @returns C matriz de N x K, C = A * B
Matriz producto(Matriz A, Matriz B);

/// @brief Producto escalar entre A y columna "co" de B
/// @param A Vector fila de dimensión N a multiplicar
/// @param B Matriz de N filas x M columnas
/// @param co indice de 0 a M-1 de una columna de B
/// @returns A[0]*B[0][co] + A[1]*B[1][co] + ... + A[N-1]*B[N-1][co]
double producto_fila_columna(Fila A, Matriz B, int co);

/// @brief Suma de fila mas fila multiplicada por escalar
/// @param A fila de dimensión N
/// @param B fila de dimensión N
/// @param e multiplicador aplicado a B
/// @returns fila igual a (A + e*B)
Fila sumar_filas_con_escalar(Fila A, Fila B, double e);

//
/// @brief Triangula la matriz A de NxN, si es diagonalizable
/// @param A matriz de NxN
/// @returns nueva matriz resultante de hacer eliminación gaussiana en A
Matriz eliminacion_gaussiana(Matriz A);

/// @brief escribe matriz en formato texto
/// @param A matriz a imprimir
/// @param os flujo genérico de salida
void mostrar(Matriz A, std::ostream & os);

// operator << de matriz
std::ostream& operator<< (std::ostream& os, const Matriz& M);

#endif // MATRIZ_H
