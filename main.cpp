#include <iostream>
#include "ChessTableMatrix.h"
#include "Menu.h"

#define NORMAL_MODE
#ifdef NORMAL_MODE

/*Valósítsa meg az egész számokat tartalmazó „sakktábla” mátrixtípust. Ezen m×n-es mátrixok
soraiban biztosan nulla értékû minden második elem. A „nem-nulla” értékek sakktábla-szerûen
helyezkednek el az [1,1], [1,3], ... , [2,2], [2,4], ... indexû helyeken. A típus reprezentációjában
csak ezeket a „nem-nulla” értékû elemeket kell eltárolnunk. (Az [1,2], [1,4], ... , [2,1], [2,3], ...
indexû helyeken levõ biztosan nulla értékû elemeket nem tároljuk.) Implementálja önálló
metódusként a mátrix i-edik sorának j-edik elemét visszaadó mûveletet, valamint az összeadás
és szorzás mûveleteket, továbbá a mátrix m×n alakban történõ kiírását!*/

using namespace std;

int main()
{
    Menu menu;
    menu.listMenu();

    return 0;
}

#else

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "ChessTableMatrix.h"

TEST_CASE("ChessTableMatrix()", "[ChessTableMatrix]"){
    ChessTableMatrix m(0,0);

    ChessTableMatrix m1(1,1);

    ChessTableMatrix m2(3,7);
}
TEST_CASE("add()", "[ChessTableMatrix]"){
    ChessTableMatrix m(2,2);
    m.add(1);
    m.add(2);

    CHECK(m.getNonZeroItems().size() == m.getMax());

    ChessTableMatrix m1(3,3);
    m1.add(1);
    m1.add(2);
    m1.add(3);
    m1.add(4);
    m1.add(5);
    m1.add(6);
    //More element added
    CHECK(m1.getNonZeroItems().size() == m1.getMax());
}

TEST_CASE("getMax()", "[ChessTableMatrix]"){
    ChessTableMatrix m(2,2);
    CHECK(2 == m.getMax());

    ChessTableMatrix m1(2,3);
    CHECK(3 == m1.getMax());

    ChessTableMatrix m2(5,3);
    //max element should be 8 with this dimension
    CHECK(9 == m2.getMax());
}

TEST_CASE("getValue(i,j)", "[ChessTableMatrix]"){
    ChessTableMatrix m(2,2);
    m.add(2);
    m.add(3);
    CHECK(2 == m.getValue(1,1));
    CHECK(0 == m.getValue(1,2));
    //Should return 3
    CHECK(5 == m.getValue(2,2));

    CHECK(m.getValue(3,3));
}
#endif
