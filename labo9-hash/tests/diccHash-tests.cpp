#include <gtest/gtest.h>
#include "DiccHash.h"
#include <iostream>
#include <fstream>

using namespace std;

#define TAM_TABLA_INI 100
#define UMBRAL_FC	  0.75


using namespace std;

TEST(DiccHash, Vacio) {
    DiccHash<int> dicc;
    ASSERT_EQ( dicc.CantClaves(), 0);
}


TEST(DiccHash, Definido) {
    DiccHash<int> dicc;

    ASSERT_FALSE(dicc.Definido(""));
    ASSERT_FALSE(dicc.Definido(" ") );
    ASSERT_FALSE(dicc.Definido("hola") );

    dicc.Definir("hola", 100);
    ASSERT_TRUE(dicc.Definido("hola") );
    ASSERT_FALSE(dicc.Definido("holas") );
    ASSERT_FALSE(dicc.Definido("hol") );
    ASSERT_EQ( dicc.CantClaves(), 1);
}


TEST(DiccHash, Definir) {
    DiccHash<char> dicc;
    ASSERT_FALSE(dicc.Definido(""));

    dicc.Definir("a",'a');
    dicc.Definir("ab",'a');

    ASSERT_FALSE(dicc.Definido(""));
    ASSERT_TRUE(dicc.Definido("a"));
    ASSERT_TRUE(dicc.Definido("ab"));
    ASSERT_FALSE(dicc.Definido("abc"));
    ASSERT_FALSE(dicc.Definido("ab "));
    ASSERT_FALSE(dicc.Definido(" ab"));
    ASSERT_EQ( dicc.CantClaves(), 2);
}



TEST(DiccHash, StringVacio) {
    DiccHash<char> dicc;
    ASSERT_FALSE(dicc.Definido(""));

    dicc.Definir("",'a');
    ASSERT_TRUE(dicc.Definido(""));
    ASSERT_FALSE(dicc.Definido(" "));

    ASSERT_TRUE(dicc.Significado("") == 'a');

    dicc.Borrar("");
    ASSERT_FALSE(dicc.Definido(""));
}

TEST(DiccHash, Significado) {
    DiccHash<char> dicc;
    ASSERT_FALSE(dicc.Definido("a"));

    dicc.Definir("a",'a');
    dicc.Definir("ab",'a');

    ASSERT_TRUE( dicc.Significado("a") == 'a');
    ASSERT_TRUE( dicc.Significado("a") != 'b');
}


TEST(DiccHash, Borrar) {
    DiccHash<int> dicc;

    dicc.Definir("juanca",40);
    dicc.Definir("moncho",38);

    ASSERT_TRUE( dicc.Definido("juanca") );
    ASSERT_TRUE( dicc.Definido("moncho")  );

    dicc.Borrar("juanca");
    ASSERT_FALSE(dicc.Definido("juanca") );
    dicc.Borrar("moncho");
    ASSERT_FALSE(dicc.Definido("moncho") );
}



TEST(DiccHash, CantClaves) {
    DiccHash<int> dhi;
    ASSERT_EQ( dhi.CantClaves(), 0);

    dhi.Definir("juanca",40);
    dhi.Definir("moncho",38);
    ASSERT_EQ( dhi.CantClaves(), 2 );

    dhi.Definir("moncho",56);
    ASSERT_EQ( dhi.CantClaves(), 2);

    dhi.Borrar("juanca");
    ASSERT_EQ( dhi.CantClaves(), 1);

    dhi.Borrar("moncho");
    ASSERT_EQ( dhi.CantClaves(), 0);
}




