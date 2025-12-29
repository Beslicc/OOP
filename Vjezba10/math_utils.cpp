#include "math_utils.h"

namespace math_utils {
    double distance(const Point& p1, const Point& p2) {
        double dx = p1.x - p2.x;
        double dy = p1.y - p2.y;
        return sqrt(dx * dx + dy * dy);
    }

    Point centroid(const vector<Point>& points) {
        if (points.empty()) {
            return Point(0, 0);
        }

        // Moramo koristiti custom akumulator s lambda funkcijom
        Point pocetna(0, 0);
        Point suma = accumulate(points.begin(), points.end(), pocetna,
            [](const Point& acc, const Point& p) {
                return Point(acc.x + p.x, acc.y + p.y);
            });

        // Koristimo static_cast za sigurnu konverziju
        double broj = static_cast<double>(points.size());
        return Point(suma.x / broj, suma.y / broj);
    }

    ostream& operator<<(ostream& os, const Point& p) {
        return os << "(" << p.x << ", " << p.y << ")";
    }
}