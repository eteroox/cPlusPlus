#pragma once

#include "Include.h"

class Kontroler {
public:
	Kontroler() : _sati{ 0 }, _minute{ 0 }, _sekunde{ 0 } {
		_stanje = Stanje::POCETNO;
	}

	void glavna_petlja() {
		while (true) {
			cout << _sati << ":" << _minute << ":" << _sekunde << endl;
			cout << "akcija: ";  cin >> _akcija;

			if (_akcija == "1" && _stanje == Stanje::POCETNO) {
				_stanje = Stanje::BLINKAJ_SATE;
				cout << "blinkaju sati \n";
				int x;
				cin >> x;
				if (x == 2) {
					_stanje = Stanje::POVECAJ_SATE;
					_sati = _sati+1;
				}
				else {
					_stanje = Stanje::POCETNO;
				}
			}
			if (_akcija == "11" && _stanje == Stanje::POCETNO) {
				_stanje = Stanje::BLINKAJ_MINUTE;
				cout << "blinkaju minute \n";
				int x;
				cin >> x;
				if (x == 2) {
					_stanje = Stanje::POVECAJ_MINUTE;
					_minute = _minute+1;
				}
				else {
					_stanje = Stanje::POCETNO;
				}
			}
			if (_akcija == "111" && _stanje == Stanje::POCETNO) {
				_stanje = Stanje::BLINKAJ_SEKUNDE;
				cout << "blinkaju sekunde \n";
				int x;
				cin >> x;
				if (x == 2) {
					_stanje = Stanje::POVECAJ_SEKUNDE;
					_sekunde = _sekunde+1;
				}
				else {
					_stanje = Stanje::POCETNO;
				}
			}
			else {
				_stanje = Stanje::POCETNO;
			}
		}
	}

private:
	enum class Stanje { POCETNO, BLINKAJ_SATE, BLINKAJ_MINUTE, BLINKAJ_SEKUNDE, POVECAJ_SATE, POVECAJ_MINUTE, POVECAJ_SEKUNDE, KRAJ };

	string	_akcija;
	Stanje	_stanje;
	int		_sati;
	int		_minute;
	int		_sekunde;
};