TEST(DiccHash, Claves) {
    DiccHash<int> dhi;
    set<string> claves;

    claves = dhi.Claves();
    ASSERT_EQ( dhi.CantClaves(), 0);

    dhi.Definir("juanca",40);
    dhi.Definir("moncho",38);

    claves = dhi.Claves();
    ASSERT_EQ( dhi.CantClaves(), 2);

    set<string> conj_claves = {"juanca","moncho"};
    ASSERT_EQ( dhi.Claves(), conj_claves);

    set<string> conj_claves2 = {"juanca","moncho",""};
    ASSERT_NE( dhi.Claves(), conj_claves2);

    set<string> conj_claves3 = {"juanca"};
    ASSERT_NE( dhi.Claves(), conj_claves3);

    set<string> conj_claves4 = {"moncho"};
    dhi.Borrar("juanca");
    claves = dhi.Claves();
    ASSERT_EQ( dhi.CantClaves(), 1);
    ASSERT_EQ( dhi.Claves(), conj_claves4);
    ASSERT_NE( dhi.Claves(), conj_claves3);

    dhi.Borrar("moncho");
    claves = dhi.Claves();
    ASSERT_EQ( dhi.CantClaves(), 0);
    ASSERT_NE( dhi.Claves(), conj_claves4);
    ASSERT_NE( dhi.Claves(), conj_claves3);
}




TEST(DiccHash, Colisiones_Unif) {
    //Lee las datos del archivo y los define en el diccionario
    DiccHash<int> dh;

    char delim = '\n';
    std::string archnom = "../data/uniforme.txt";

    int val = 0;
    string str;

    ifstream archin(archnom.c_str());
    ASSERT_TRUE(archin.good());

    while(getline(archin,str,delim) && archin.good()) {
        dh.Definir(str, val);
        val++;

        if (val == 50)
            break;
    }
    archin.close();

    ASSERT_EQ(dh.CantClaves(),val);

    //Si no pasa este chequeo significa que tienen muchas colisiones; por lo cual, deberían reformular la función de hash.
    ASSERT_TRUE(dh.colisiones() < 20);
}



TEST(DiccHash, Colisiones_Gauss) {
    //Lee las datos del archivo y los define en el diccionario
    DiccHash<int> dh;

    char delim = '\n';
    std::string archnom = "../data/gauss.txt";

    int val = 0;
    string str;

    ifstream archin(archnom.c_str());
    ASSERT_TRUE(archin.good());

    while(getline(archin,str,delim) && archin.good()) {
        dh.Definir(str, val);
        val++;

        if (val == 50)
            break;
    }
    archin.close();


    ASSERT_EQ(dh.CantClaves(),val);

    //Si no pasa este chequeo significa que tienen muchas colisiones; por lo cual, deberían reformular la función de hash.
    ASSERT_TRUE(dh.colisiones() < 30);
}

TEST(DiccHash, Colisiones_libretas) {
    //Lee las datos del archivo y los define en el diccionario
    DiccHash<int> dh;

    char delim = '\n';
    std::string archnom = "../data/libretas.txt";

    int val = 0;
    string str;

    ifstream archin(archnom.c_str());
    ASSERT_TRUE(archin.good());

    while(getline(archin,str,delim) && archin.good()) {
        dh.Definir(str, val);
        val++;

        if (val == 50)
            break;
    }
    archin.close();

    ASSERT_EQ(dh.CantClaves(), val);

    //Si no pasa este chequeo significa que tienen muchas colisiones; por lo cual, deberían reformular la función de hash.
    ASSERT_TRUE(dh.colisiones() < 26);
}



TEST(DiccHash, Redimensionado) {
    DiccHash<int> dh;

    char delim = '\n';
    std::string archnom = "../data/uniforme.txt";

    unsigned int val = 0;
    string str;

    ifstream archin(archnom.c_str());
    ASSERT_TRUE(archin.good());

    while(getline(archin,str,delim) && archin.good()) {
        dh.Definir(str, val);
        val++;
    }
    archin.close();

    ASSERT_EQ(dh.CantClaves(),val);

    int eval = 0;
    archin.open(archnom.c_str());
    while(getline(archin,str) && archin.good()) {
        ASSERT_TRUE(dh.Definido(str));
        ASSERT_EQ(dh.Significado(str),eval);
        eval++;
    }
    archin.close();

    ASSERT_EQ(eval,val);

    ASSERT_LE(dh.factorCarga(), UMBRAL_FC);
}



