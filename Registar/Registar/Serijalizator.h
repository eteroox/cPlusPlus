#pragma once
#include "Include.h"
#include "Osoba.h"
#include "Adresa.h"

class Serijalizator {
protected:
	Osoba* osobaNova;
public:
	template <class T>
	void spremi(T* osoba, string text) {

		fstream datoteka;
		fstream* d1 = &datoteka;

		vector<Osoba> vektor;
		string tekst;

		d1->open(text, fstream::out);

		*d1 << osoba->getprvi()<< "," << osoba->getdrugi() << "," << osoba->gettreci() << endl;

		d1->close();
	}
	
	template <class T>
	T* ucitaj(string x) {

		fstream datoteka;
		fstream* d1 = &datoteka;

		d1->open(x, fstream::in);

		string tekst;

		*d1 >> tekst;		// ucitaj sadrzaj u varijablu 'tekst'
		cout << tekst << endl;

		//Osoba novaOsoba(tekst.substr(0,4), tekst.substr(4,6), stoi(tekst.substr(11, 2)));

		d1->close();

		return new T(tekst.substr(0, 4), tekst.substr(5, 5), stoi(tekst.substr(11, 2)));

	}
};


class Strategy {
private:
	Serijalizator* _serijaliziraj;
public:
	template <class T>
	void spremanje(T* osoba, string text) {
		_serijaliziraj->spremi(osoba, text);
	}

	string odaberiFormatZapisa();

	template <class T>
	void spremiJson(T* osoba, string text);

	template <class T>
	void spremiXml(T* osoba, string text);
};

string  Strategy::odaberiFormatZapisa() {
	int input;
	string format;
	Strategy str;

	cout << "Izaberite format u kojem cete zapisati datoteku: " << endl;
	cout << "1)txt , 2)xml, 3)json" << endl;
	cin >> input;
	switch (input) {
	case 1:
		format = ".txt";
		break;
	case 2:
		format = ".xml";
		break;
	case 3:
		format = ".json";
		break;
	default:
		format = ".txt";
		break;
	}
	return format;
}


template <class T>
void Strategy::spremiJson(T* osoba, string text) {

	fstream datoteka;
	fstream* d1 = &datoteka;

	vector<Osoba> vektor;
	string tekst;

	d1->open(text, fstream::out);

	*d1 << "{'Osoba':[" << endl;
	*d1 << "{'firstName': " << osoba->getprvi() << ", 'lastName' : " << osoba->getdrugi() << ", 'age: '" << osoba->gettreci() << "}" << endl;
	*d1 << "]}" << endl;

	d1->close();
}


template <class T>
void Strategy::spremiXml(T* osoba, string text) {

	fstream datoteka;
	fstream* d1 = &datoteka;

	vector<Osoba> vektor;
	string tekst;

	d1->open(text, fstream::out);

	*d1 << "<osobe>" << endl;
	*d1 << "<osoba>" << endl;
	*d1 << "<firstName>" << osoba->getprvi() << "</ firstName> <lastName> " << osoba->getdrugi() << "< / lastName>" << "<age>" << osoba->gettreci() << "< / age>" << endl;
	*d1 << "< / osoba>" << endl;
	*d1 << "< / osobe>" << endl;
	d1->close();
}