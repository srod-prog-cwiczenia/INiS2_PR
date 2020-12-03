#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <assert.h>
#include <time.h>       
#include <fstream>
#include <algorithm>
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
	string toString() const {/*taka metoda jest w niektórych IDE 
					   tworzona ,,automatycznie'' */
		return imie + " " + nazwisko + " " + adr.ulica + " " + to_string(adr.nr_domu);
	};
	/*prze³adowanie operatora rzutowania: */
	operator string() const { return toString(); };
	/*prze³adowanie operatora negacji: */
	bool operator !() {
		return imie.empty() && nazwisko.empty() &&
			adr.ulica.empty() && adr.nr_domu == 0;
	};
	/* prze³adowanie operatora < */
//	bool operator <(const Osoba& oo) {
		/*inny sposób, ale czy dobry???*/
		//return (string)(*this) < (string)oo;
	/*	if (nazwisko < oo.nazwisko) return true;
		if (nazwisko > oo.nazwisko) return false;
		if (imie < oo.imie) return true;
		if (imie > oo.imie) return false;
		if (adr.ulica < oo.adr.ulica) return true;
		if (adr.ulica > oo.adr.ulica) return false;
		if (adr.nr_domu < oo.adr.nr_domu) return true;
		return false;
	};*/
	friend bool operator < (const Osoba& a, const Osoba& b) {
//taka forma przeci¹¿enia mo¿e zast¹piæ powy¿sz¹ a jest nieodzowna do
//posortowania zawartoœci kontenera map
	if (a.nazwisko < b.nazwisko) return true;
		if (a.nazwisko > b.nazwisko) return false;
		if (a.imie < b.imie) return true;
		if (a.imie > b.imie) return false;
		if (a.adr.ulica < b.adr.ulica) return true;
		if (a.adr.ulica > b.adr.ulica) return false;
		if (a.adr.nr_domu < b.adr.nr_domu) return true;
		return false;
	}
	bool operator ==(const Osoba& oo) const {
		return nazwisko == oo.nazwisko &&
			imie == oo.imie &&
			adr.ulica == oo.adr.ulica &&
			adr.nr_domu == oo.adr.nr_domu;
	}
	bool operator <=(const Osoba& oo) const {
		return *this < oo || *this == oo;
	}
};