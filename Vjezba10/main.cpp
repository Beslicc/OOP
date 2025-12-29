#include <iostream>
#include <cstdlib>
using namespace std;

// Deklaracije funkcija
void zadatak1();
void zadatak2();
void zadatak3();

int main() {
    cout << "  VJEŽBA 10 - STL algoritmi i namespace  " << endl;
    cout << "==========================================" << endl << endl;

    int izbor;

    do {
        cout << "\nOdaberite zadatak:" << endl;
        cout << "1. Prirodni brojevi (STL algoritmi)" << endl;
        cout << "2. Tocke (namespace math_utils)" << endl;
        cout << "3. Studenti (Map-Filter-Reduce)" << endl;
        cout << "0. Izlaz" << endl;
        cout << "Vas izbor: ";
        cin >> izbor;

        switch (izbor) {
        case 1:
            zadatak1();
            break;
        case 2:
            zadatak2();
            break;
        case 3:
            zadatak3();
            break;
        case 0:
            cout << "Hvala i doviðenja!" << endl;
            break;
        default:
            cout << "Nevažeæi izbor!" << endl;
        }

    } while (izbor != 0);

    return 0;
}