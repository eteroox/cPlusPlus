#pragma once
#include "Include.h"

namespace Izvjestaji {
	class FinancijskiIzvjestaj {
	protected:
		
	public:
		string datum1Moj, datum2Moj;
		map<string, vector<double>> mjesecni_podaci;
		map<string, vector<double>> godisnji_podaci;
		virtual void prikazi();
	};

	class Troskovi {
	protected:

	public:
		string datum1Moj, datum2Moj;
		map<string, vector<double>> mjesecni_podaci;
		map<string, vector<double>> godisnji_podaci;
		virtual void prikazi();
	};

	void FinancijskiIzvjestaj::prikazi() {

	}

	void Troskovi::prikazi() {

	}
}


class MjesecniIzvjestaj : public Izvjestaji::FinancijskiIzvjestaj , public Izvjestaji::Troskovi{
protected:
	string datum1Moj, datum2Moj;
	map<string, vector<double>> mjesecni_podaci;
public:
	MjesecniIzvjestaj(string datum1, string datum2, map<string, vector<double>> mjesecni_podaci) {
		datum1Moj = datum1;
		datum2Moj = datum2;
		this->mjesecni_podaci = mjesecni_podaci;
	};
	void prikazi();
	void MjesecDatum(int datum);
};

void MjesecniIzvjestaj::prikazi() {

	MjesecniIzvjestaj* mjesec= new MjesecniIzvjestaj(datum1Moj,datum2Moj, mjesecni_podaci);
	string datumPrvi = mjesec->datum1Moj;
	string datumDrugi = mjesec->datum2Moj;
	map<string, vector<double>> mjesecni_podatci_moj = mjesec->mjesecni_podaci;
	
	cout << "Mjesecni izvjestaj" << endl;
	cout << "Broj: MF-25" << endl;
	cout << "Period: " << datumPrvi << " - " << datumDrugi << endl;
	cout << "Izvoz: ";

	int prvi = stoi(datumPrvi.substr(2, 1)); //prvi datum
	int drugi = stoi(datumDrugi.substr(2, 1)); //drugi datum

										   // za slucaj da je mjesec dvoznamenkast
	if (stoi(datumPrvi.substr(2, 2)) == 10 || stoi(datumPrvi.substr(2, 2)) == 11 || stoi(datumPrvi.substr(2, 2)) == 12) {
		prvi = stoi(datumPrvi.substr(2, 2));
	}

	if (stoi(datumDrugi.substr(2, 2)) == 10 || stoi(datumDrugi.substr(2, 2)) == 11 || stoi(datumDrugi.substr(2, 2)) == 12) {
		drugi = stoi(datumDrugi.substr(2, 2));
	}

	int i = prvi;
	int i2 = prvi;

	map<string, vector<double>>::iterator it = mjesecni_podatci_moj.begin(); //za second sam napravio
	map<string, vector<double>>::iterator ik = mjesecni_podatci_moj.begin(); //za first sam napravio
	while (i <= drugi)
	{
		cout << " ";
		MjesecDatum(i);
		cout << ':'
			<< it->second[i] << "kn ";
		cout << ",";
		i++;
	}
	cout << endl;
	cout << "Trosak: ";
	it++;
	while (i2 <= drugi)
	{
		cout << " ";
		MjesecDatum(i2);
		cout << ':'
			<< it->second[i2] << "kn ";
		cout << ",";
		i2++;
	}
	cout << endl;
	cout << "========================================" << endl;
	cout << endl;
}



/*godisnji classa*/
class GodisnjiIzvjestaj : public Izvjestaji::FinancijskiIzvjestaj , public Izvjestaji::Troskovi {
protected:
	string datum1Moj, datum2Moj;
	map<string, vector<double>> mjesecni_podaciMoj;
public:
	GodisnjiIzvjestaj(string datum1, string datum2, map<string, vector<double>> mjesecni_podaci) {
		datum1Moj = datum1;
		datum2Moj = datum2;
		mjesecni_podaciMoj = mjesecni_podaci;
	};
	void prikazi();
	void MjesecDatum(int datum);
};

/* funkcija za prikaz godisnjeg izvjestaja*/
void GodisnjiIzvjestaj::prikazi() {

	GodisnjiIzvjestaj* godina = new GodisnjiIzvjestaj(datum1Moj, datum2Moj, mjesecni_podaciMoj);
	string datumPrvi = godina->datum1Moj;
	string datumDrugi = godina->datum2Moj;
	map<string, vector<double>> godisnji_podatci_moj = godina->mjesecni_podaciMoj;


	cout << "Godisnki izvjestaj" << endl;
	cout << "Broj: GF-25" << endl;
	cout << "Izvjestaj za godinu " << datumPrvi.substr(4, 4) << endl;
	cout << "Izvoz: " << endl;

	map<string, vector<double>>::iterator it = godisnji_podatci_moj.begin(); //za second sam napravio
	map<string, vector<double>>::iterator ik = godisnji_podatci_moj.begin(); //za first sam napravio

	int i = 1;
	int i2 = 1;

	while (i <= 12) {
		cout << " ";
		MjesecDatum(i);
		cout << ':'
			<< it->second[i] << "kn ";
		cout << endl;
		i++;
	}
	cout << "Trosak: " << endl;
	it++;
	while (i2 <= 12)
	{
		cout << " ";
		MjesecDatum(i2);
		cout << ':'
			<< it->second[i2] << "kn ";
		cout << endl;
		i2++;
	}
	cout << "========================================" << endl;
	cout << endl;
}


/*mjesecni izvjestaj datumi*/
void GodisnjiIzvjestaj::MjesecDatum(int datum) {

	switch (datum) {
	case 1:
		cout << "Sijecanj";
		break;
	case 2:
		cout << "Veljaca";
		break;
	case 3:
		cout << "Ozujak";
		break;
	case 4:
		cout << "Travanj";
		break;
	case 5:
		cout << "Svibanj";
		break;
	case 6:
		cout << "Lipanj";
		break;
	case 7:
		cout << "Srpanj";
		break;
	case 8:
		cout << "Kolovoz";
		break;
	case 9:
		cout << "Rujan";
		break;
	case 10:
		cout << "Listopad";
		break;
	case 11:
		cout << "Studeni";
		break;
	case 12:
		cout << "Prosinac";
		break;

	default:
		cout << "Mjesec treba biti od 1-12" << endl;
	}
}

/*godisnji izvjestaj datumi*/
void MjesecniIzvjestaj::MjesecDatum(int datum) {

	switch (datum) {
	case 1:
		cout << "Sijecanj";
		break;
	case 2:
		cout << "Veljaca";
		break;
	case 3:
		cout << "Ozujak";
		break;
	case 4:
		cout << "Travanj";
		break;
	case 5:
		cout << "Svibanj";
		break;
	case 6:
		cout << "Lipanj";
		break;
	case 7:
		cout << "Srpanj";
		break;
	case 8:
		cout << "Kolovoz";
		break;
	case 9:
		cout << "Rujan";
		break;
	case 10:
		cout << "Listopad";
		break;
	case 11:
		cout << "Studeni";
		break;
	case 12:
		cout << "Prosinac";
		break;

	default:
		cout << "Mjesec treba biti od 1-12" << endl;
	}
}