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

        void storeMatrix();

    protected:

    private:
        vector<ChessTableMatrix> matrices;
};

#endif // MENU_H
