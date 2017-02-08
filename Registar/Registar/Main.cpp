#include "Include.h"
#include "Osoba.h"
#include "Adresa.h"
#include "Serijalizator.h"

int main() {
	Osoba osoba("Pero", "Peric", 33);
	Adresa adresa("Ilica", "105", "Zagreb");


	Serijalizator p;
	p.spremi(&osoba, "osoba.txt");	// sprema kao tekst "Pero,Peric,33"
	p.spremi(&adresa, "adresa.txt");

	Osoba* x = p.ucitaj<Osoba>("osoba.txt");
	
	cout << x->getprvi()<<"," << x->getdrugi()<<"," << x->gettreci() << endl;

	/*strategy dio*/
	Strategy str;
	string format;

	format = str.odaberiFormatZapisa();

	if (format == ".txt") {
		str.spremanje(&osoba, "osoba.txt");
	}
	if (format == ".json") {
		str.spremiJson(&osoba, "osoba.json");
	}
	if (format == ".xml") {
		str.spremiXml(&osoba, "osoba.xml");
	}

	system("pause");
	return 0;
}
