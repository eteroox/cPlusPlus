#pragma once
#include "Include.h"

class Kalendar {
protected:
	string biljeska, datum, dan, mjesec, godina;
public:
	void funkcije() {
		int unos;
		cout << "Za dodavanje nove biljeske unesite 1 , za pretragu biljezaka 2, za brisanje 3" << endl;
		cin >> unos;

		switch (unos)
		{
		case 1:
			unesiBiljesku();
			break;
		case 2:
			pretraziKalendar();
			break;
		case 3:
			izbrisiBiljesku();
			break;
		default:
			unesiBiljesku();
			break;
		}
	}
	void unesiBiljesku() {
		ofstream out_data("kalendar.txt", ios_base::app);

		cout << "Unesite 'exit' u datum za povratak u prethodni meni " << endl;
		cout << "Unesite biljesku: ";
		cin.ignore();
		getline(cin, biljeska);
		cout << "Unesite datum u obliku dd/mm/gggg: ";
		cin >> datum;

		if (datum != "exit") {
			dan = datum.substr(0, 2);
			mjesec = datum.substr(3, 2);
			godina = datum.substr(6, 4);

			"\n";
			cout << "dodali smo novu biljesku: " << dan << "/" << mjesec << "/" << godina << " ==> " << biljeska << endl;

			out_data << dan << "/" << mjesec << "/" << godina << " " << biljeska << "\r\n";
			out_data.close();
			unesiBiljesku();
		}
		else {
			"\n";
			funkcije();
		}
	}

	void izbrisiBiljesku() {
		vector<string> file;
		string temp;

		ifstream infile("kalendar.txt");

		while (!infile.eof())
		{
			getline(infile, temp);
			file.push_back(temp);
		}
		
		infile.close();

		string item;

		for (int n = 0; n < file.size(); n++) {
			cout << file[n] << endl;
		}

		cout << "Unesite 'exit' za povratak u prethodni meni " << endl;
		cout << "Upisite datum za koji zelite izbrisati sve biljeske ili datum i jedinstveni uzorak prvih par rijeci biljeske za brisanje jedne biljeske  : ";
		cin.ignore();
		getline(cin, item);

		if (item == "exit") {
			funkcije();
		}

		for (int i = 0; i < (int)file.size(); ++i)
		{
			if (file[i].substr(0, item.length()) == item)
			{

				file.erase(file.begin() + i);
				cout << "biljeska za datum " << item << " je obrisana" << endl;
				cout << "------------" << endl;
				//i = 0; // Reset search
			}
		}
		ofstream out("kalendar.txt", ios::out | ios::trunc);

		for (vector<string>::const_iterator i = file.begin(); i != file.end(); ++i)
		{
			out << *i << endl;
		}
		out.close();
		izbrisiBiljesku();
	}

	void pretraziKalendar() {

		string line;
		string slova;
		ifstream pretraga;

		cout << "Unesite 'exit' za povratak u prethodni meni " << endl;
		cout << "Pretrazite po kljucnoj rijeci ili datumu ";
		cin >> slova;
		if (slova != "exit") {
			"\n";
			pretraga.open("kalendar.txt");
			if (pretraga.is_open())
			{

				while (getline(pretraga, line)) {
					if (line.find(slova) != string::npos) {
						cout << line << endl;
					}
				}
				cout << slova << " nije pronaden niti jedan rezultat ili ih vise nema" << endl;
				cout << "----------------------------------" << endl;
				pretraga.close();
				pretraziKalendar();
			}
		}
		else {
			"\n";
			funkcije();
		}
	}
};