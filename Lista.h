#pragma once
using namespace std;
#include <vector>
#include <string>
#include <iostream>
class Lista
{
private:
    vector<string> vv;
public:
	Lista(); //jeden konstruktor
    Lista(int ile); //drugi konstruktor - wype�nia wektor liczbami 0...ile-1
    ~Lista(); //destruktor
	void wydruk(); //wypisuje zawarto�� wektora
private:
	virtual string formatowanie(string txt_p); //metoda u�ywana podczas drukowania
 };

