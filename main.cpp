#include <iostream>
#include "ChessTableMatrix.h"
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
    ChessTableMatrix matrix(2,2);
    matrix.add(1);
    matrix.add(2);

    ChessTableMatrix masik(2,2);
    masik.add(6);
    masik.add(7);

    ChessTableMatrix osszeg = matrix+masik;
    ChessTableMatrix szorzat = matrix*masik;

    matrix.displayMatrix();
    cout<<endl<<"=============================="<<endl;
    masik.displayMatrix();
    cout<<endl<<"===========OSSZEGUK==========="<<endl;
    osszeg.displayMatrix();
    cout<<endl<<"============SZORZATUK========="<<endl;
    szorzat.displayMatrix();
    return 0;
}
