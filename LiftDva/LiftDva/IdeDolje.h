#pragma once
#include "Stanja.h"
#include "kontroler.h"

using namespace std;

class IdeDolje : public Stanja {
public:
	IdeDolje(Kontroler* k);
	void kretnjaLifta(int broj, int brojDva);
private:
	Kontroler* _kontroler;
};