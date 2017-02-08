#include <iostream>
#include "kontroler.h"
#include "Pocetno.h"
#include "Stanja.h"
#include "stoji.h"
#include "IdeGore.h"
#include "IdeDolje.h"

using namespace std;

Kontroler::Kontroler() {
	POCETNO = new Pocetno(this);
	STOJI = new Stoji(this);
	IDEGORE = new IdeGore(this);
	IDEDOLJE = new IdeDolje(this);

	_kat = 14;
}

Kontroler::~Kontroler() {
	delete POCETNO;
	delete STOJI;
	delete IDEGORE;
	delete IDEDOLJE;
}

void Kontroler::postavi_stanje(Stanja* st) {
	_stanje = st;
}

void Kontroler::pocetni_kat() {
	cout << "Lift je na: " << _kat << ". katu" << endl;
}

void Kontroler::prikaziKat() {
	cout << "Kat: " << _kat << endl;
}

void Kontroler::gdjeIde(int uneseni, int drugi) {
	_stanje->kretnjaLifta(uneseni, drugi);
}