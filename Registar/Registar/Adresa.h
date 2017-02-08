#pragma once
#include "Include.h"

class Adresa {
protected:
	string ulicaAdresa, brojAdresa, gradAdresa;
public:
	Adresa(string ulica, string broj, string grad) {
		ulicaAdresa = ulica;
		brojAdresa = broj;
		gradAdresa = grad;
	}
	string getprvi();
	string getdrugi();
	string gettreci();;
};

string Adresa::getprvi() {
	return ulicaAdresa;
}

string Adresa::getdrugi() {
	return brojAdresa;
}

string Adresa::gettreci() {
	return gradAdresa;
}