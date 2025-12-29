#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "math_utils.h"

using namespace std;
using namespace math_utils;

void zadatak2() {
    cout << "=== ZADATAK 2: Toèke ===" << endl;

    // a) Uèitavanje toèaka iz datoteke
    ifstream fin("points.txt");
    if (!fin) {
        cerr << "Greška: ne mogu otvoriti datoteku points.txt" << endl;
        // Kreiraj testnu datoteku
        ofstream fout("points.txt");
        fout << "1.0 2.0\n3.5 4.2\n-2.0 3.0\n5.0 -1.0\n-3.0 -4.0\n0.0 0.0\n2.5 2.5\n";
        fout.close();
        fin.open("points.txt");
    }

    // Bolji naèin za uèitavanje - èitaj direktno Point objekte
    vector<Point> points;
    Point p;

    // Potrebno je overloadati operator>> za Point
    while (fin >> p.x >> p.y) {
        points.push_back(p);
    }

    cout << "Uèitano " << points.size() << " toèaka:" << endl;
    copy(points.begin(), points.end(), ostream_iterator<Point>(cout, "\n"));
    cout << endl;

    // b) Sortiraj po udaljenosti od ishodišta (lambda)
    sort(points.begin(), points.end(),
        [](const Point& a, const Point& b) {
            return (a.x * a.x + a.y * a.y) < (b.x * b.x + b.y * b.y);
        });

    cout << "Sortirano po udaljenosti od ishodišta:" << endl;
    copy(points.begin(), points.end(), ostream_iterator<Point>(cout, "\n"));
    cout << endl;

    // c) Prebroji toèke u prvom kvadrantu
    int prviKvadrant = count_if(points.begin(), points.end(),
        [](const Point& p) {
            return p.x > 0 && p.y > 0;
        });
    cout << "Toèaka u prvom kvadrantu: " << prviKvadrant << endl;

    // d) Izraèunaj centroid
    Point cent = centroid(points);
    cout << "Centroid: " << cent << endl;

    // e) Pomakni sve toèke za (5, 3) koristeæi transform
    transform(points.begin(), points.end(), points.begin(),
        [](const Point& p) {
            return Point(p.x + 5, p.y + 3);
        });

    cout << "\nToèke nakon pomaka za (5, 3):" << endl;
    copy(points.begin(), points.end(), ostream_iterator<Point>(cout, "\n"));
    cout << endl;

    // f) Ukloni toèke s obje koordinate negativne (remove_if + erase idiom)
    auto newEnd = remove_if(points.begin(), points.end(),
        [](const Point& p) {
            return p.x < 0 && p.y < 0;
        });
    points.erase(newEnd, points.end());

    cout << "Toèke nakon uklanjanja negativnih:" << endl;
    copy(points.begin(), points.end(), ostream_iterator<Point>(cout, "\n"));

    // g) Ispiši u datoteku koristeæi ostream_iterator
    ofstream fout("output_points.txt");
    ostream_iterator<Point> output(fout, "\n");
    copy(points.begin(), points.end(), output);
    cout << "\nRezultati spremljeni u output_points.txt" << endl << endl;
}