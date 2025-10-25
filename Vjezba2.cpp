#include <iostream>
using namespace std;

/*
// ZAD 1
int* fibonacci(int n) {
	int* niz = new int[n];
	niz[0] = 1;
	niz[1] = 1;
	for (int i = 2; i < n; i++) {
		niz[i] = niz[i - 2] + niz[i - 1];
	}
	return niz;
}

int main() {
	int n;
	cout << "Unesi velicinu: ";
	cin >> n;
	int* niz = fibonacci(n);
	cout << "Fibonacci niz: ";
	for (int i = 0; i < n; i++) {
		cout << niz[i] << " ";
	}
	cout << endl;
	delete[] niz;
	niz = nullptr;
	system("pause");
	return 0;
}
*/

/*
// ZAD 2
struct Vector {
	int* elementi;
	int logicka;
	int fizicka;
};

Vector vector_new(int pocetni_kapacitet){
	Vector v;
	v.elementi = new int[pocetni_kapacitet];
	v.logicka = 0;
	v.fizicka = pocetni_kapacitet;
	return v;
};

void vector_delete(Vector& v){
	delete[] v.elementi;
	v.elementi = nullptr;
	v.logicka = 0;
	v.fizicka = 0;
};

void vector_push_back(Vector& v, int nelement) {
	if (v.logicka >= v.fizicka) {
		int novi_kapacitet = v.fizicka * 2;
		int* novi_niz = new int[novi_kapacitet];
		for (int i = 0; i < v.logicka; i++) {
			novi_niz[i] = v.elementi[i];
		}
		delete[] v.elementi;
		v.elementi = novi_niz;
		v.fizicka = novi_kapacitet;
	}
	v.elementi[v.logicka] = nelement;
	v.logicka++;
};

void vector_pop_back(Vector& v) {
	if (v.logicka > 0)
		v.logicka--;
};

int vector_front(Vector& v) {
	return v.elementi[0];
};

int vector_back(Vector& v) {
	return v.elementi[v.logicka - 1];
};

int vector_size(Vector& v) {
	return v.logicka;
};

int main() {
	Vector v = vector_new(2);

	vector_push_back(v, 10);
	vector_push_back(v, 20);
	vector_push_back(v, 30);
	vector_push_back(v, 40);

	cout << "Prvi element: " << vector_front(v) << endl;
	cout << "Zadnji element: " << vector_back(v) << endl;
	cout << "Velicina vektora: " << vector_size(v) << endl;

	vector_pop_back(v);
	cout << "Nakon pop_back, velicina je: " << vector_size(v) << endl;

	cout << "Sadrzaj: ";
	for (int i = 0; i < vector_size(v); i++) {
		cout << v.elementi[i] << " ";
	}
	cout << endl;
	vector_delete(v);
	system("pause");
	return 0;
}
*/
/*
// ZAD 3

#include <iostream>
#include <iomanip>

using namespace std;

double** unosMatrice(int m, int n) {
    double** matrica = new double* [m];
    for (int i = 0; i < m; i++) {
        matrica[i] = new double[n];
        for (int j = 0; j < n; j++) {
            cin >> matrica[i][j];
        }
    }
    return matrica;
}

double** generirajMatricu(int m, int n, double a, double b) {
    double** matrica = new double* [m];
    for (int i = 0; i < m; i++) {
        matrica[i] = new double[n];
        for (int j = 0; j < n; j++) {
            matrica[i][j] = a + (i * n + j) * ((b - a) / (m * n));
        }
    }
    return matrica;
}

double** zbrojiMatrice(double** A, double** B, int m, int n) {
    double** rezultat = new double* [m];
    for (int i = 0; i < m; i++) {
        rezultat[i] = new double[n];
        for (int j = 0; j < n; j++) {
            rezultat[i][j] = A[i][j] + B[i][j];
        }
    }
    return rezultat;
}

double** oduzmiMatrice(double** A, double** B, int m, int n) {
    double** rezultat = new double* [m];
    for (int i = 0; i < m; i++) {
        rezultat[i] = new double[n];
        for (int j = 0; j < n; j++) {
            rezultat[i][j] = A[i][j] - B[i][j];
        }
    }
    return rezultat;
}

double** pomnoziMatrice(double** A, double** B, int m, int n, int p) {
    double** rezultat = new double* [m];
    for (int i = 0; i < m; i++) {
        rezultat[i] = new double[p];
        for (int j = 0; j < p; j++) {
            rezultat[i][j] = 0;
            for (int k = 0; k < n; k++) {
                rezultat[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return rezultat;
}

double** transponirajMatricu(double** A, int m, int n) {
    double** rezultat = new double* [n];
    for (int i = 0; i < n; i++) {
        rezultat[i] = new double[m];
        for (int j = 0; j < m; j++) {
            rezultat[i][j] = A[j][i];
        }
    }
    return rezultat;
}

void ispisiMatricu(double** matrica, int m, int n) {
    cout << fixed << setprecision(4);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(10) << right << matrica[i][j];
        }
        cout << endl;
    }
}

void dealocirajMatricu(double** matrica, int m) {
    for (int i = 0; i < m; i++) {
        delete[] matrica[i];
    }
    delete[] matrica;
}

int main() {
    int m = 2, n = 3;

    cout << "Unesite elemente matrice A (" << m << "x" << n << "):" << endl;
    double** A = unosMatrice(m, n);

    cout << "Generiranje matrice B (" << m << "x" << n << ") u rasponu [1, 10]:" << endl;
    double** B = generirajMatricu(m, n, 1.0, 10.0);

    cout << "Matrica A:" << endl;
    ispisiMatricu(A, m, n);

    cout << "Matrica B:" << endl;
    ispisiMatricu(B, m, n);

    cout << "Zbroj A + B:" << endl;
    double** zbroj = zbrojiMatrice(A, B, m, n);
    ispisiMatricu(zbroj, m, n);

    cout << "Razlika A - B:" << endl;
    double** razlika = oduzmiMatrice(A, B, m, n);
    ispisiMatricu(razlika, m, n);

    cout << "Transponirana matrica A:" << endl;
    double** transponiranaA = transponirajMatricu(A, m, n);
    ispisiMatricu(transponiranaA, n, m);

    int p = 2;
    cout << "Mnozenje A(" << m << "x" << n << ") * C(" << n << "x" << p << "):" << endl;
    double** C = generirajMatricu(n, p, 1.0, 5.0);
    cout << "Matrica C:" << endl;
    ispisiMatricu(C, n, p);

    double** umnozak = pomnoziMatrice(A, C, m, n, p);
    cout << "Umnozak A * C:" << endl;
    ispisiMatricu(umnozak, m, p);

    dealocirajMatricu(A, m);
    dealocirajMatricu(B, m);
    dealocirajMatricu(zbroj, m);
    dealocirajMatricu(razlika, m);
    dealocirajMatricu(transponiranaA, n);
    dealocirajMatricu(C, n);
    dealocirajMatricu(umnozak, m);

    return 0;
}
*/