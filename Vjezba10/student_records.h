#ifndef STUDENT_RECORDS_H
#define STUDENT_RECORDS_H

#include <string>
#include <iostream>

using namespace std;

namespace student_records {
    struct Student {
        string ime;
        string prezime;
        int bodovi;

        Student(const string& i = "", const string& p = "", int b = 0)
            : ime(i), prezime(p), bodovi(b) {
        }

        // Operator za usporedbu (za sortiranje)
        bool operator<(const Student& other) const {
            return prezime < other.prezime;
        }
    };

    // Funkcija za konverziju bodova u ocjenu
    int bodovi_u_ocjenu(int bodovi);

    // Operator za ispis
    ostream& operator<<(ostream& os, const Student& s);

    // Operator za èitanje
    istream& operator>>(istream& is, Student& s);
}

#endif