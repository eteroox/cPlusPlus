#pragma once
#include "Include.h"

class Login {
protected:
	string username, password;
	string dictionary[1000];

public:
	void Izaberi() {
		cout << "Dobrodosli u kalendar" << endl;
		int broj;
		cout << "Unesite 1 za logiranje ili 2 za registriranje (trenutno nije u funkciji)" << endl;
		cin >> broj;

		if (broj == 1) {
			Ulogiraj();
			Kalendar kalendar;
			kalendar.funkcije();
		}
		if (broj == 2) {
			Registriraj();
			Kalendar kalendar;
			kalendar.funkcije();
		}
	}

	void Ulogiraj(){
		ifstream in_stream;
		map<int, string> mapaUsername;
		map<int, string> mapaPassword;
		string testUsername, testPassword;


		//citanje fila i dodjeljivanje polju
		in_stream.open("login.txt");
		cout << endl;
		if (in_stream.fail())

		{
			cout << "Program je neuspjesno pokrenut \n";
			exit(1);
		}
		else {
			cout << "Program je uspjesno pokrenut" << endl;
		}

		int i = 0;
		while (in_stream >> testUsername >> testPassword)
		{
			mapaUsername[i] = testUsername;
			mapaPassword[i] = testPassword;
			cout << "Username: "<< mapaUsername[i] << " Password: "<<mapaPassword[i] << endl;
			i++;
		}

		int size = i;
		int a=0;
		bool found = false;

		while (found == false)

		{
			//login
			cout << "Unesite username i password" << endl;
			cout << "Username: ";
			cin >> username;
			cout << "Password: ";
			cin >> password;

			for (int b = 0; b < size; b++)
			{
				if (username == mapaUsername[b] && password == mapaPassword[b]) {
					cout << "Username i password su tocni " << endl;
					system("CLS");
					cout << "Ulogiran kao " << username << endl;
					cout << "#############################" << endl;
					found = true;
				}
				else {
					
				}//else
			}//for
		}//while
	}//funkcija

	
	void Registriraj() {
		cout << " Pokrenuli ste funkciju registriraj koja trenutno nije dostupna te ste preusmjereni na logiranje" << endl;
		Ulogiraj();
	}
};//klasa funkcija