#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <string>
#include "Sifriranje.h"
#include "SifriranjeASCII.h"

class Dodatak : public Sifriranje {						//clasa koja ce biti dekorator , znaci ko u primjeru sadrzi slag , mlijeko
public:
	virtual void desifriraj() const = 0;
	virtual map<char, int> sifra() const = 0; //za testiranje navodno tak treba
};

/* ################# dekorator za desifriranje ASCII ############# */
class desifrirajASCII : public Dodatak {					//dekorator za ascii , kao slag u primjeru
public:
	desifrirajASCII(Sifriranje* sifra) : _sifra{ sifra } {
		cout << "desifriranje ASCII dekorator" << endl;
	}
	virtual void desifriraj() const;
	virtual map<char, int> sifra() const { return Sifriranje; }					//za unos slova koja ovdje sifriramo i vracamo mapu sa siframa
	virtual string ipisiSifru(map<char, int> mapa) const { return slovoIndex; };		//za ispisivanje sifre iz mape koju smo vratili u funckiji sifra()

private:
	Sifriranje* _sifra;
	map<char, int> Sifriranje;
};

/* ################# dekorator za desifriranje slova ############# */
class desifrirajSLOVA : public Dodatak {						//dekorator za slova , kao mlijeko u primjeru
public:
	desifrirajSLOVA(Sifriranje* sifra) : _sifra{ sifra } {
		cout << "desifriranje slova dekorator" << endl;
	}
	virtual void desifriraj() const;
	virtual map<char, int> sifra() const { return Sifriranje; }					//za unos slova koja ovdje sifriramo i vracamo mapu sa siframa
	virtual string ipisiSifru(map<char, int> mapa) const { return slovoIndex; };		//za ispisivanje sifre iz mape koju smo vratili u funckiji sifra()

private:
	Sifriranje* _sifra;
	map<char, int> Sifriranje;
};


/* za ASCII METODA*/
void desifrirajASCII::desifriraj() const {

	map<string, string> Desifriranje;							//mapa u koju spremamo desifrirani tekst
	ifstream ifile;
	string filename = "sifriranje.txt";
	ifile.open(filename.c_str());

	int x = 0;
	string a;
	while (getline(ifile, a))								//provjeravamo imaju li ascII sifre u sifriranje.txt 2 ili 3 znaka
	{
		if (stoi(a.substr(4, 3)) > 99) {
			Desifriranje[a.substr(0, 1)] = a.substr(4, 3);		//punimo mapu ako je sifra od 3 znaka
		}
		if (stoi(a.substr(4, 3)) < 100) {
			Desifriranje[a.substr(0, 1)] = a.substr(4, 2);		//punimo mapu ako je sifra od 2 znaka
		}
	}

	for (map<string, string>::iterator ii = Desifriranje.begin(); ii != Desifriranje.end(); ++ii)
	{
		cout << (*ii).second;									//ispisujemo sifrirane znakove u obliku 1244551122
	}
	cout << endl;

	char moj;
	int brojX;
	for (map<string, string>::iterator ii = Desifriranje.begin(); ii != Desifriranje.end(); ++ii)
	{
		brojX = stoi((*ii).second);								//pretvaramo stringove iz mapeu intove
		moj = (char)brojX;										//dobivene intove pretvaramo u charactere
		cout << moj;											//ispisujemo desifrirana slova
	}
	cout << endl;
}


/*za slova metoda*/
void desifrirajSLOVA::desifriraj() const {
	string line, linija, desifrirano;
	string sifra;
	int velicina = 2, brojac = 0, i = 0;
	ifstream pretraga;

	pretraga.open("MojSifriraniText.txt");							//file u kojem se nalazi sifrirani tekst iz funkcije sifra

	getline(pretraga, sifra);

	map<int, string> mapaZaDesifriranje;							//mapa u koju ce se spremati sifrirana slova

	while (sifra.length() >= velicina) {
		mapaZaDesifriranje[i] = sifra.substr(brojac, 2);			//vucemo sifre iz datoteke u mapu jednu po jednu
		velicina += 2;
		brojac += 2;
		i++;
	}
	pretraga.close();

	cout << "Ispis desifriranih slova: " << endl;
	for (map<int, string>::iterator ii = mapaZaDesifriranje.begin(); ii != mapaZaDesifriranje.end(); ++ii)
	{
		pretraga.open("sifriranjeMoj.txt");							//po svakom kljucu u mapi pretrazujemo njegovu vrijednost
		if (pretraga.is_open())										//u datoteci te ispisujemo vrijednost iste
		{

			while (getline(pretraga, linija)) {
				if (linija.find((*ii).second) != string::npos) {
					cout << linija.substr(0, 1);
				}
			}
			pretraga.close();
		}
	}
	cout << endl;
}