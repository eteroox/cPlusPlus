#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include "stoji.h"
#include "kontroler.h"

using namespace std;

Stoji::Stoji(Kontroler* k) : _kontroler{ k } {
	_kontroler = k;
}