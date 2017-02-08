#pragma once
#include "Sifriranje.h"



class AscII : public Sifriranje {							//clasa koja nasljeduje glavnu , kao kakao 
public:
	AscII() {
		slovoIndex = "Unosimo slova koje ce se sifrirati preko ascii: ";
	}
	virtual map<char, int> sifra() const;						//za unos slova koja ovdje sifriramo i vracamo mapu sa siframa
	virtual string ipisiSifru(map<char, int> mapa) const { return slovoIndex; };		//za ispisivanje sifre iz mape koju smo vratili u funckiji sifra()
	virtual void desifriraj() const {}							//za desifriranje sifriranog zapisa u filu
protected:
	Sifriranje* _sifriranje;
	string slovoIndex;
};


map<char, int> AscII::sifra() const {
	string letter;

	cout << "Unesite text koji želite pretvoriti u ASCII: ";
	getline(cin, letter);										//unosimo slova koja ce se sifrirati preko ascII

	map<char, int> Sifriranje;
	for (int i = 0; i < letter.length(); i++)
	{
		char x = letter.at(i);
		cout << int(x) << endl;
		Sifriranje[x] = int(x);									//spremamo slova u mapu
	}

	ofstream ofile;
	string filename = "sifriranje.txt";						//datoteka gdje ce se zapisati sifrirana slova
	ofile.open(filename.c_str());

	for (map<char, int>::iterator ii = Sifriranje.begin(); ii != Sifriranje.end(); ++ii)
	{
		ofile << ii->first << " = " << ii->second;						//zapisujemo kljuc(slovo koje smo upisali) 
		ofile << "\n";													//i sifrirano slovo u datoteku sifriranje.txt
		cout << (*ii).first << ": " << (*ii).second << endl;
	}

	return Sifriranje;									//vracamo mapu kako bi je mogli koristiti u drugim funkcijama
}



/*staro desifriranje di nisam dekorator koristio*/


/*
void AscII::desifriraj() const {

	map<string, string> Desifriranje;
	ifstream ifile;
	string filename = "sifriranje.txt";
	ifile.open(filename.c_str());

	int x = 0;
	string a;
	while (getline(ifile, a))
	{
		if (stoi(a.substr(4, 3)) > 99) {
			Desifriranje[a.substr(0, 1)] = a.substr(4, 3);
		}
		if (stoi(a.substr(4, 3)) < 100) {
			Desifriranje[a.substr(0, 1)] = a.substr(4, 2);
		}
	}

	for (map<string, string>::iterator ii = Desifriranje.begin(); ii != Desifriranje.end(); ++ii)
	{
		cout << (*ii).second;
	}
	cout << endl;

	char moj;
	int brojX;
	for (map<string, string>::iterator ii = Desifriranje.begin(); ii != Desifriranje.end(); ++ii)
	{
		brojX = stoi((*ii).second);
		moj = (char)brojX;
		cout << moj;
	}
	cout << endl;
}
*/