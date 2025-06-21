#include <iostream>
#include "Money.h"
using namespace std;

int main() {
    Money wallet1, wallet2;

    cout << "Enter wallet 1: " << endl;
    cin >> wallet1;            
    cout << "Wallet 1: " << wallet1 << endl;

    cout << "Enter wallet 2: "<< endl;
    cin >> wallet2;
    cout << "Wallet 2: " << wallet2 << endl << endl;

    Money ratio = wallet1 / wallet2;
    std::cout << "wallet1 / wallet2 = " << ratio << endl;

    cout << "wallet1 == wallet2? " << boolalpha << (wallet1 == wallet2) << endl;
    cout << "wallet1 < wallet2? " << boolalpha << (wallet1 < wallet2) << endl << endl;

    double div;
    cout << "Input divisor (double): ";
    cin >> div;
    Money res = wallet1 / div;
    cout << "wallet1 / " << div << " = " << res << endl;

    return 0;
}
