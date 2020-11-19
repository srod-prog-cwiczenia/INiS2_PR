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
	};
};