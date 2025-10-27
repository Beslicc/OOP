#include <iostream>
#include <cstddef>

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

