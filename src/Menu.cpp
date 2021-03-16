#include "Menu.h"
#include <iostream>
#include <string>
#include <fstream>
#include "ChessTableMatrix.h"

using namespace std;

void Menu::listMenu(){
    int num;
    do{
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
    }while(selectedItem(num) != 0);
}

void readInpSource(){

}


void listMatrices(){

}

void storeMatrix(){

}


int Menu::selectedItem(int n){
    switch(n){
        case 0:
            exit(0);
            break;
        case 1:
            cout << "Use the inp.txt file as input source!";
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
