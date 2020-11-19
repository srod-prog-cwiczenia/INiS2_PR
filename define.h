#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <assert.h>
#include <time.h>       
#include <fstream>
using namespace std;
//makra
#ifdef _MSC_VER
  #define KOMPILATOR_CPP_VISUAL
#endif
//definicje typów:
struct Osoba {
	string imie, nazwisko;
	struct Adres {
		string ulica;
		unsigned int nr_domu;
		Adres(string ulica_p, unsigned int nr_domu_p) :
			ulica(ulica_p), nr_domu(nr_domu_p) {};
	} adr;
	Osoba(string imie_p, string nazwisko_p, string ulica_p, unsigned int nr_domu_p) :
		imie(imie_p), nazwisko(nazwisko_p), adr(ulica_p, nr_domu_p) {};
	string toString() {/*taka metoda jest w niektórych IDE 
					   tworzona ,,automatycznie'' */
		return imie + " " + nazwisko + " " + adr.ulica + " " + to_string(adr.nr_domu);
	};
	/*prze³adowanie operatora rzutowania: */
	operator string() { return toString(); };

};