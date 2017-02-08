#pragma once

#include "stanja.h"

class Kontroler {
public:
	Kontroler();
	~Kontroler();
	void postavi_stanje(Stanja* st);
	void pocetni_kat();
	void prikaziKat();
	void gdjeIde(int uneseni,int drugi);

	Stanja* POCETNO;
	Stanja* STOJI;
	Stanja* IDEGORE;
	Stanja* IDEDOLJE;

	int _kat;

private:
	Stanja*	_stanje;
	int broj;
};