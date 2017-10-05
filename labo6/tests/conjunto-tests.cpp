#include <gtest/gtest.h>
#include "Conjunto.h"


/**
 * Test simple básico
 */
TEST(conjunto_test, conjunto_vacio) {
    Conjunto<int> c;
    EXPECT_EQ(c.cardinal(), 0);
}


TEST(conjunto_test, test_insertar_un_valor) {
    Conjunto<int> c;
    c.insertar(5);
    EXPECT_EQ(c.cardinal(), 1);
}

TEST(conjunto_test, test_insertar_remover_un_valor) {
    Conjunto<int> c;
    c.insertar(5);
    c.remover(5);
    EXPECT_EQ(c.cardinal(), 0);
    c.insertar(5);
    EXPECT_EQ(c.cardinal(), 1);
}

TEST(conjunto_test, test_insertar_cinco_valores) {
    Conjunto<int> c;
    c.insertar(5);
    c.insertar(4);
    c.insertar(7);
    c.insertar(6);
    c.insertar(8);
    EXPECT_EQ(c.cardinal(), 5);
}

TEST(conjunto_test, test_minimo) {
    Conjunto<int> c;
    c.insertar(5);
    c.insertar(4);
    c.insertar(7);
    c.insertar(6);
    c.insertar(8);
    EXPECT_EQ(c.minimo(), 4);
}

TEST(conjunto_test, test_maximo) {
    Conjunto<int> c;
    c.insertar(5);
    c.insertar(4);
    c.insertar(7);
    c.insertar(6);
    c.insertar(8);
    EXPECT_EQ(c.maximo(), 8);
}

TEST(conjunto_test, test_remover_caso_un_hijo) {
    Conjunto<int> c;
    c.insertar(5);
    c.insertar(6);
    c.insertar(7);
    c.remover(6);
    EXPECT_EQ(c.cardinal(), 2);
}

TEST(conjunto_test, test_remover_caso_dos_hijos_simple) {
    Conjunto<int> c;
    c.insertar(5);
    c.insertar(4);
    c.insertar(7);
    c.insertar(6);
    c.insertar(8);
    c.remover(7);
    EXPECT_EQ(c.cardinal(), 4);
}

TEST(conjunto_test, test_remover_caso_dos_hijos_doble) {
    Conjunto<int> c;
    c.insertar(5);
    c.insertar(4);
    c.insertar(20);
    c.insertar(15);
    c.insertar(12);
    c.insertar(16);
    c.insertar(24);
    c.insertar(22);
    c.insertar(25);
    c.remover(20);
    EXPECT_EQ(c.cardinal(), 8);
}

TEST(conjunto_test, test_siguiente_inorder) {
    Conjunto<int> c;
    c.insertar(5);
    c.insertar(4);
    c.insertar(20);
    c.insertar(15);
    c.insertar(12);
    c.insertar(16);
    c.insertar(24);
    c.insertar(22);
    c.insertar(25);

    EXPECT_EQ(c.siguiente(20), 22);
    EXPECT_EQ(c.siguiente(4), 5);
    EXPECT_EQ(c.siguiente(15), 16);
}

TEST(conjunto_test, igualdad) {
    Conjunto<int> c1, c2;
    c1.insertar(1);
    c1.insertar(2);
    c1.insertar(3);
    c1.insertar(4);
    c1.insertar(5);
    c2.insertar(3);
    c2.insertar(4);
    c2.insertar(5);
    c2.insertar(1);
    c2.insertar(2);
    EXPECT_EQ(c1,c2);
}

TEST(conjunto_test, desigualdad) {
    Conjunto<int> c1, c2;
    c1.insertar(1);
    c1.insertar(2);
    c1.insertar(3);
    c2.insertar(1);
    c2.insertar(3);
    EXPECT_NE(c1,c2);
}

TEST(conjunto_test, mostrar){
    Conjunto<int> c;
    c.insertar(3);
    c.insertar(7);
    c.insertar(2);
    c.insertar(6);
    c.insertar(4);
    c.insertar(8);
    c.insertar(9);
    stringstream ss;
    ss << c;
    EXPECT_EQ("Conjunto(3, 2, 7, 6, 4, 8, 9)", ss.str());
}
