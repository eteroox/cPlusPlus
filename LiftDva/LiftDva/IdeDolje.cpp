#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include "kontroler.h"
#include "IdeDolje.h"
#include <vector>
#include <string> 
#include <conio.h>
#include <algorithm>    // std::sort

using namespace std;

IdeDolje::IdeDolje(Kontroler* k) : _kontroler{ k } {
	_kontroler = k;
}

struct myclass {
	bool operator() (int i, int j) { return (i>j); }			//sort po desc orderu
} myobject;


void IdeDolje::kretnjaLifta(int broj,int brojDva) {		//broj = kat na koji se lift zove , brojDva kat na kojem se lift nalazi
														//u pocetnom trenutku
	int katIzvana= broj,noviBroj,dodge=1;
	vector< int > noviDolje;
	string test;
	Kontroler k;
	int katPrijekretanja = brojDva;

	for (int i = katPrijekretanja; broj <= i; i--) {
		if (dodge>1) {									//preskacemo prvi unos jer ga dobijemo preko funkcije
			//cin >> katIzvana;
			getline(cin, test);
			cout << "Lift je na: " << i << " katu" << endl;
			if (test == "") {
				cout << "Lift se ne poziva ..." << endl;			//ako nismo unjeli kat onda se ispisuje
			}
			else {
				katIzvana = stoi(test);							//inace se pridjeljuje vrijednost u varijablu katIzvana
			}
		}
		else {
			katIzvana = broj;
		}
		if (katIzvana < i && katIzvana > 0) {
			cout << "Lift ce stati na zeljenom katu na putu do odredisnog kata" << endl;
			noviDolje.push_back(katIzvana);					//spremanje katova koji su naputu u vector
		}

		//vrtimo petlju sve dok ne dodemo do kraja vektora tj. njegovog zadnjeg clana
		//zatim sortiramo silazno i ispisemo sve katove koji su preostali
		//nakon toga se brisu svi clanovi iz vektora kako bi se ispraznio i mogao dalje koristiti

		if (find(noviDolje.begin(), noviDolje.end(), i) != noviDolje.end() || i == broj) {
			cout << "Stigli smo na zeljeni kat" << endl;
			std::sort(noviDolje.begin(), noviDolje.end(), myobject);
			noviDolje.erase(unique(noviDolje.begin(), noviDolje.end()), noviDolje.end());					//brisem duplikate
			for (std::vector<int>::iterator it = noviDolje.begin(); it != noviDolje.end(); ++it) {
				cout << *it << endl;
				i = *it;
			}
			noviDolje.clear();
		}

		//ako je vektor prazan i ako je kat na koji smo zeljeli doci jednak brojacu biramo
		// gdje osoba koja je zvala kat zeli ici
		if (broj == i && noviDolje.empty())
		{
			k.postavi_stanje(k.STOJI);
			cin >> noviBroj;							//nakon što je lif pokupio osobu koja ga je zvala 
														//bira kat na koji zeli ici
			if (noviBroj > broj) {						//ako je broj koji unese osoba veci od trenutnog kata ide gore
				k.postavi_stanje(k.IDEGORE);
				k.gdjeIde(noviBroj, i);
			}
			else {
				k.postavi_stanje(k.IDEDOLJE);			//inace ide dolje
				k.gdjeIde(noviBroj, i);
			}
		}
		dodge++;
	}
}//kraj funkcije kretnjaLifta




/*
if (find(noviDolje.begin(), noviDolje.end(), i) != noviDolje.end() || i == broj) {
cout << "Stigli smo na zeljeni kat" << endl;
std::sort(noviDolje.begin(), noviDolje.end(), myobject);
for (std::vector<int>::iterator it = noviDolje.begin(); it != noviDolje.end(); ++it) {
cout << *it << endl;
}
}

*/





/*
IdeDolje::IdeDolje(Kontroler* k) : _kontroler{ k } {
	_kontroler = k;
}


void IdeDolje::kretnjaLifta(int broj, int brojDva) {		//broj = kat na koji se lift zove , brojDva kat na kojem se lift nalazi
															//u pocetnom trenutku
	int katIzvana = broj, noviBroj, dodge = 1;
	vector< int > noviDolje;
	Kontroler k;
	int katPrijekretanja = brojDva;

	for (int i = katPrijekretanja; broj <= i; i--) {
		if (dodge>1) {
			cin >> katIzvana;
			cout << "Lift je na: " << i << " katu" << endl;
		}
		else {
			katIzvana = broj;
		}
		if (katIzvana < i && katIzvana > 0) {
			cout << "Lift ce stati na zeljenom katu na putu do odredisnog kata" << endl;
			cout << "unjeli smo kat: " << katIzvana << endl;;
			noviDolje.push_back(katIzvana);					//spremanje katova koji su naputu u mapu
		}
		if (find(noviDolje.begin(), noviDolje.end(), i) != noviDolje.end() || i == broj) {
			cout << "Stigli smo na zeljeni kat" << endl;
			k.postavi_stanje(k.STOJI);
			cin >> noviBroj;							//nakon što je lif pokupio osobu koja ga je zvala 
														//bira kat na koji zeli ici
			if (noviBroj > broj) {						//ako je broj koji unese osoba veci od trenutnog kata ide gore
				k.postavi_stanje(k.IDEGORE);
				k.gdjeIde(noviBroj, i);
			}
			else {
				k.postavi_stanje(k.IDEDOLJE);			//inace ide dolje
				k.gdjeIde(noviBroj, i);
			}
		}
		dodge++;
	}
}//kraj funkcije kretnjaLifta

*/