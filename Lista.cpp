#include "Lista.h"

Lista::Lista()
{
}

Lista::Lista(int ile) {
	for (int i = 0; i < ile; i++) {
		vv.push_back(to_string(i));
	}
};

Lista::~Lista()
{
}

string Lista::formatowanie(string txt_p)
{
	return txt_p;
}

void Lista::wydruk()
{
	for (string lancuch : vv) {
		cout << formatowanie(lancuch) << "\n";
	}
	/*  poni¿ej jest pêtla dzia³aj¹ca na starej wersji C++:
	for (int i = 0; i < vv.size(); i++)
		cout << vv[i] << "\n"; */
}
