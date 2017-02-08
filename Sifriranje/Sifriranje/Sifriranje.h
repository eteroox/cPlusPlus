#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Sifriranje {									//glavna classa kao napitak u primjeru
public:
	virtual string ipisiSifru(map<char, int> mapa) const { return slovoIndex; }
	//virtual string slovo() const { return slovoIndex; }
	virtual void desifriraj() const { }
	virtual map<char, int> sifra() const = 0;
protected:
	string slovoIndex;
};

class Slova : public Sifriranje {						//clasa koja nasljeduje glavnu , kao kapucino
public:
	Slova() {
		slovoIndex = "Unosimo slova koje ce se sifrirati: ";
	}
	virtual map<char, int> sifra() const;						//za unos slova koja ovdje sifriramo i vracamo mapu sa siframa
	virtual string ipisiSifru(map<char, int> mapa) const;		//za ispisivanje sifre iz mape koju smo vratili u funckiji sifra(),te upis u file
	virtual void desifriraj() const { }							//za desifriranje sifriranog zapisa u filu
protected:
	Sifriranje* _sifriranje;
};

map<char, int> Slova::sifra() const {
	int sifrirano;

	map<char, int> MojaMapa;						//mapa u koju se upisuju sifrirana slova te koja se kasnije vraca na ispis na
	int brojac = 0;									//ekran te za upis u datoteku
	string line;
	string MojeSlovo;
	ifstream stream;
	bool flag = true;

	while (flag) {
		cout << "Unesite slovo koje zelite sifrirati: ";
		cin >> MojeSlovo;
		if (MojeSlovo != "exit") {
			"\n";
			stream.open("sifriranjeMoj.txt");				//datoteka koja sadrzi popis slova i njihovih sifri
			if (stream.is_open())
			{

				while (getline(stream, line)) {					// nadodavanje novog sifriranog slova u svakoj iteraciji
					if (line.find(MojeSlovo) != string::npos) {
						cout << line.substr(4, 2) << endl;
						sifrirano = stoi(line.substr(4, 2));
						MojaMapa[brojac] = sifrirano;
						brojac++;
					}
				}
				stream.close();
			}
		}
		if (MojeSlovo == "exit") {
			flag = false;
		}
	}
	return MojaMapa;								//mapa se vraca da bi se kasnije koristila sa funkcijom ispisiSifru
}

string Slova::ipisiSifru(map<char, int> mapa) const {			//funkcija koja uz pomoc vracene mape ispisuje sifru te ju unosi u file

	char slova = 0;
	string sifra;
	ofstream ofile;
	string filename = "MojSifriraniText.txt";						//file u kojem se nalazi sifrirani text
	ofile.open(filename);

	cout << "Ispis sifriranih slova: " << endl;
	for (map<char, int>::iterator ii = mapa.begin(); ii != mapa.end(); ++ii)	//iterira se kroz vracenu mapu
	{
		cout << (*ii).second;
		ofile << (*ii).second;										//upisujemo sifru u file
		slova = slova + (char)(*ii).second;
		sifra = slova;												//zapisujemo sifru u string
	}

	return sifra;												//vracamo string
}

/*staro desifriranje di nisam dekorator koristio*/

/*
void Slova::desifriraj() const {
	string line,linija, desifrirano;
	string sifra;
	int velicina=2,brojac=0,i=0;
	ifstream pretraga;

	pretraga.open("MojSifriraniText.txt");
	
	getline(pretraga, sifra);

	map<int, string> mapaZaDesifriranje;

	while (sifra.length() >= velicina) {
		mapaZaDesifriranje[i] = sifra.substr(brojac, 2);
		velicina += 2;
		brojac += 2;
		i++;
	}
	pretraga.close();

	cout << "Ispis desifriranih slova: " << endl;
	for (map<int, string>::iterator ii = mapaZaDesifriranje.begin(); ii != mapaZaDesifriranje.end(); ++ii)
	{
		pretraga.open("sifriranjeMoj.txt");
		if (pretraga.is_open())
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
*/