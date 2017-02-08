#pragma once
#include "Include.h"


class Lift {
protected:
	int v2 = rand() %20;
public:
	Lift() : _trenutni{ 14 } {
		_stanje = Stanje::STOJI;
	}
	void pozovi() {
		int kat;
		int zeljeni;
		int noviPutnik;
		vector< int > noviDolje;
		vector< int > noviGore;
		cout << "pozovite lift na kat na kojem se nalazite: " << endl;
		cin >> kat;
		while (true) {
			if (kat < 1 || kat > 20) {
				cout << "Zgrada ima od 1 do 20 katova" << endl;
				pozovi();
			}

			/*slucaj da lift bude pozvan ispod kata na kojem se nalazi*/
			if (_trenutni > kat) {
				_stanje = Stanje::IDE_DOLJE;
				for (int i = 0; i + kat <= _trenutni; i++) {
					_stanje = Stanje::IDE_DOLJE;
					cout << "lift je na: " <<_trenutni - i << " katu" << endl;
					cout << "poziva li se lift na novi kat? " << endl;
					cin >> noviPutnik;

					//ukoliko osoba poziva lift koji se krece prema dolje na kat koji je ispod kata na kojem je lift
					if (noviPutnik < _trenutni - i) {
						noviDolje.push_back(noviPutnik);
						cout << "idemo prema katu" << endl;
					}

					//kad lift dode na kat na koji su ga pozivali ljudi dok se kretao prema dolje
					if (find(noviDolje.begin(), noviDolje.end(), _trenutni - i) != noviDolje.end()) {
						cout << "Stigli smo na: " << _trenutni - i << " kat" << endl;
						_stanje = Stanje::STOJI;
						_stanje = Stanje::VRATA_OTVORENA;
						_stanje = Stanje::VRATA_ZATVORENA;
					}
					else {

					}

				}

				/*kad lift dode do zeljenog kata osoba odabire kat na koji zli ici i prebacuje se na funkcije*/
				cout << "Na koji kat zelite ici? " << endl;
				cin >> zeljeni;

					if (kat > zeljeni && zeljeni > 1) {
						ideDolje(kat, zeljeni);
					}
					if (kat < zeljeni && zeljeni < 20) {
						ideGore(kat, zeljeni);
					}
					else {
						cout << "niste odabrali ispravni kat" << endl;
					}
			}

			/*slucaj da lift bude pozvan iznad kata na kojem se nalazi*/
			if (_trenutni < kat) {
				_stanje = Stanje::IDE_GORE;

				for (int i = 0; i + _trenutni <= kat; i++) {
					_stanje = Stanje::IDE_GORE;
					cout << "lift je na: " << _trenutni + i << " katu" << endl;
					cout << "poziva li se lift na novi kat?" << endl;
					cin >> noviPutnik;
					if (noviPutnik > _trenutni + i) {
						noviGore.push_back(noviPutnik);
						cout << "idemo prema katu" << endl;
					}
					if (find(noviGore.begin(), noviGore.end(), _trenutni + i) != noviGore.end()) {
						cout << "Stigli smo na: " << _trenutni + i << " kat" << endl;
						_stanje = Stanje::STOJI;
						_stanje = Stanje::VRATA_OTVORENA;
						_stanje = Stanje::VRATA_ZATVORENA;
					}
					else {

					}
				}

				/*kad lift dode do zeljenog kata osoba odabire kat na koji zli ici i prebacuje se na funkcije*/
				cout << "Na koji kat zelite ici? " << endl;
				cin >> zeljeni;

				if (kat > zeljeni && zeljeni > 1) {
					ideDolje(kat, zeljeni);
				}
				if (kat < zeljeni && zeljeni < 20) {
					ideGore(kat, zeljeni);
				}
				else {
					cout << "niste odabrali ispravni kat" << endl;
				}
			}

			/*slucaj da lift bude pozvan na kat na kojem se nalazi (tj ne poziva se neg se samo ude u njega)*/
			else{
				_stanje = Stanje::STOJI;
				_stanje = Stanje::VRATA_OTVORENA;

				cout << "Na koji kat zelite ici? " << endl;
				cin >> zeljeni;
				_stanje = Stanje::VRATA_ZATVORENA;

				if (kat > zeljeni && zeljeni > 1) {
					ideDolje(kat, zeljeni);
				}
				if (kat < zeljeni && zeljeni < 20) {
					ideGore(kat, zeljeni);
				}
			}
		}
	}

	/*funkcija za slucaj da lift ide dolje*/
	void ideDolje(int k, int z) {
			_stanje = Stanje::IDE_DOLJE;
			for (int brojac = 0; brojac + z <= k; brojac++) {
				cout << k - brojac << endl;
		}
			pozovi();
	}

	/*funkcija za slucaj da lift ide gore*/
	void ideGore(int k, int z) {
			_stanje = Stanje::IDE_GORE;
			for (int brojac = 0; brojac + k <= z; brojac++) {
				cout << k + brojac << endl;
		}
			pozovi();
	}

private:
	enum class Stanje { STOJI, IDE_GORE, IDE_DOLJE,VRATA_OTVORENA,VRATA_ZATVORENA };
	
	string	_akcija;
	Stanje	_stanje;
	int _trenutni;
};