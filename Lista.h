#pragma once
#include "define.h"
class Lista
{
private:
	//pola klasy:
    vector<string> vv;	
public:
	//metody klasy:
	Lista(); //jeden konstruktor
    Lista(int ile); //drugi konstruktor - wype³nia wektor liczbami 0...ile-1
    ~Lista(); //destruktor
	void wydruk(); //wypisuje zawartoœæ wektora
private:
	virtual string formatowanie(string txt_p); //metoda u¿ywana podczas drukowania
 };

