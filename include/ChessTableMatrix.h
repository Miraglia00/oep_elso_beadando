#ifndef CHESSTABLEMATRIX_H
#define CHESSTABLEMATRIX_H

#include <vector>
using namespace std;


class ChessTableMatrix
{
    public:

        void add(int a);

        int getMax() const;

        void displayMatrix();

        int getValue(int i, int j);

        vector<int> getNonZeroItems();

        vector<int> getFullMatrix();

        ChessTableMatrix operator+(ChessTableMatrix m1);

        ChessTableMatrix operator*(ChessTableMatrix m1);

        ChessTableMatrix operator*(int num);

        ChessTableMatrix(int dim_m, int dim_n);

        int getR() const;
        int getC() const;

        virtual ~ChessTableMatrix();

    protected:

    private:
        int m = 0, n = 0;
        vector<int> matrix;
        int realSize;
};

#endif // CHESSTABLEMATRIX_H
