#pragma once
#include "Lista.h"
class ListaSformatowana :
	public Lista
{
public:
	ListaSformatowana(int ile) : Lista(ile) {};
private:
	string pomnozenieZnaku(char ch, int ileRazy);
	string formatowanie(string txt_p);
};

