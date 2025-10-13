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
//1
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


//2.
#include <iostream>
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
	system("pause");
	return 0;
	}

*/

int main() {
	using namespace std;
	string s;
	cout << "unesi redak:" << endl;
	cin >> s;
	getline(cin, s);
	for (char &c : s) {
		
		}
	}
	return 0;
}