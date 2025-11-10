#ifndef TRESETA_H
#define TRESETA_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Karta {
private:
	int broj;
	int zog;
public:
	Karta(int broj, int zog);
	int getBroj() const;
	int getZog() const;
	string toString() const;
	bool istiBroj(const Karta& druga) const;
	bool istiZog(const Karta& druga) const;
};

class Mac {
private:
	vector<Karta>karte;
public:
	Mac();
	void promijesaj();
	Karta podijeliKartu();
	bool imaKarata() const;
	int brojKarta() const;
};

class Igrac {
private:
	string ime;
	vector<Karta> ruka;
	int bodoviAkuza;
public:
	Igrac(const string& ime);
	string getIme() const;
	int getBodoviAkuza() const;
	void primiKartu(const Karta& karta);
	void ispisiRuku()const;
	void provjeriAkuze();
private:
	bool imaNapolitanu() const;
	bool imaTriIste() const;
	bool imaCetiriIste() const;
};

#endif