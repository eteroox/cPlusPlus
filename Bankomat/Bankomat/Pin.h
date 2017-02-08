#pragma once
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#include "Include.h"

class PristupBankomatu {
public:
	virtual string pinKartice() const = 0 ;
	virtual void pregledStanja(string jmbg) const= 0 ;
	virtual void podizanjeNovaca(string jmbg) const= 0 ;
	virtual void depozitNovaca(string jmbg) const= 0 ;
};


class PodatkovnaKomponenta : public PristupBankomatu {
public:
	string pinKartice() const;
	void pregledStanja(string jmbg) const;
	void podizanjeNovaca(string jmbg) const;
	void depozitNovaca(string jmbg) const;
};

class Bankomat {
public:
	Bankomat(PodatkovnaKomponenta* po) : pristup { po }{
		pristup = po;
	}
	string pin() const {
		pristup->pinKartice();
		return "string";
	}
	void stanje(string jmbg) const {
		pristup->pregledStanja(jmbg);
	}
	void podizanje(string jmbg) const {
		pristup->podizanjeNovaca(jmbg);
	}
	void depozit(string jmbg) const {
		pristup->depozitNovaca(jmbg);
	}
protected:
	PristupBankomatu* pristup;
};


/*##################################### Pin kartice ###################################################*/
string PodatkovnaKomponenta::pinKartice() const {
	ifstream stream;
	int pokusajUnosaPina=1, odabir;
	string jmbg = "0119012966", sifraDohvacena,upisanaSifra, line;
	Kontroler k;
	Bankomat* banka = new Bankomat(new PodatkovnaKomponenta);

	if (jmbg != "exit") {
		"\n";
		stream.open("accounti.txt");						//na temelju jmbga se dohvaca sifra
		if (stream.is_open())
		{

			while (getline(stream, line)) {
				if (line.find(jmbg) != string::npos) {
					sifraDohvacena = line.substr(11, 4);
				}
			}
			stream.close();
		}
		while (pokusajUnosaPina < 4 && sifraDohvacena != upisanaSifra) {			//unosi se sifra te se usporeduje sa izvadenom
			cout << "(pokusaj " << pokusajUnosaPina << " od 3) Unesite pin :";
			cin >> upisanaSifra;
			pokusajUnosaPina++;
		}
		if (pokusajUnosaPina == 4) {
			k.postavi_stanje(k.KARTICAZABLOKIRANA);							//ako je broj pokusaja premasio 3 kartica blokirana
			k.prikaziStanje();
		}else {
			cout << " 1)Pregled stanja, 2)Preuzimanje novca, 3)Depozit novaca ";
			cin >> odabir;
			switch (odabir) {
			case 1:
				banka->stanje(jmbg);						//jmbg prosljedujemo dalje kako bi dobili ostale informacije iz njega
				break;
			case 2:
				banka->podizanje(jmbg);
				break;
			case 3:
				banka->depozit(jmbg);
				break;
			default:
				banka->stanje(jmbg);
			}
		}
	}
	return jmbg;
}


