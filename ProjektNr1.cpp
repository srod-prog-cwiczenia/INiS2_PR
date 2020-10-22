// ProjektNr1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "Lista.h"
#include "ListaSformatowana.h"

void zadaniaZObiektow() {
	cout << "obiekt li jako zmienna lokalna----------------\n";
	//obiekt li jako zmienna lokalna:
	Lista li(10);
	li.wydruk();

	cout << "obiekt li2 jako wskaźnik (\"pointer\")----------------\n";

	//obiekt li2 jako wskaźnik ("pointer")
	Lista* li2 = new Lista(5);
	li2->wydruk();
	delete li2;

	cout << "obiekt klasy ListaSformatowana----------------\n";
	ListaSformatowana* ls = new ListaSformatowana(10);
	ls->wydruk();
	delete ls;
}
//-----------------------
void zadaniaZeWskaznikow() {
  // obliczyć sumę kontrolną łańcucha najpierw
	// za pomocą string a potem używając char *
	do {
		cout << "Podaj napis (\"w\" oznacza wyjście)\n";
		string lancuch;
		cin >> lancuch;
		if (lancuch == "w") break;
		unsigned char suma = 13, pom = 1;
	
		for (char znak : lancuch) {
			suma ^= (znak + pom++);
		}
		cout << "Suma kontrolna: " << (int)suma << "\n";
	}
	while (true);
}
//=======================
int main()
{
	do {
		cout << "1. Zadania z obiektow (Lista, ListaSformatowana)\n";
		cout << "2. Zadania ze wskaznikow\n";
		cout << "0. Koniec\n";
		string txt;
		cin >> txt;
		if (txt.empty() || txt[0] == '0') exit(0);
		switch (txt[0]) {
		case '1': {
			zadaniaZObiektow();
			break;
		}
		case '2': {
			zadaniaZeWskaznikow();
			break;
		}
		default:
			break;
		}
	} while (true);
}
// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
