#pragma once
#include "Stanja.h"
#include "kontroler.h"

using namespace std;

class Pocetno : public Stanja {
public:
	Pocetno(Kontroler* k);
	void kretnjaLifta(int broj, int brojDva) {};
private:
	Kontroler* _kontroler;
};