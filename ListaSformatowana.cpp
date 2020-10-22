#include "ListaSformatowana.h"

string ListaSformatowana::pomnozenieZnaku(char ch, int ileRazy)
{
	//TODO: przetestowaæ (nie zosta³a przetestowana)
	string res;
	for (int i = 0; i < ileRazy; i++) {
		res += ch;
	};
	return res;
}

string ListaSformatowana::formatowanie(string txt_p)
{
	constexpr auto MAX_LICZBA_ZNAKOW_FORMATOWANIA = 40;
	if (txt_p.length() >= MAX_LICZBA_ZNAKOW_FORMATOWANIA) return txt_p;
	int liczbaZnakow = (MAX_LICZBA_ZNAKOW_FORMATOWANIA - txt_p.length()) / 2;
	return string(liczbaZnakow, '-') + txt_p + 
		string(liczbaZnakow, '-');
}
