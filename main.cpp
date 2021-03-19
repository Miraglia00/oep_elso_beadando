#include <iostream>
#include "ChessTableMatrix.h"
#include "Menu.h"

#define NORMAL_MODE
#ifdef NORMAL_MODE

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
    CHECK_THROWS(ChessTableMatrix m(0,0));

    CHECK_NOTHROW(ChessTableMatrix m1(1,1));

    CHECK_NOTHROW(ChessTableMatrix m2(3,7));
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
    CHECK(m1.getNonZeroItems().size() != m1.getMax());
}

TEST_CASE("getMax()", "[ChessTableMatrix]"){
    ChessTableMatrix m(2,2);
    CHECK(2 == m.getMax());

    ChessTableMatrix m1(2,3);
    CHECK(3 == m1.getMax());

    ChessTableMatrix m2(5,3);
    //max element should be 8 with this dimension
    CHECK(9 != m2.getMax());
}

TEST_CASE("getValue(i,j)", "[ChessTableMatrix]"){
    ChessTableMatrix m(2,2);
    m.add(2);
    m.add(3);
    CHECK(2 == m.getValue(1,1));
    CHECK(0 == m.getValue(1,2));
    //Should return 3
    CHECK(5 != m.getValue(2,2));

    CHECK_THROWS(m.getValue(3,3));
}
#endif
