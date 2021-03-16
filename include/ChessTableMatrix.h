#ifndef CHESSTABLEMATRIX_H
#define CHESSTABLEMATRIX_H

#include <vector>
using namespace std;


class ChessTableMatrix
{
    public:
        enum ChessTableMatrixError{
            FULL_MATRIX,
            NOT_FULL_MATRIX,
            INVALID_DIMENSION,
        };

        int m = 0, n = 0;

        void add(int a);

        int getMax() const;

        void displayMatrix();

        int getValue(int i, int j);

        vector<int> getNonZeroItems();

        vector<int> getFullMatrix();

        ChessTableMatrix operator+(ChessTableMatrix m1);

        ChessTableMatrix operator*(ChessTableMatrix m1);

        ChessTableMatrix(int dim_m, int dim_n);
        virtual ~ChessTableMatrix();

    protected:

    private:
        vector<int> matrix;
        int realSize;
};

#endif // CHESSTABLEMATRIX_H
