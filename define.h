#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
//definicje typ�w:
struct Osoba {
	string imie, nazwisko;
	struct Adres {
		string ulica;
		unsigned int nr_domu;
	};
};