#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <cmath>

using namespace std;

void zadatak1() {
    cout << "=== ZADATAK 1: Prirodni brojevi ===" << endl;

    vector<unsigned int> brojevi = { 16, 3, 8, 1, 15, 32, 7, 4, 10, 2, 5 };

    // a) Pronaði prvi neparni broj
    auto prviNeparni = find_if(brojevi.begin(), brojevi.end(),
        [](unsigned int n) { return n % 2 != 0; });

    if (prviNeparni != brojevi.end()) {
        cout << "1. Prvi neparni broj: " << *prviNeparni << endl;
    }
    else {
        cout << "1. Nema neparnih brojeva." << endl;
    }

    // b) Ukupan broj neparnih brojeva
    unsigned int brojNeparnih = count_if(brojevi.begin(), brojevi.end(),
        [](unsigned int n) { return n % 2 != 0; });
    cout << "2. Ukupan broj neparnih: " << brojNeparnih << endl;

    // c) Prosjek neparnih brojeva
    unsigned int sumaNeparnih = accumulate(brojevi.begin(), brojevi.end(), 0u,
        [](unsigned int acc, unsigned int n) {
            return acc + (n % 2 != 0 ? n : 0);
        });

    if (brojNeparnih > 0) {
        double prosjekNeparnih = static_cast<double>(sumaNeparnih) / brojNeparnih;
        cout << "3. Prosjek neparnih: " << prosjekNeparnih << endl;
    }
    else {
        cout << "3. Nema neparnih brojeva za raèunanje prosjeka." << endl;
    }

    // d) Zamijeni potencije broja 2 sa 2
    cout << "4. Zamjena potencija broja 2: " << endl;
    cout << "   Prije: ";
    copy(brojevi.begin(), brojevi.end(), ostream_iterator<unsigned int>(cout, " "));
    cout << endl;

    transform(brojevi.begin(), brojevi.end(), brojevi.begin(),
        [](unsigned int n) {
            // Provjera je li n potencija broja 2
            if (n > 0 && (n & (n - 1)) == 0) {
                return 2u;
            }
            return n;
        });

    cout << "   Poslije: ";
    copy(brojevi.begin(), brojevi.end(), ostream_iterator<unsigned int>(cout, " "));
    cout << endl;

    // e) Ispiši prvo parne pa neparne (od manjeg ka veæem)
    cout << "5. Sortirani parni i neparni:" << endl;

    vector<unsigned int> parni, neparni;
    copy_if(brojevi.begin(), brojevi.end(), back_inserter(parni),
        [](unsigned int n) { return n % 2 == 0; });
    copy_if(brojevi.begin(), brojevi.end(), back_inserter(neparni),
        [](unsigned int n) { return n % 2 != 0; });

    sort(parni.begin(), parni.end());
    sort(neparni.begin(), neparni.end());

    cout << "   Parni: ";
    copy(parni.begin(), parni.end(), ostream_iterator<unsigned int>(cout, " "));
    cout << endl;

    cout << "   Neparni: ";
    copy(neparni.begin(), neparni.end(), ostream_iterator<unsigned int>(cout, " "));
    cout << endl << endl;
}