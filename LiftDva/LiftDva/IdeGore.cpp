#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include "IdeGore.h"
#include "kontroler.h"
#include <vector>
#include <string> 
#include <conio.h>
#include <algorithm>    // std::sort

using namespace std;

IdeGore::IdeGore(Kontroler* k) : _kontroler{ k } {
	_kontroler = k;
}

struct myclass2 {
	bool operator() (int i, int j) { return (i<j); }			//sort po asc orderu
} myobjectGore;

void IdeGore::kretnjaLifta(int broj,int brojDva) {
	int katIzvana= broj, noviBroj,dodge=1;
	vector< int > noviGore;
	string test;
	Kontroler k;
	int katPrijekretanja = brojDva;

	for (int i = katPrijekretanja; broj >= i; i++) {
		if(dodge>1){								//preskacemo prvi unos jer ga dobijemo preko funkcije
			//cin >> katIzvana;
			getline(cin, test);
			cout << "Lift je na: " << i << " katu" << endl;
			if (test == "") {
				cout << "Lift se ne poziva ..." << endl;					//ako nismo unjeli kat onda se ispisuje
			}
			else {
				katIzvana = stoi(test);									//inace se pridjeljuje vrijednost u varijablu katIzvana
			}
		}
		else {
			katIzvana = broj;
		}
		if (katIzvana > i && katIzvana < 21) {
			cout << "Lift ce stati na zeljenom katu na putu do odredisnog kata" << endl;
			noviGore.push_back(katIzvana);								//spremanje katova koji su naputu u vector
		}

		//vrtimo petlju sve dok ne dodemo do kraja vektora tj. njegovog zadnjeg clana
		//zatim sortiramo uzlazno i ispisemo sve katove koji su preostali
		//nakon toga se brisu svi clanovi iz vektora kako bi se ispraznio i mogao dalje koristiti

		if (find(noviGore.begin(), noviGore.end(), i) != noviGore.end() || i == broj) {
			cout << "Stigli smo na zeljeni kat" << endl;
			std::sort(noviGore.begin(), noviGore.end(), myobjectGore);
			noviGore.erase(unique(noviGore.begin(), noviGore.end()), noviGore.end());					//brisem duplikate
			for (std::vector<int>::iterator it = noviGore.begin(); it != noviGore.end(); ++it) {
				cout << *it << endl;
				i = *it;
			}
			noviGore.clear();
		}

		//ako je vektor prazan i ako je kat na koji smo zeljeli doci jednak brojacu biramo
		// gdje osoba koja je zvala kat zeli ici
			if (broj == i && noviGore.empty())
			{
				k.postavi_stanje(k.STOJI);
				cin >> noviBroj;
				if (noviBroj > broj) {
					k.postavi_stanje(k.IDEGORE);
					k.gdjeIde(noviBroj, i);
				}
				else {
					k.postavi_stanje(k.IDEDOLJE);
					k.gdjeIde(noviBroj, i);
				}
			}
		dodge++;
	}
}











/*

void IdeGore::kretnjaLifta(int broj,int brojDva) {
	int katIzvana= broj, noviBroj,dodge=1;
	vector< int > noviGore;
	Kontroler k;
	int katPrijekretanja = brojDva;

	for (int i = katPrijekretanja; broj >= i; i++) {
		if(dodge>1){
			cin >> katIzvana;
			cout << "Lift je na: " << i << " katu" << endl;				//poziv na kat izvan lifta dok se lift krece gore
		}
		else {
			katIzvana = broj;
		}
		if (katIzvana > i && katIzvana < 21) {
			cout << "Lift ce stati na zeljenom katu na putu do odredisnog kata" << endl;
			noviGore.push_back(katIzvana);								//spremanje katova koji su naputu u vector
		}
		if (find(noviGore.begin(), noviGore.end(), i) != noviGore.end() || i == broj) {
			cout << "Stigli smo na zeljeni kat" << endl;
			k.postavi_stanje(k.STOJI);
			cin >> noviBroj;
			if (noviBroj > broj) {
				k.postavi_stanje(k.IDEGORE);
				k.gdjeIde(noviBroj, i);
			}
			else {
				k.postavi_stanje(k.IDEDOLJE);
				k.gdjeIde(noviBroj, i);
			}
		}
		dodge++;
	}
}

*/