/*##################################### Pregled stanja ###################################################*/
void PodatkovnaKomponenta::pregledStanja(string jmbg) const {
	srand(time(NULL));
	int brojRacuna = rand() % 1000 + 100;
	ifstream infile;
	ofstream ofile;
	string linija, line;
	string mojString, brojKartice;
	string filename = "C:/Users/Denis/Documents/Visual Studio 2015/Projects/5.vjezba/Bankomat/Bankomat/transakcije/" + jmbg + ".txt";
	infile.open("accounti.txt");

	if (infile.is_open())
	{

		while (getline(infile, linija)) {
			if (linija.find(jmbg) != string::npos) {
				brojKartice = linija.substr(16, 12);					//broj kartice od korisnika na zadanom jmbgu
			}
		}
		infile.close();
	}

	infile.open(filename);

	if (infile.is_open())
	{

		while (getline(infile, line)) {
			if (line.find(brojKartice) != string::npos) {			//dohvacamo podatke o zadnjoj transakciji i spremamo ih u string
				mojString = line;
			}
		}
		infile.close();
	}

	map<int, string> mapaStanja;
	int brojac=0;

	istringstream iss(mojString);
	string word;
	while (iss >> word) {
		mapaStanja[brojac] = word;								//loadamo rijec po rijec iz stringa u mapu
		brojac++;
	}

	cout << endl;

	Kontroler k;
	k.postavi_stanje(k.PREGLEDSTANJA);
	k.prikaziStanje();
	k.postavi_stanje(k.PRINTANJERACUNA);
	k.prikaziStanje();
																		//ispisujemo stanje racuna
	cout << "Broj racuna : " << mapaStanja[4] << endl;
	cout << "Kartica: " << mapaStanja[5] << endl;
	cout << "Stanje racuana je: " << mapaStanja[0] << "kn" << endl;
	cout << "Zadnja transakcija je obavljena datuma: " << mapaStanja[1] << " u " << mapaStanja[2] << " sati" << endl;
	cout << "Vrsta transakcije: " << mapaStanja[3] << endl;


	time_t theTime = time(NULL);
	struct tm *aTime = localtime(&theTime);

	int day = aTime->tm_mday;
	int month = aTime->tm_mon + 1;
	int year = aTime->tm_year + 1900;
	int Hour = aTime->tm_hour;
	int Min = aTime->tm_min;
	int Sec = aTime->tm_sec;

	ofile.open(filename, ios_base::app);
																						//radimo zapis o transakciji
	ofile << mapaStanja[0] << " " << day << "/" << month << "/" << year << " "
		<< Hour << ":" << Min << ":" << Sec << " "
		<< "PregledStanja" << " S" << brojRacuna << " " << brojKartice << endl;

	ofile.close();
	k.postavi_stanje(k.KARTICAVADENJE);
	k.prikaziStanje();
}


/*##################################### Podizanje novaca ###################################################*/
void PodatkovnaKomponenta::podizanjeNovaca(string jmbg) const {
	srand(time(NULL));
	int brojRacuna = rand() % 1000 + 100;
	string linija, brojKartice, line, mojString;
	ifstream infile;
	ofstream ofile;
	string filename = "C:/Users/Denis/Documents/Visual Studio 2015/Projects/5.vjezba/Bankomat/Bankomat/transakcije/" + jmbg + ".txt";
	infile.open("accounti.txt");

	if (infile.is_open())
	{

		while (getline(infile, linija)) {
			if (linija.find(jmbg) != string::npos) {
				brojKartice = linija.substr(16, 12);					//broj kartice od korisnika na zadanom jmbgu
			}
		}
		infile.close();
	}

	infile.open(filename);

	if (infile.is_open())
	{

		while (getline(infile, line)) {
			if (line.find(brojKartice) != string::npos) {			//dohvacamo podatke o zadnjoj transakciji i spremamo ih u string
				mojString = line;
			}
		}
		infile.close();
	}

	map<int, string> mapaStanja;
	int brojac = 0,razlika=0;
	int podize;
	bool flag = true;

	istringstream iss(mojString);
	string word;
	while (iss >> word) {
		mapaStanja[brojac] = word;									//loadamo rijec po rijec iz stringa u mapu
		brojac++;
	}

	Kontroler k;
	k.postavi_stanje(k.PODIZANJENOVACA);
	k.prikaziStanje();

	while (flag) {								//provijerava se ima li korisnik dovoljan iznos na racunu(minus nije dozvoljen)
		cin >> podize;
		if (podize == 100 || podize == 200 || podize == 500 || podize == 1000 || podize == 2000 || podize == 5000 || podize == 10000) {
			if (podize <= stoi(mapaStanja[0])) {
				razlika = stoi(mapaStanja[0]) - podize;
				flag = false;
			}
			else {
				cout << "Nedovoljno novaca na racunu" << endl;
			}
		}
		else {
			cout << "Krivi unos" << endl;
		}
	}

		time_t theTime = time(NULL);
		struct tm *aTime = localtime(&theTime);

		int day = aTime->tm_mday;
		int month = aTime->tm_mon + 1;
		int year = aTime->tm_year + 1900;
		int Hour = aTime->tm_hour;
		int Min = aTime->tm_min;
		int Sec = aTime->tm_sec;
																//ako ima dovoljan iznos ispisuje mu se racun
		cout << endl;
		k.postavi_stanje(k.PRINTANJERACUNA);
		k.prikaziStanje();
		cout << "Broj racuna : " << brojRacuna << endl;
		cout << "Kartica: " << mapaStanja[5] << endl;
		cout << "Podignuto je: " << podize << "kn" << endl;
		cout << "Stanje racuana je: " << razlika << "kn" << endl;
		cout << "Vrijeme obavljanja transakcije: " << day << "/" << month << "/" << year << " u " << Hour << ":" << Min << ":" << Sec << " sati" << endl;
		cout << "Vrsta transakcije: " << "Podizanje novaca" << endl;

		ofile.open(filename, ios_base::app);
																				//sprema se informacija o novom stanju i transakciji
		ofile << razlika << " " << day << "/" << month << "/" << year << " "
			<< Hour << ":" << Min << ":" << Sec << " "
			<< "Podizanje" << " P" << brojRacuna << " " << brojKartice << endl;

		ofile.close();
		k.postavi_stanje(k.KARTICAVADENJE);
		k.prikaziStanje();
}


