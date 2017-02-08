#include "Kontroler.h"
#include "Stanja.h"
#include "Include.h"
#include "Pin.h"

int main() {
	Kontroler k;
	k.umetanjeKartice();

	Bankomat* banka=new Bankomat(new PodatkovnaKomponenta);
	banka->pin();
	system("pause");
	return 0;
}