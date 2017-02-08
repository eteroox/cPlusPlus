#include <iostream>
#include "Kontroler.h"
#include "Pocetno.h"
#include "Stoji.h"
#include "IdeGore.h"
#include "IdeDolje.h"

int main() {
	Kontroler k;

	k.postavi_stanje(k.POCETNO);				//preko kontrolera se postavlja stanje na pocetno

	bool flag = true;

	while (flag) {
		int broj;
		cin >> broj;							//unosimo na koji se kat lift zove
		if (broj < 14 && broj > 0) {			//ako je kat manji od kata na kojem se lift nalazi (14.) i veci od 0 onda se preko kontrolera ide u funkciju stanja dolje
			k.postavi_stanje(k.IDEDOLJE);
			k.gdjeIde(broj,k._kat);
		 }
		if (broj > 14 && broj < 21) {
			k.postavi_stanje(k.IDEGORE);
			k.gdjeIde(broj, k._kat);			//ako je kat veci od kata na kojem se lift nalazi (14.) i manji od 21 onda se preko kontrolera ide u funkciju stanja gore
		}
		else {
			flag=false;							//ak se unese krivi kat program se prekida
		}

	}
	
	system("pause");
	return 0;
}