#pragma once
#include "Include.h"

class Osoba {
protected:
	string imeOsobe, prezimeOsobe;
	int godineOsobe;
public:
	Osoba(string ime, string prezime, int age) {
		imeOsobe = ime;
		prezimeOsobe = prezime;
		godineOsobe = age;
	}
	string getprvi();
	string getdrugi();
	int gettreci();
	string getTest();
	Osoba getAll();
};

string Osoba::getprvi()
{
	return imeOsobe;
}

string Osoba::getdrugi()
{
	return prezimeOsobe;
}

int Osoba::gettreci() {
	return godineOsobe;
}

