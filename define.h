#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <assert.h>
#include <time.h>       
using namespace std;
//definicje typ�w:
struct Osoba {
	string imie, nazwisko;
	struct Adres {
		string ulica;
		unsigned int nr_domu;
	};
};