#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include "pocetno.h"
#include "kontroler.h"

using namespace std;

Pocetno::Pocetno(Kontroler* k) : _kontroler{ k } {
	_kontroler = k;
}