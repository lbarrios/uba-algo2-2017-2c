#include <matriz.h>
#include <gtest/gtest.h>

using namespace std;

TEST(matriz_test, test_suma) {
    EXPECT_EQ(suma({{1,0},{0,1}}, {{1,0},{0,1}})[0][0], 2);
}

TEST(matriz_test, test_producto_fila_columna) {
    Fila R = {1,1,1};
    // vector columna
    Matriz C = {{1},{1},{1}};
    EXPECT_EQ(producto_fila_columna(R,C,0), 3);
}

TEST(matriz_test, test_producto) {
    Matriz A = producto({{1,0},{0,1}},
                        {{1,0},{0,1}});
    EXPECT_EQ(A[0][0], 1);

    Matriz R = {{1,1,1}};
    // vector columna
    Matriz C = {{1},{1},{1}};
    EXPECT_EQ(producto(R,C)[0][0], 3);
}

TEST(matriz_test, test_sumar_filas_con_escalar) {
    Fila R = {1,1,1}, S = {2,2,2};
    Fila T = sumar_filas_con_escalar(R, S, 2);
    EXPECT_EQ(T[2], 5);
}

TEST(matriz_test, test_eliminacion_gaussiana) {
    Matriz A = {{1, 2, 0},
                {1, 1, 1},
                {0, 1, 0}},
           B = {{1, 2,  0},
                {0, -1, 1},
                {0, 0,  1}};
    EXPECT_EQ(eliminacion_gaussiana(A), B);
}
