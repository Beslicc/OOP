#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

/*
int main()
{
	int a, b, s;
	std::cout << "unesi dva broja" << std::endl;
	std::cin >> a >> b;
	s = a + b;
	std::cout << "suma je " << s << std::endl;
}
*/
/*
// ZAD 1
int main()
{
	bool flag;
	std::cout << "unesi " << true << " - " << false << std::endl;
	std::cin >> flag;
	std::cout << std::uppercase << flag << std::endl;
	int a = 255;
	std::cout << "hex " << std::hex << a << std::endl;
	std::cout << "dec " << std::dec << a << std::endl;
	std::cout << "oct " << std::oct << a << std::endl;
	double pi = 3.141592;
	std::cout << "pi = " << std::fixed << std::uppercase;
	std::cout << std::setprecision(10) << std::setw(20);
	std::cout << std::setfill('0');
	std::cout << pi << std::endl;
	system("pause");
}
*/

/*
// ZAD 2
using namespace std;

int limit(int vrijednost, int low = 0, int high = 100) {
	if (vrijednost < low)
		return low;
	else if (vrijednost >= high)
		return high;
	else
		return vrijednost;
}

double limit(double vrijednost, double low = 0.0, double high = 100.0) {
	if (vrijednost < low)
		return low;
	else if (vrijednost >= high)
		return high;
	else
		return vrijednost;
}

int main() {
	int vrijednost;
	cout << "unesi broj:" << endl;
	cin >> vrijednost;
	int rezultat = limit(vrijednost);

	cout << "vrijednost: " << rezultat << endl;
	return 0;
}
*/


// ZAD 3
/*
using namespace std;
int main() {
	string s;
	cout << "Unesi tekst: ";
	getline(cin, s);

	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = toupper(s[i]);
		else if (s[i] >= '0' && s[i] <= '9')
			s[i] = '*';
		else if (s[i] == ' ')
			s[i] = '_';
	}

	cout << "Novi tekst: " << s << endl;
	return 0;
}
*/

/*
// ZAD 4
int& at(int arr[], int index) {
	return arr[index];
}

int main() {
	int a[5] = { 1, 2, 3, 4, 5 };
	at(a, 2)++;
	for (int i = 0; i < 5; ++i) std::cout << a[i] << (i + 1 < 5 ? ' ' : '\n');
	return 0;
}
*/