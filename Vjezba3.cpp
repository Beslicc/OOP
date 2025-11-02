#include <iostream>
#include <cstddef>
#include <vector>
using namespace std;

/*
// ZADATAK 1
inline bool ascending(int a, int b){
	return a < b;
};
inline bool descending(int a, int b) {
	return a > b;
};

void sortt(int niz[], size_t n, bool(*cmp)(int, int)) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (cmp(niz[i], niz[j])) {
				int k = niz[i];
				niz[i] = niz[j];
				niz[j] = k;
			}
		}
	}
}

int main() {
	int niz[] = {5,2,8,1,3};
	int n = 5;
	cout << "Uzlazno: ";
	sortt(niz, n, ascending);
	for (int i = 0; i < n; i++) {
		cout << niz[i] << " ";
	}
	cout << endl;
	cout << "Silazno: ";
	sortt(niz, n, descending);
	for (int i = 0; i < n; i++) {
		cout << niz[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
*/

/*
// ZADATAK 2

template<typename T>
void sortt(T niz[], size_t n, bool(*cmp)(T, T)) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (cmp(niz[i], niz[j])) {
				T k = niz[i];
				niz[i] = niz[j];
				niz[j] = k;
			}
		}
	}
}

template<typename T> inline bool ascending(T a, T b) {
	return a < b;
};
template<typename T> inline bool descending(T a, T b) {
	return a > b;
};

int main() {
	int niz[] = { 5,2,8,1,3 };
	int n = 5;
	cout << "Uzlazno: ";
	sortt(niz, n, ascending<int>);
	for (int i = 0; i < n; i++) {
		cout << niz[i] << " ";
	}
	cout << endl;
	cout << "Silazno: ";
	sortt(niz, n, descending<int>);
	for (int i = 0; i < n; i++) {
		cout << niz[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
*/

// ZADATAK 3
/*
void obradi(vector<int>& niz) {
	auto parni = [](int x) { return x % 2 == 0; };
	auto prepolovi = [](int x) { return x / 2; };
	auto udvostruci = [](int x) { return x * 2; };
	for (int& x : niz) {
		if (parni(x)) x = prepolovi(x);
		else x = udvostruci(x);
	}
}

void suma_i_produkt(const vector<int>& niz, int& suma, int& produkt) {
	suma = 0;
	produkt = 1;
	auto dodaj_sumu = [&](int x) { suma += x; };
	auto dodaj_produkt = [&](int x) { produkt *= x; };
	for (int x : niz) {
		dodaj_sumu(x);
		dodaj_produkt(x);
	}
}

int suma_vecih_od_praga(const vector<int>& niz, int prag) {
	int suma = 0;
	auto dodaj_ako_veca = [prag, &suma](int x) { if (x > prag) suma += x; };
	for (int x : niz) dodaj_ako_veca(x);
	return suma;
}

int main() {
	vector<int> brojevi = { 2, 3, 5, 6, 10 };
	cout << "Pocetni niz: ";
	for (int x : brojevi) cout << x << " ";
	cout << endl;
	obradi(brojevi);
	cout << "Nakon obrade: ";
	for (int x : brojevi) cout << x << " ";
	cout << endl;
	int suma, produkt;
	suma_i_produkt(brojevi, suma, produkt);
	cout << "Suma = " << suma << ", Produkt = " << produkt << endl;
	int prag = 5;
	cout << "Suma brojeva > " << prag << " = " << suma_vecih_od_praga(brojevi, prag) << endl;
	return 0;
}
*/

// ZADATAK 4
/*
struct Student {
	string ime;
	int jmbag;
	int godina;
	int ects;
	double prosjek;
};

void filter_students(Student arr[], int n, void (*akcija)(Student&), bool (*filter)(Student&)) {
	for (int i = 0; i < n; i++) {
		if (filter(arr[i]))
			akcija(arr[i]);
	}
}

void ispisi(Student& s) {
	cout << s.ime << " (" << s.godina << ". god), " << s.ects << " ECTS, prosjek: " << s.prosjek << endl;
}

void povecaj_godinu(Student& s) {
	s.godina++;
}

int main() {
	Student studenti[] = {
		{"Ana", 123, 1, 30, 4.2},
		{"Marko", 456, 1, 0, 2.8},
		{"Iva", 789, 2, 60, 3.9},
		{"Petar", 321, 3, 45, 3.3}
	};
	int n = sizeof(studenti) / sizeof(studenti[0]);

	cout << "Studenti 1. godine s barem 1 ECTS:\n";
	auto uvjet1 = [](Student& s) { return s.godina == 1 && s.ects > 0; };
	filter_students(studenti, n, ispisi, uvjet1);

	cout << "\nStudenti s prosjekom > 3.5:\n";
	auto uvjet2 = [](Student& s) { return s.prosjek > 3.5; };
	filter_students(studenti, n, ispisi, uvjet2);

	cout << "\nPovecavanje godine studentima s barem 45 ECTS...\n";
	auto uvjet3 = [](Student& s) { return s.ects >= 45; };
	filter_students(studenti, n, povecaj_godinu, uvjet3);

	cout << "\nSvi studenti nakon promjena:\n";
	for (int i = 0; i < n; i++) ispisi(studenti[i]);
	return 0;
}
*/