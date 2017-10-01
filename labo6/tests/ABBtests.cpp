#include <gtest/gtest.h>
#include "ABB.h"

/**
 * Test de constructor
 */
TEST(abb_test, constructor) {
    ABB<int> abb;
    EXPECT_EQ(abb.cantidad(), 0);
}

TEST(abb_test, agregar_suma_cantidad) {
    /**
     * Cada vez que agrego un elemento
     * se suma uno a la cantidad del arbol
     */
    ABB<int> abb;
    abb.insertar(5);
    EXPECT_EQ(abb.cantidad(), 1);
    abb.insertar(5);
    EXPECT_EQ(abb.cantidad(), 2);
    abb.insertar(8);
    EXPECT_EQ(abb.cantidad(), 3);
}

TEST(abb_test, agregar_no_pisa_raiz) {
    /**
     * Al agregar un elemento menor o mayor a un arbol con un elemento
     * este elemento no pisa la raíz
     */
    ABB<int> abb1(5), abb2(5);
    abb1.insertar(4); // Agrego por izquierda
    abb2.insertar(6); // Agrego por derecha
    EXPECT_EQ(abb1.raiz(), 5);
    EXPECT_EQ(abb2.raiz(), 5);
}

TEST(abb_test, agregar_elemento_derecha) {
    /**
     * Al agregar un elemento mayor a un arbol con un elemento
     * este pasa a esar en el subarbol derecho
     */
    ABB<int> abb(5);
    abb.insertar(6);
    EXPECT_FALSE(abb.tieneSubarbolIzquierdo());
    EXPECT_TRUE(abb.tieneSubarbolDerecho());
    EXPECT_EQ(abb.subarbolDerecho().raiz(), 6);
}

TEST(abb_test, agregar_elemento_izquierda) {
    /**
     * Al agregar un elemento menor a un arbol con un elemento
     * este pasa a esar en el subarbol izquierdo
     */
    ABB<int> abb(5);
    abb.insertar(4);
    EXPECT_TRUE(abb.tieneSubarbolIzquierdo());
    EXPECT_FALSE(abb.tieneSubarbolDerecho());
    EXPECT_EQ(abb.subarbolIzquierdo().raiz(), 4);
}

TEST(abb_test, agregar_agrega_ese_elemento) {
    /**
     * Al agregar elementos, estos pasan a estar en el arbol
     * o en el subarbol izquierdo/derecho correspondiente
     */
    ABB<int> abb(5);
    int elem2 = 6, elem3 = 4;
    abb.insertar(elem2);
    EXPECT_FALSE(abb.tieneSubarbolIzquierdo());
    EXPECT_TRUE(abb.tieneSubarbolDerecho());
    abb.insertar(elem3);
    EXPECT_TRUE(abb.tieneSubarbolIzquierdo());
    EXPECT_TRUE(abb.tieneSubarbolDerecho());
    EXPECT_EQ(abb.subarbolIzquierdo().raiz(), 4);
    EXPECT_EQ(abb.subarbolDerecho().raiz(), 6);
}

TEST(abb_test, agregar_elemento_hace_que_exista) {
    ABB<int> abb;
    EXPECT_FALSE(abb.existe(5));
    abb.insertar(5);
    EXPECT_TRUE(abb.existe(5));
}

TEST(abb_test, agregar_muchos_elementos_hace_que_existan) {
    ABB<int> abb;
    for (int i = 0; i <= 10; i++) {
        abb.insertar(i);
    }
    for (int i = 10; i >= 0; i--) {
        abb.existe(i);
    }
}

TEST(abb_test, agregar_elemento_aumenta_altura) {
    ABB<int> abb;
    EXPECT_EQ(abb.altura(),0);
    abb.insertar(5);
    EXPECT_EQ(abb.altura(),1);
}

TEST(abb_test, agregar_solo_derecha_aumenta_la_altura_por_cada_elemento) {
    ABB<int> abb(5);
    EXPECT_EQ(abb.altura(),1);
    abb.insertar(6);
    EXPECT_EQ(abb.altura(),2);
    abb.insertar(7);
    EXPECT_EQ(abb.altura(),3);
}

TEST(abb_test, agregar_solo_izquierda_aumenta_la_altura_por_cada_elemento) {
    ABB<int> abb(5);
    EXPECT_EQ(abb.altura(),1);
    abb.insertar(4);
    EXPECT_EQ(abb.altura(),2);
    abb.insertar(3);
    EXPECT_EQ(abb.altura(),3);
}

TEST(abb_test, agregar_a_izquierda_y_derecha_aumenta_altura_en_uno) {
    ABB<int> abb(5);
    EXPECT_EQ(abb.altura(),1);
    abb.insertar(3);
    abb.insertar(7);
    EXPECT_EQ(abb.altura(),2);
    abb.insertar(4);
    abb.insertar(2);
    abb.insertar(6);
    abb.insertar(8);
    EXPECT_EQ(abb.altura(),3);
}