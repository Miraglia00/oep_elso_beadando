#ifndef MENU_H
#define MENU_H

#include "ChessTableMatrix.h"


class Menu
{
    public:

        Menu();
        virtual ~Menu();

        void listMenu();

        int selectedItem(int n);

        void readInpSource();

        void listMatrices();

        void storeMatrix(ChessTableMatrix m);

        void flush();

        void displaySelectedMatrix();

        void selectMatrix();

        void displaySpecifiedValueOfMatrix();

        void addTwoMatrices();

        void formatMatrix(ChessTableMatrix m, size_t ind);

        void multiplyMatrixByScalar();

        void multiplyMatrixByMatrix();
    protected:

    private:
        int selected = -1;
        vector<ChessTableMatrix> matrices;
};

#endif // MENU_H
