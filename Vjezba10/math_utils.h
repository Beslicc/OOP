#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#include <vector>
#include <cmath>
#include <numeric>
#include <iostream>

using namespace std;

namespace math_utils {
    struct Point {
        double x, y;

        Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

        // Operator za usporedbu za sortiranje
        bool operator<(const Point& other) const {
            return (x * x + y * y) < (other.x * other.x + other.y * other.y);
        }

        // Operator zbrajanja za accumulate
        Point operator+(const Point& other) const {
            return Point(x + other.x, y + other.y);
        }
    };

    // Funkcija za raèunanje udaljenosti
    double distance(const Point& p1, const Point& p2);

    // Funkcija za raèunanje centroida
    Point centroid(const vector<Point>& points);

    // Operator za ispis
    ostream& operator<<(ostream& os, const Point& p);

    // Operator za èitanje (dodajemo)
    istream& operator>>(istream& is, Point& p);
}

#endif