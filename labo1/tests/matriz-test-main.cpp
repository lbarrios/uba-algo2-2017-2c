#include <iostream>
#include <matriz.h>

using namespace std;

bool test_suma() {
    cout << "Corriendo test_suma..." << endl;

    // Chequeo del resultado de sumar en una celda determinada
    if (suma({{1, 0},
              {0, 1}},
             {{1, 0},
              {0, 1}})[0][0] != 2) {
        cout << "ERROR: suma({{1,0},{0,1}}, {{1,0},{0,1}})[0][0] es distinto de 2" << endl;
        return false;
    }

    cout << "OK" << endl;
    return true;
}

bool test_producto_fila_columna() {
    cout << "Corriendo test_producto_fila_columna..." << endl;

    if (producto_fila_columna({1, 1, 1}, {{1},
                                          {1},
                                          {1}}, 0) != 3) {
        cout << "ERROR: producto_fila_columna({1,1,1},{{1},{1},{1}},0) es distinto de 3" << endl;
        return false;
    }

    cout << "OK" << endl;
    return true;
}

bool test_producto() {
    cout << "Corriendo test_producto..." << endl;
    // Chequeo del resultadeo de un producto de matrices en una celda determinada
    if (producto({{1, 0},
                  {0, 1}},
                 {{1, 0},
                  {0, 1}})[0][0] != 1) {
        cout << "ERROR: producto({{1,0},{0,1}},{{1,0},{0,1}})[0][0] es distinto de 1" << endl;
        return false;
    }

    // Producto de dos matrices que resultan en un escalar (matriz 1x1)
    if (producto({{1, 1, 1}}, {{1},
                               {1},
                               {1}})[0][0] != 3) {
        cout << "ERROR: producto({{1,1,1}},{{1},{1},{1}})[0][0] es distinto de 3" << endl;
        return false;
    }

    cout << "OK" << endl;
    return true;
}

bool test_sumar_filas_con_escalar() {
    cout << "Corriendo test_sumar_filas_con_escalar..." << endl;
    if (sumar_filas_con_escalar({1, 1, 1}, {2, 2, 2}, 2)[2] != 5) {
        cout << "ERROR: sumar_filas_con_escalar({1,1,1},{2,2,2},2)[2] es distinto de 5" << endl;
        return false;
    }

    cout << "OK" << endl;
    return true;
}

bool test_eliminacion_gaussiana() {
    cout << "test_eliminacion_gaussiana..." << endl;
    if (eliminacion_gaussiana({{1, 2, 0},
                               {1, 1, 1},
                               {0, 1, 0}}) != Matriz({{1, 2,  0},
                                                      {0, -1, 1},
                                                      {0, 0,  1}})) {
        cout << "ERROR: eliminacion_gaussiana({{1,2,0},\n"
                "                              {1,1,1},\n"
                "                              {0,1,0}}) es distinto de {{1,2,0}, {0,-1,1}, {0,0,1}}" << endl;
        return false;
    }

    cout << "OK" << endl;
    return true;
}

int main() {
    bool res = true;
    res = test_suma() && res;
    res = test_producto_fila_columna() && res;
    res = test_producto() && res;
    res = test_sumar_filas_con_escalar() && res;
    res = test_eliminacion_gaussiana() && res;
    return res ? 0 : -1;
}
