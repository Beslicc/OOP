#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include "student_records.h"

using namespace std;
using namespace student_records;

void zadatak3() {
    cout << "=== ZADATAK 3: Studenti ===" << endl;

    // a) Uèitavanje studenata iz datoteke
    ifstream fin("studenti.txt");
    if (!fin) {
        cerr << "Greška: ne mogu otvoriti datoteku studenti.txt" << endl;
        // Kreiraj testnu datoteku
        ofstream fout("studenti.txt");
        fout << "Ana Anic 75\n"
            << "Ivan Ivic 45\n"
            << "Marko Markovic 90\n"
            << "Petra Petric 35\n"
            << "Luka Lukic 60\n"
            << "Maja Majic 85\n"
            << "Jure Juretic 25\n"
            << "Karla Karlic 95\n";
        fout.close();
        fin.open("studenti.txt");
    }

    vector<Student> studenti;
    Student temp;

    // Uèitavanje koristeæi stream iterator
    while (fin >> temp) {
        studenti.push_back(temp);
    }

    cout << "Originalni broj studenata: " << studenti.size() << endl;
    cout << "Originalni popis:" << endl;
    for (const auto& s : studenti) {
        cout << "  " << s << endl;
    }
    cout << endl;

    // MAP-FILTER-REDUCE pattern

    // 1. FILTER: remove_if + erase - ukloni studente s manje od 40 bodova
    auto newEnd = remove_if(studenti.begin(), studenti.end(),
        [](const Student& s) {
            return s.bodovi < 40;
        });
    studenti.erase(newEnd, studenti.end());

    cout << "Nakon filtera (<40 bodova): " << studenti.size() << " studenata" << endl;
    cout << "Popis nakon filtera:" << endl;
    for (const auto& s : studenti) {
        cout << "  " << s << endl;
    }
    cout << endl;

    // 2. MAP: transform - konvertiraj bodove u ocjene
    transform(studenti.begin(), studenti.end(), studenti.begin(),
        [](Student s) {
            s.bodovi = bodovi_u_ocjenu(s.bodovi);
            return s;
        });

    cout << "Nakon transformacije (bodovi -> ocjene):" << endl;
    for (const auto& s : studenti) {
        cout << "  " << s.prezime << ", " << s.ime << ": ocjena " << s.bodovi << endl;
    }
    cout << endl;

    // 3. REDUCE: accumulate - izraèunaj prosjek ocjena
    if (!studenti.empty()) {
        int sumaOcjena = accumulate(studenti.begin(), studenti.end(), 0,
            [](int acc, const Student& s) {
                return acc + s.bodovi;
            });

        double prosjekOcjena = static_cast<double>(sumaOcjena) / studenti.size();
        cout << "Prosjek ocjena: " << prosjekOcjena << endl;
    }

    // 4. Sortiraj po prezimenu
    sort(studenti.begin(), studenti.end(),
        [](const Student& a, const Student& b) {
            return a.prezime < b.prezime;
        });

    // 5. Ispiši konaèni izvještaj
    cout << "\n=== KONAÈNI IZVJEŠTAJ (sortirano po prezimenu) ===" << endl;
    cout << "Prezime, Ime: Ocjena" << endl;
    cout << "--------------------------------" << endl;

    for_each(studenti.begin(), studenti.end(),
        [](const Student& s) {
            cout << s.prezime << ", " << s.ime << ": " << s.bodovi << endl;
        });

    // 6. Spremi u datoteku koristeæi ostream_iterator
    ofstream fout("izvjestaj_studenti.txt");
    fout << "=== IZVJEŠTAJ O STUDENTIMA ===" << endl;
    fout << "Prezime, Ime: Ocjena" << endl;
    fout << "--------------------------------" << endl;

    for_each(studenti.begin(), studenti.end(),
        [&fout](const Student& s) {
            fout << s.prezime << ", " << s.ime << ": " << s.bodovi << endl;
        });

    cout << "\nIzvještaj spremljen u izvjestaj_studenti.txt" << endl;
}