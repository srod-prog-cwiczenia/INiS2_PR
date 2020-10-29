// ProjektNr1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "Lista.h"
#include "ListaSformatowana.h"

namespace zadania {
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
		/*
		   UWAGA: jak w C# tworzyliśmy obiekt? Ano tak:
		   Lista li2 = new Lista(5);
		   li2.wydruk();
		*/

		cout << "obiekt klasy ListaSformatowana----------------\n";
		ListaSformatowana* ls = new ListaSformatowana(10);
		ls->wydruk();
		delete ls;
	}
	//-----------------------
	unsigned char zadaniaZeWskaznikow(int wersja, string lancuch = "") {
		// obliczyć sumę kontrolną łańcucha najpierw
		  // za pomocą string a potem używając char *
		unsigned char suma = 13;
		bool zadanyParametr = !lancuch.empty();
		do {
			if (!zadanyParametr) {
				cout << "Podaj napis (\"w\" oznacza wyjście)\n";
				cin >> lancuch;
				if (lancuch == "w") break;
			}
			suma = 13;
			unsigned char pom = 1;

			switch (wersja) {
			case 1:
				for (char znak : lancuch) {
					suma ^= (znak + pom++);
				}
				break;
			case 2: {
				// obliczyć sumę kontrolną łańcucha najpierw
				  // za pomocą string a potem używając char *
				const char* str = lancuch.c_str(); //c_str to rzutowanie string na char*
				while (*str) {
					suma ^= (*str++ + pom++);
				}
				break;
			}
			}
			if (zadanyParametr) {
				break;
			}
			cout << "Suma kontrolna: " << (int)suma << "\n";
			//ćwiczenie: napisać wersję bazującą na wskaźnikach char*
		} while (true);
		return suma;
	}
	void testyJednostkowe() {


	}
};
//=======================
int main()
{
	do {
		cout << "1. Zadania z obiektow (Lista, ListaSformatowana)\n";
		cout << "2. Zadania ze wskaznikow (suma kontrolna przez string)\n";
		cout << "3. Zadania ze wskaznikow (suma kontrolna przez char*)\n";
		cout << "4. Autotesty jednostkowe \n";
		cout << "0. Koniec\n";
		string txt;
		cin >> txt;
		if (txt.empty() || txt[0] == '0') exit(0);
		switch (txt[0]) {
		case '1': {
			zadania::zadaniaZObiektow();
			break;
		}
		case '2': {
			zadania::zadaniaZeWskaznikow(1);
			break;
		}
		case '3': {
			zadania::zadaniaZeWskaznikow(2);
			break;
		}
		case '4': {
			zadania::testyJednostkowe();
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
