#include "Menu.h"
#include <iostream>
#include <string>
#include <fstream>
#include "ChessTableMatrix.h"

using namespace std;

void Menu::listMenu(){
    int num;
    while(true){
        cout << "------------------------------" << endl;
        cout << "Chesstable Matrix Menu:" << endl << "------------------------------" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Add new Chesstable Matrix" << endl;
        cout << "2. Display specified matrix value" << endl;
        cout << "3. Add matrix" << endl;
        cout << "4. Multiply matrix" << endl;
        cout << "5. Display matrix" << endl;
        cout << "6. Display stored matrices" << endl << "------------------------------" << endl;
        cout << "Choose from above: ";


        cin >> num;
        selectedItem(num);
    }
}

void Menu::readInpSource(){
    fstream file;
    file.open("inp.txt");
    if(file.fail()){
        cout << "Wrong file name!" << endl;
    }

    int n = 0;
    int m = 0;

    file >> n >> m;

    if(n == 0 || m == 0){
        cout << "Dimensions must be bigger than 0, edit the file and try again!";
    }else{
        ChessTableMatrix matrix(n,m);
        int val = false;
        for(int i = 0; i < matrix.getMax(); i++){

            file >> val;
            cout << val;
        }
    }
}


void Menu::listMatrices(){

}

void Menu::storeMatrix(){

}


int Menu::selectedItem(int n){
    switch(n){
        case 0:
            exit(0);
            break;
        case 1:
            cout << "Use the inp.txt file as input source!" << endl;
            readInpSource();
            cout << endl << endl;
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            return false;
    }
}

Menu::Menu()
{
}

Menu::~Menu()
{
}
