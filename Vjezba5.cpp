#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
using namespace std;

class Karta {
    string zog;
    int broj;
public:
    Karta(string z = "", int b = 0) : zog(z), broj(b) {} 

    string getZog() const {
        return zog;
    }
    int getBroj() const {
        return broj;
    }
};

class Spil {
    vector<Karta> sp;
public:
    Spil() {
        string zogovi[] = { "bastoni", "spade", "dinari", "kupe" };
        for (const auto& z : zogovi) {
            for (int b : {1, 2, 3, 4, 5, 6, 7, 11, 12, 13})
                sp.emplace_back(z, b);
        }
    }

    void mijesanje() {
        srand(time(0));
        random_shuffle(sp.begin(), sp.end());
    }

    vector<Karta> dijeljenje() {
        vector<Karta> ruka;
        for (int i = 0; i < 10; i++) {
            if (!sp.empty()) {
                ruka.push_back(sp.back());
                sp.pop_back();
            }
        }
        return ruka;
    }
};

class Igrac {
    string ime;
    vector<Karta> karte;
    int bodovi = 0;

public:
    Igrac(string i) : ime(i) {}
    void postaviKarte(const vector<Karta>& noveKarte) {
        karte = noveKarte;
    }
    void izracunajBodove() {
        int broj[3] = { 0 }; 

        for (const auto& k : karte) {
            if (k.getBroj() == 1) broj[0]++;
            if (k.getBroj() == 2) broj[1]++;
            if (k.getBroj() == 3) broj[2]++;
        }

        for (int i = 0; i < 3; i++) {
            if (broj[i] >= 3) bodovi += 3;
            if (broj[i] == 4) bodovi += 1; 
        }

        string zogovi[] = { "bastoni", "spade", "dinari", "kupe" };

        for (const auto& z : zogovi) {
            bool ima1 = false, ima2 = false, ima3 = false;
            for (const auto& k : karte) {
                if (k.getZog() == z) {
                    if (k.getBroj() == 1) ima1 = true;
                    if (k.getBroj() == 2) ima2 = true;
                    if (k.getBroj() == 3) ima3 = true;
                }
            }
            if (ima1 && ima2 && ima3) bodovi += 3;
        }
    }

    void ispis() const {
        cout << ime << " ima " << bodovi << " bodova." << endl;

        cout << "Karte: ";
        for (const auto& k : karte) {
            cout << k.getBroj() << k.getZog()[0] << " "; 
        }
        cout << endl << endl;
    }
};

int main() {
    int brojIgraca;
    cout << "Unesi broj igraca (2 ili 4): ";
    cin >> brojIgraca;

    if (brojIgraca != 2 && brojIgraca != 4) {
        cout << "Neispravan broj igraca!" << endl;
        return 1;
    }

    vector<Igrac> igraci;
    for (int i = 0; i < brojIgraca; ++i) {
        string ime;
        cout << "Unesi ime igraca " << (i + 1) << ": ";
        cin >> ime;
        igraci.emplace_back(ime);
    }

    Spil spil;
    spil.mijesanje();

    for (auto& igrac : igraci) {
        igrac.postaviKarte(spil.dijeljenje());
        igrac.izracunajBodove();
        igrac.ispis();
    }

    return 0;
}