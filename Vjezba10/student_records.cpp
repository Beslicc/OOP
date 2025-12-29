#include "student_records.h"
#include <stdexcept>

namespace student_records {
    int bodovi_u_ocjenu(int bodovi) {
        if (bodovi < 0 || bodovi > 100) {
            throw invalid_argument("Bodovi moraju biti izmeðu 0 i 100");
        }

        if (bodovi < 40) return 1;
        else if (bodovi < 55) return 2;
        else if (bodovi < 70) return 3;
        else if (bodovi < 85) return 4;
        else return 5;
    }

    ostream& operator<<(ostream& os, const Student& s) {
        return os << s.prezime << ", " << s.ime << ": " << s.bodovi << " bodova";
    }

    istream& operator>>(istream& is, Student& s) {
        return is >> s.ime >> s.prezime >> s.bodovi;
    }
}