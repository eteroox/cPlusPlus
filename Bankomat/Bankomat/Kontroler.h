#pragma once
#include "Stanja.h"
#include <iostream>
using namespace std;

/* klasa koja kontrolira upravljanje stanjima*/
class Kontroler {
public:
	Kontroler();
	void postavi_stanje(Stanja* st);
	void umetanjeKartice();
	void prikaziStanje();

	Stanja* KRIVOUMETNUTA;
	Stanja* DOBROUMETNUTA;
	Stanja* KARTICAZABLOKIRANA;
	Stanja* PREGLEDSTANJA;
	Stanja* DEPOZITNOVACA;
	Stanja* PODIZANJENOVACA;
	Stanja* PRINTANJERACUNA;
	Stanja* KARTICAVADENJE;

private:
	Stanja*	_stanje;
};

/*stanja u kojima se moze naci kartica*/
//za krivo umetnutu karticu
class KrivoUmetnutaKartica : public Stanja {
public:
	KrivoUmetnutaKartica(Kontroler* k) : _kontroler{ k } {}
	void prikaziStanje();
private:
	Kontroler* _kontroler;
};

//za dobro umetnutu karticu
class DobroUmetnutaKartica : public Stanja {
public:
	DobroUmetnutaKartica(Kontroler* k) : _kontroler{ k } {}
	void prikaziStanje();
private:
	Kontroler* _kontroler;
};

//ako korisnik zeli pregledati stanje
class PregledStanja : public Stanja {
public:
	PregledStanja(Kontroler* k) : _kontroler{ k } {}
	void prikaziStanje();
private:
	Kontroler* _kontroler;
};

//ako korisnik zeli poloziti novce
class DepozitNovaca : public Stanja {
public:
	DepozitNovaca(Kontroler* k) : _kontroler{ k } {}
	void prikaziStanje();
private:
	Kontroler* _kontroler;
};

//ako korisnik zeli podici novce
class PodizanjeNovaca : public Stanja {
public:
	PodizanjeNovaca(Kontroler* k) : _kontroler{ k } {}
	void prikaziStanje();
private:
	Kontroler* _kontroler;
};

/*ako je kartica blokirana*/
class KarticaBlokirana : public Stanja {
public:
	KarticaBlokirana(Kontroler* k) : _kontroler{ k } {}
	void prikaziStanje();
private:
	Kontroler* _kontroler;
};

/*za printanje racuna*/
class PrintanjeRacuna : public Stanja {
public:
	PrintanjeRacuna(Kontroler* k) : _kontroler{ k } {}
	void prikaziStanje();
private:
	Kontroler* _kontroler;
};

/*za vracanje kartice*/
class KarticaVadenje : public Stanja {
public:
	KarticaVadenje(Kontroler* k) : _kontroler{ k } {}
	void prikaziStanje();
private:
	Kontroler* _kontroler;
};


/*===============================================================================*/
Kontroler::Kontroler() {
	KRIVOUMETNUTA = new KrivoUmetnutaKartica(this);
	DOBROUMETNUTA = new DobroUmetnutaKartica(this);
	PREGLEDSTANJA = new PregledStanja(this);
	DEPOZITNOVACA = new DepozitNovaca(this);
	PODIZANJENOVACA = new PodizanjeNovaca(this);
	KARTICAZABLOKIRANA = new KarticaBlokirana(this);
	PRINTANJERACUNA = new PrintanjeRacuna(this);
	KARTICAVADENJE = new KarticaVadenje(this);
}

void Kontroler::postavi_stanje(Stanja* st) {
	_stanje = st;
}

void Kontroler::prikaziStanje() {
	_stanje->prikaziStanje();
}

void DobroUmetnutaKartica::prikaziStanje() {
	cout << "Ucitavaju se informacije ..." << endl;
}

void KrivoUmetnutaKartica::prikaziStanje() {
	cout << "Kartica je naopako stavljena !!" << endl;
}

void PregledStanja::prikaziStanje() {
	cout << "Ucitavaju se informacije o stanju na racunu ..." << endl;
}

void DepozitNovaca::prikaziStanje() {
	cout << "Deponiramo novac ..." << endl;
}

void PodizanjeNovaca::prikaziStanje() {
	cout << "Koliko novaca zelite podici ..." << endl;
}

void KarticaBlokirana::prikaziStanje() {
	cout << "Potrosili ste pokusaje za unos pina te vam je kartica blokirana , javite se bankarskom sluzbeniku" << endl;
}

void PrintanjeRacuna::prikaziStanje() {
	cout << "Racun se ispisuje..." << endl;
}

void KarticaVadenje::prikaziStanje() {
	cout << "Mozete izvaditi karticu ..." << endl;
}

void Kontroler::umetanjeKartice() {
	int odabir;
	Kontroler k;

	cout << "Stavljate karticu: " << endl;
	cin >> odabir;
	if (odabir == 1) {
		k.postavi_stanje(k.KRIVOUMETNUTA);
		k.prikaziStanje();
		umetanjeKartice();
	}
	if (odabir == 2) {
		k.postavi_stanje(k.DOBROUMETNUTA);
		k.prikaziStanje();
	}
}