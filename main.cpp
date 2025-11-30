#include "container.h"
#include <iostream>

using namespace std;

void obradiContainer(Container c) {
    cout << "U funkciji: ";
    c.print();
}

Container kreirajContainer() {
    Container temp(2);
    temp.push_back(100);
    temp.push_back(200);
    return temp;
}

int main() {
    cout << "1. Kreiranje containera" << endl;
    Container c1;
    c1.push_back(1);
    c1.push_back(2);
    c1.push_back(3);
    c1.print();

    cout << "\n2. Copy konstruktor" << endl;
    Container c2 = c1;
    c2.print();

    cout << "\n3. Move konstruktor" << endl;
    Container c3 = move(c1);
    cout << "c3: ";
    c3.print();
    cout << "c1: ";
    c1.print();

    cout << "\n4. Prosljedivanje funkciji" << endl;
    obradiContainer(c2);

    cout << "\n5. Vracanje iz funkcije" << endl;
    Container c4 = kreirajContainer();
    c4.print();

    cout << "\n6. Realokacija" << endl;
    Container c5(2);
    c5.push_back(10);
    c5.push_back(20);
    cout << "Prije realokacije - capacity: " << c5.capacity() << endl;
    c5.push_back(30);
    cout << "Nakon realokacije - capacity: " << c5.capacity() << endl;
    c5.print();

    cout << "\n7. Ispis s indeksima" << endl;
    for (size_t i = 0; i < c5.size(); i++) {
        cout << "c5.at(" << i << ") = " << c5.at(i) << endl;
    }

    cout << "\n8. Clear" << endl;
    c5.print();
    c5.clear();
    cout << "Nakon clear - size: " << c5.size() << endl;

    return 0;
}