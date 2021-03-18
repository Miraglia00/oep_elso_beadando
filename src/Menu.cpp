#include "Menu.h"
#include <iostream>
#include <string>
#include <fstream>
#include "ChessTableMatrix.h"

using namespace std;

void Menu::listMenu(){
    int num;
    while(true){
        cout << "----------------------------" << endl;
        cout << "Chesstable Matrix Menu:" << endl;
        cout << "----------------------------" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Add new Chesstable Matrix" << endl;
        cout << "2. Select matrix from stored" << endl;
        cout << "3. Display stored matrices" << endl;
        cout << "-----(Selected index: "<<selected<<")-----" << endl;
        cout << "4. Display matrix" << endl;
        cout << "5. Display selected matrix value (i,j)" << endl;
        cout << "6. Selected matrix + another stored matrix" << endl;
        cout << "7. Selected matrix * scalar" << endl;
        cout << "8. Selected matrix * matrix" << endl;
        cout << "----------------------------" << endl;
        cout << "Choose from above: ";


        cin >> num;
        flush();
        selectedItem(num);
    }
}

void Menu::readInpSource(){
    int n = -1;
    int m = -1;
    do{
        cout << "Enter the row(m) and column(n) of the matrix separated by space: ";
        cin >> m >> n;
    }while(n == -1 && m == -1);

    ChessTableMatrix matrix(m,n);

    int max = matrix.getMax();
    cout << "Enter the numbers to be added to the matrix separated by spaces (Max element: "<< max <<"):";
    int num = 0;

    for(int i = 0; i < max; i++){
        cin >> num;
        matrix.add(num);
    }

    storeMatrix(matrix);
    selected = (int)(matrices.size()-1);
    cout << "Matrix saved and set as selected!";

    flush();

}

void Menu::listMatrices(){
    cout << "Listing stored matrices: " << endl;
    for(size_t i = 0; i < matrices.size(); i++){
        formatMatrix(matrices[i], i);

    }
}

void Menu::formatMatrix(ChessTableMatrix m, size_t ind){
    cout << endl << "*****************************" << endl;
    cout << "[" << ind << "] => Size(" << m.getR() << ", " << m.getC() << ")" << endl;
    m.displayMatrix();
    cout << endl << "*****************************" << endl;
}

void Menu::storeMatrix(ChessTableMatrix m){
    matrices.push_back(m);
}

int Menu::selectedItem(int n){
    switch(n){
        case 0:
            exit(0);
            break;
        case 1:
            readInpSource();
            cout << endl << endl;
            break;
        case 2:
            selectMatrix();
            cout << endl << endl;
            break;
        case 3:
            listMatrices();
            cout << endl << endl;
            break;
        case 4:
            displaySelectedMatrix();
            cout << endl << endl;
            break;
        case 5:
            displaySpecifiedValueOfMatrix();
            cout << endl << endl;
            break;
        case 6:
            addTwoMatrices();
            cout << endl << endl;
            break;
        case 7:
            multiplyMatrixByScalar();
            cout << endl << endl;
            break;
        case 8:
            multiplyMatrixByMatrix();
            cout << endl << endl;
            break;
        default:
            return false;
    }

    return false;
}

void Menu::flush(){
    cin.clear();
    fflush(stdin);
}

void Menu::selectMatrix(){
    if(matrices.size() == 0){
        cout << "No matrix added yet!";
    }else{
        cout << "Select an index to access to the stored matrix (0-"<<matrices.size()-1<<"): ";
        do{
            cin >> selected;
        }while(0 > selected && selected > (int)matrices.size()-1);
        flush();
    }
}

void Menu::displaySpecifiedValueOfMatrix(){
    cout << "Provide row and column to get the value from matrix: ";
    try{
        int i,j;
        cin >> i >> j;
        cout << "("<<i<<", "<<j<<") => " << matrices[selected].getValue(i,j);

    }catch(char const* e){
        cout << e << endl;
    }
}

void Menu::addTwoMatrices(){
    if(matrices.size() < 2){
        cout << "Not enough matrix stored!";
        return;
    }
    if(matrices.size() == 0){
        cout << "No matrix added yet!";
        return;
    }

    cout << "Provide an index for the second matrix. Also the outcome will be saved as a separate one: ";
    int otherind = -1;
    do{
        cin >> otherind;
        flush();
    }while(0 > otherind && otherind > (int)matrices.size()-1);

    try{
        ChessTableMatrix outcome = matrices[selected]+matrices[otherind];
        storeMatrix(outcome);
        formatMatrix(outcome, matrices.size()-1);

    }catch(char const* e){
        cout << e << endl;
    }
}

void Menu::multiplyMatrixByScalar(){
    if(matrices.size() == 0){
        cout << "No matrix added yet!";
        return;
    }
    cout << "Provide a scalar!" << endl << "Also the outcome will be saved as a separate one: ";

    int sc;

    cin >> sc;

    flush();

    try{
        ChessTableMatrix outcome = matrices[selected] * sc;

        storeMatrix(outcome);

        formatMatrix(outcome, matrices.size()-1);

    }catch(char const* e){
        cout << e << endl;
    }
}

void Menu::multiplyMatrixByMatrix(){
    if(matrices.size() == 0){
        cout << "No matrix added yet!";
        return;
    }
    if(matrices.size() < 2){
        cout << "Not enough matrix stored!";
        return;
    }
    cout << "Provide an index for the second matrix. Also the outcome will be saved as a separate one: ";
    int otherind = -1;
    do{
        cin >> otherind;
        flush();
    }while(0 > otherind && otherind > (int)matrices.size()-1);

    try{
        ChessTableMatrix outcome = matrices[selected]*matrices[otherind];
        storeMatrix(outcome);
        formatMatrix(outcome, matrices.size()-1);

    }catch(char const* e){
        cout << e << endl;
    }
}

void Menu::displaySelectedMatrix(){
    if(matrices.size() == 0){
        cout << "No matrix added yet!";
        return;
    }
    formatMatrix(matrices[selected], selected);
}

Menu::Menu()
{
}

Menu::~Menu()
{
}
