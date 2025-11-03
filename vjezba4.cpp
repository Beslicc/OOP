#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*
// ZADATAK 1

void input_vector(vector<int>& v) {
	int broj;
	cout << "Unesi brojeve (0 za kraj): ";
	while (true) {
		cin >> broj;
		if (broj == 0) break;
		v.push_back(broj);
	}
}

void print_vector(const vector<int>& v) {
	for (int x : v) {
		cout << x << " ";
	}
	cout << endl;
}

int main() {
	vector <int> brojevi;
	input_vector(brojevi);
	cout << "Uneseni brojevi: ";
	print_vector(brojevi);
	system("pause");
	return 0;
}
*/

/*
// ZADATAK 2

int myAbs(int x) {
	if (x < 0) { 
		return -x; }
	else { 
		return x;
	}
}
void input_vector(vector<int>& v) {
	int broj;
	cout << "Unesi brojeve (0 za kraj): ";
	while (true) {
		cin >> broj;
		if (broj == 0) break;
		v.push_back(broj);
	}
}
void print_vector(const vector<int>& v) {
	for (int x : v) {
		cout << x << " ";
	}
	cout << endl;
}

int main() {
	vector <int> v;
	input_vector(v);
	cout << "Orginalni vektor: ";
	print_vector(v);
	vector<int> jedinstveni;
	for (int x : v) 
		if (find(jedinstveni.begin(), jedinstveni.end(), x) == jedinstveni.end())
			jedinstveni.push_back(x);
	
	cout << "Jedinstveni elementi: ";
	print_vector(jedinstveni);

	sort(jedinstveni.begin(), jedinstveni.end(), [](int a, int b) { return myAbs(a) < myAbs(b); });
	cout << "Sortirani po apsolutnoj vrijednosti: ";
	for (int x : jedinstveni)
		cout << x << " ";
	system("pause");
	return 0;
}
*/
/*
// ZADATAK 3

void fix_spaces(string& text) {
	for (size_t i = 0; i + 1 < text.size(); ) {
		if (text[i] == ' ' && text[i + 1] == ' ') {
			text.erase(i, 1);
		}
		else {
			i++;
		}
	}
	for (size_t i = 0; i < text.size(); i++) {
		if (text[i] == ' ' && text[i + 1] == ',' || text[i+1]=='.') {
			text.erase(i, 1);
		}
	}
	for (size_t i = 0; i+1 < text.size(); i++) {
		if (text[i] == ',' && text[i + 1] != ' ') {
			text.insert(i+1, " ");
		}
	}
}

int main() {
	string tekst = "Puno  razmaka ,i tocka .";
	fix_spaces(tekst);
	cout << tekst << endl;
	system("pause");
	return 0;
}
*/

// ZADATAK 4
/*
string word_to_pig_latin(const std::string& word) {
	string samoglasnici = " aeiouAEIOU";
	if (samoglasnici.find(word[0])!=string::npos) {
		return word + "hay";
	}
	else {
		return word.
	}
}

int main() {
	
	system("pause");
	return 0;
}
*/