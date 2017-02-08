#pragma once
#include "Stanja.h"
#include "kontroler.h"

using namespace std;

class Stoji : public Stanja {
public:
	Stoji(Kontroler* k);
	void kretnjaLifta(int broj, int brojDva) {};
private:
	Kontroler* _kontroler;
};