/*########################################## Depozit ##################################################################*/
void PodatkovnaKomponenta::depozitNovaca(string jmbg) const {
	int uplata,trenutnoStanje=0;
	srand(time(NULL));
	int brojRacuna = rand() % 1000 + 100;
	string line, brojKartice;
	int strpos = line.find(" ");
	ofstream ofile;
	ifstream infile;
	string filename = "C:/Users/Denis/Documents/Visual Studio 2015/Projects/5.vjezba/Bankomat/Bankomat/transakcije/"+jmbg+".txt";

	infile.open("accounti.txt");				//pretrazujemo broj kartice po jmbgu
	if (infile.is_open())
	{

		while (getline(infile, line)) {
			if (line.find(jmbg) != string::npos) {
				brojKartice = line.substr(16, 12);		//broj kartice od korisnika na zadanom jmbgu
			}
		}
		infile.close();
	}

	//racunanje stanja uplate
	infile.open(filename);
	if (infile.is_open())
	{
		while (getline(infile, line)) {
			if (line.find(brojKartice) != string::npos) {
				trenutnoStanje = stoi(line.substr(0, strpos));		//stanje na racunu
			}
		}
		infile.close();
	}

	cout << "Koliko novaca uplacujete: ";
	cin >> uplata;

	trenutnoStanje = trenutnoStanje + uplata;	//nakon uplate stanje

	ofile.open(filename, ios_base::app);


	time_t theTime = time(NULL);
	struct tm *aTime = localtime(&theTime);

	int day = aTime->tm_mday;
	int month = aTime->tm_mon + 1;
	int year = aTime->tm_year + 1900; 
	int Hour = aTime->tm_hour;
	int Min = aTime->tm_min;
	int Sec = aTime->tm_sec;

	cout << endl;
	Kontroler k;
	k.postavi_stanje(k.DEPOZITNOVACA);
	k.prikaziStanje();
	k.postavi_stanje(k.PRINTANJERACUNA);
	k.prikaziStanje();
																		//ispis dokaza o uplati (racun)
	cout << "Datuma " << " " << day << "/" << month << "/" << year
		<< " u " << Hour << ":" << Min << ":" << Sec << " sati"
		<< " uplatili ste " << uplata
		<< "kn na racun te vam je sada stanje " << trenutnoStanje
		<< " na kartici " << brojKartice << endl;
																		//upisivanje transakcije u datoteku sa novim stanjem
	ofile << trenutnoStanje << " " << day << "/" << month << "/" << year << " "
		<< Hour << ":" << Min << ":" << Sec << " "
		<< "depozit" << " D" << brojRacuna << " " << brojKartice << endl;

	ofile.close();
	k.postavi_stanje(k.KARTICAVADENJE);
	k.prikaziStanje();
}