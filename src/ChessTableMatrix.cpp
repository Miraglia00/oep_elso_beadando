#include "ChessTableMatrix.h"
#include <iostream>
#include <math.h>

void ChessTableMatrix::add(int a) {
    if(matrix.size() <= (unsigned int)getMax()) {
        matrix.push_back(a);
    }else{
        throw FULL_MATRIX;
    }
}

int ChessTableMatrix::getMax() const {
    return std::ceil((this->m * this->n) / 2.0);
}

void ChessTableMatrix::displayMatrix(){
    if((unsigned int)getMax() != matrix.size()) { throw NOT_FULL_MATRIX; }
    vector<int> fullMatrix = getFullMatrix();

    for(int i= 0; i < realSize; i++){
        if(i % n == 0 && i != 0) {
            std::cout << endl;
        }
        std::cout << fullMatrix[i] << " ";
    }
}

int ChessTableMatrix::getValue(int i, int j){
    if((unsigned int)getMax() != matrix.size()) { throw NOT_FULL_MATRIX; }
    if((i * j) > (m * n)) { throw INVALID_DIMENSION; }
    vector<int> fullMatrix = getFullMatrix();
    return fullMatrix[(m * (i-1)) + j-1];
}

vector<int> ChessTableMatrix::getNonZeroItems(){
    vector<int> items;
    for(size_t i = 0; i < matrix.size(); ++i){
        items.push_back(matrix[i]);
    }
    return items;
}

vector<int> ChessTableMatrix::getFullMatrix() {
    vector<int> fullMatrix;
    for(int i = 0; i < (m*n); ++i){
        if(m == n){
            int fordit = false;
            if(fullMatrix.size() % m == 0 && fullMatrix.size() != 0){
                fordit = !fordit;
            }
            if(fordit){
                fullMatrix.push_back(0);
                fullMatrix.push_back(matrix[i]);
            }else{
                fullMatrix.push_back(matrix[i]);
                fullMatrix.push_back(0);
            }
        }else{
            fullMatrix.push_back(matrix[i]);
            fullMatrix.push_back(0);
        }
    }
    return fullMatrix;

}

ChessTableMatrix ChessTableMatrix::operator+(ChessTableMatrix m1){
    if(m1.m != m || m1.n != n) { throw INVALID_DIMENSION; }
    ChessTableMatrix newMatrix(m,n);
    vector<int> items = getNonZeroItems();
    vector<int> items1 = m1.getNonZeroItems();

    for(size_t i = 0; i < matrix.size(); i++){
        newMatrix.add(items[i]+items1[i]);
    }
    return newMatrix;
}

ChessTableMatrix ChessTableMatrix::operator*(ChessTableMatrix m1){
    if(m1.m != n) { throw INVALID_DIMENSION; }
    ChessTableMatrix newMatrix(m,m1.n);
    vector<int> items = getFullMatrix();
    vector<int> items1 = m1.getFullMatrix();
    int szorzat = 0;

    for(int i = 0; i < m; i++){
        for(int u = 0; u < m1.n; ++u){
            for(int y = 0; y < n; ++y){
                 szorzat += items[(i!=0)?i*m+y:i+y]*items1[u+(m1.n*y)];
            }
            if(szorzat != 0) {
                newMatrix.add(szorzat);
                szorzat = 0;
            }
        }
    }

    return newMatrix;
}

ChessTableMatrix::ChessTableMatrix(int dim_m, int dim_n)
{
    m = dim_m;
    n = dim_n;
    realSize = m * n;
}

ChessTableMatrix::~ChessTableMatrix()
{
    //dtor
}
