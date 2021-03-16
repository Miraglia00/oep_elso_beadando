#include <iostream>
#include "ChessTableMatrix.h"
/*Val�s�tsa meg az eg�sz sz�mokat tartalmaz� �sakkt�bla� m�trixt�pust. Ezen m�n-es m�trixok
soraiban biztosan nulla �rt�k� minden m�sodik elem. A �nem-nulla� �rt�kek sakkt�bla-szer�en
helyezkednek el az [1,1], [1,3], ... , [2,2], [2,4], ... index� helyeken. A t�pus reprezent�ci�j�ban
csak ezeket a �nem-nulla� �rt�k� elemeket kell elt�rolnunk. (Az [1,2], [1,4], ... , [2,1], [2,3], ...
index� helyeken lev� biztosan nulla �rt�k� elemeket nem t�roljuk.) Implement�lja �n�ll�
met�dusk�nt a m�trix i-edik sor�nak j-edik elem�t visszaad� m�veletet, valamint az �sszead�s
�s szorz�s m�veleteket, tov�bb� a m�trix m�n alakban t�rt�n� ki�r�s�t!*/

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
