#include "Sifriranje.h"
#include "SifriranjeASCII.h"
#include "Dodatak.h"

int main()
{
	/*
	Sifriranje* sifriranjeASCII = new AscII();				//sifriranje preko funkcija klase
	sifriranjeASCII->sifra();
	sifriranjeASCII = new desifrirajASCII(sifriranjeASCII);		//desifriranje preko dekoratora
	sifriranjeASCII->desifriraj();

	Sifriranje* sifriranje = new Slova();					//sifriranje preko funkcija klase
	//sifriranje->slovo();
	sifriranje->ipisiSifru(sifriranje->sifra());
	cout << endl;
	sifriranje = new desifrirajSLOVA(sifriranje);			//desifriranje preko dekoratora
	sifriranje->desifriraj();
	*/

	Sifriranje* sifriranjeASCII = new AscII();					//funkcije sifriranje nisu u dekoratoru
	sifriranjeASCII->sifra();
	sifriranjeASCII = new desifrirajASCII(sifriranjeASCII);
	sifriranjeASCII->desifriraj();

	Sifriranje* sifriranjeSlova = new Slova();
	sifriranjeSlova->ipisiSifru(sifriranjeSlova->sifra());
	cout << endl;
	sifriranjeSlova = new desifrirajSLOVA(sifriranjeSlova);
	sifriranjeSlova->desifriraj();

	system("pause");
	return 0;
}