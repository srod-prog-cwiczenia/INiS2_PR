// ProjektNr1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "Lista.h"
#include "ListaSformatowana.h"
#include "CzytaczePlikow.h"

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
		/*
		* @wersja 1 - oznacza obliczenie sumy kontrolnej przy użyciu klasy string
		* @wersja 2 - oznacza obliczenie sumy kontrolnej przy użyciu char *
		*/
		unsigned char suma = 13;
		const bool zadanyParametr = !lancuch.empty();
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
				//jak zrobić zamianę (=rzutowanie) char* na string? 
				//odp: string txt = (string)str;
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
		} while (true);
		return suma;
	}
	/*
	  zadanie: rozszerzyć działanie tego Factory
	  przyjmując że jak ktoś poda parametr unsigned int to
	  znaczy jaką długość ma mieć generowany łańcuch.
	  Jak nie poda to długość ma być jak do tej pory (losowa).
	  Zadanie wykonane.
	*/
	constexpr auto DLUGOSC_DOMYSLNA = -1;
	string losowyLancuchFactory(unsigned int dlugosc = DLUGOSC_DOMYSLNA) {
		const unsigned int ile = 
			(dlugosc == DLUGOSC_DOMYSLNA ? rand() % 1000 + 10 : dlugosc);
		string rezultat;
		for (unsigned int j = 0; j < ile; j++) {
			rezultat += (char)(32 + rand() % 95);
		}
		return rezultat;
	}
	void testyJednostkowe() {
		for (string txt : {"Jeden_dwa_trzy", "Ala_ma_kota", 
			"Inny test"}) {
			assert(zadaniaZeWskaznikow(1, txt) == zadaniaZeWskaznikow(2, txt));
		}
		for (unsigned int licznik = 0; licznik < 10000; licznik++) {
			string txt = losowyLancuchFactory();
			assert(zadaniaZeWskaznikow(1, txt) == zadaniaZeWskaznikow(2, txt));
		}
		cout << "Wszystkie testy [ OK ].\n";
	}
	void kopiowanieLancuchow() {
//TODO: ten łańcuch skopiować niskopoziomowo na inny tak by można
		//było go modyfikować
		string lancuch = losowyLancuchFactory(50);
		//pierwszy sposób, nienadzwyczajny :) :
		char kopia1[1000]; //tablica tysiąca znaków 
				
#ifdef KOMPILATOR_CPP_VISUAL
		strcpy_s(kopia1, lancuch.c_str());
#else
		strcpy(kopia, lancuch.c_str());
#endif
		cout << kopia1 << endl;
		//drugi sposób - zaalokować odpowiednią ilość pamięci na dane:
		//wskazówka użyć pary malloc i free.
		char* kopia2 = (char*)malloc(lancuch.length() + 1); // + 1 bo na znak \0 na końcu
		//uwaga: malloc tworzy wskaźnik ,,nieokreślonego typu'' void *,
		//jest to tak zwany wskaźnik generyczny
		assert(kopia2 && "Przypuszczalnie zabraklo pamieci dla kopia2");
#ifdef KOMPILATOR_CPP_VISUAL
		strcpy_s(kopia2, lancuch.length() + 1, lancuch.c_str()); 
#else
		strcpy(kopia2, lancuch.c_str());
#endif
		cout << kopia2 << endl;
		free(kopia2);
	}
	void klasyAbstrakcyjne() {
		/*implementacja tego interfejsu ma działac tak:
		  CzytaczPliku *cp = new CzytaczPliku("C:\\pliczek.txt");
		  while (!cp->koniecPliku()) {
			char znak = cp->getZnak();
		  }
		  delete cp;
		*/
		cout << "Zawartość pliku przeczytana przez CzytaczPliku1 : " << endl;
		CzytaczePlikow::CzytaczPliku1* cp1 = new CzytaczePlikow::CzytaczPliku1("pliczek.txt");
		while (!cp1->koniecPliku()) {
			char znak = cp1->getZnak();
			cout << znak;
		}
		/*
		TODO: implementacja czytacza działa,
		ale na końcu przeczytanego pliku pojawia się dodatkowy znak,
		wyjaśnić dlaczego. */
		delete cp1;
		cout << endl;

		/*,,tymczasowy'' sposób na ,,załatanie'' bolączki
		opisanej w TODO powyżej */
		cout << "Zawartość pliku przeczytana przez CzytaczPliku1 ale z"
			" ''ucięciem zbędnego ostatniego znaku) : " << endl;
		cp1 = new CzytaczePlikow::CzytaczPliku1("pliczek.txt");
		while (!cp1->koniecPliku()) {
			char znak = cp1->getZnak();
			if (!cp1->koniecPliku())
				cout << znak;
		}
		delete cp1;

		cout << "Zawartość pliku przeczytana przez CzytaczPliku2 (fstream) : " << endl;
		CzytaczePlikow::CzytaczPliku2* cp2 = new CzytaczePlikow::CzytaczPliku2("pliczek.txt");
		while (!cp2->koniecPliku()) {
			char znak = cp2->getZnak();
			cout << znak;
			//zdjąć komentarz aby ujrzeć
			//kody ASCII znaków: cout << ":" << (unsigned short int)(znak) << " ";
		}
		delete cp2;

		cout << endl;

	}
	void przykladNaDodawanieLiczbyDoLancucha() {
		int liczba = 7;
		cout << "To jest lancuch char* " << endl;
		// efekt nie jest taki jakim go byśmy oczekiwali:
		cout << "To jest lancuch char* " + liczba << endl;
		/*for (int ii = 0; ii < 15; ii++) {
			cout << "To jest lancuch char* " + ii << endl;
		}*/ // to jest test wielu przesunięć wskaźnika na początek łańcucha
		//teraz powinno być dobrze:
		cout << "To jest lancuch char* " + to_string(liczba) << endl;
		cout << "To jest lancuch char* " << liczba << endl;
	}

	void przeladowanieOperatorow() {
		//TODO:
		/*
		1. zdefiniowac strukture (słowo kluczowe struct) Osoba [DONE - patrz define.h]
		2. dodać do niej konstruktor [DONE];
		3. przeciążyć operatory: rzutowania (string) i porównania : < [DONE]
		4. TODO w domu: przeciążyć jeszcze ! i inne pozostałe
		   operatory porównania: >, ==, <=, >=, !=
 	    5. stworzyć kontener map<Osoba, double> i sprawdzić
		   że nieodzowne jest przeciążenie operatora < na stukturę Osoba.
		*/
		Osoba oso1("Adam", "Kowalski", "Sloneczna", 7);
		Osoba oso2 = { "Anna", "Kowalska", "Sloneczna", 7 }; //konstruktor kopiujący
		Osoba oso3 = oso1;
		oso3.nazwisko = "Koralewski";
		/*można też tak tworzyć tablice obiektów: */
		Osoba tabOso[2] = { {"Dorota", "Nowak", "Przytulna", 23}, 
			{"Damian", "Nowak", "Przytulna", 23} };
		//test rzutowania (string)
		cout << "Osoba 1: " << (string)oso1 << endl;
		//test przeładowania !
		assert (!oso1 == false);
		assert (!Osoba("", "", "", 0));
		//test przeładowania < :
		assert(oso2 < oso1);
		assert(!(oso1 < oso2));
		//test przeładowania ==:
		assert(!(oso1 == oso2));
		assert (oso1 == Osoba("Adam", "Kowalski", "Sloneczna", 7));
		cout << "TESTY PRZESZLY POMYŚLNIE\n";
	}
};
//=======================
int main()
{
	srand((int)time(NULL)); //zainicjowanie generatora liczb losowych
	do {
		cout << "1. Zadania z obiektow (Lista, ListaSformatowana)\n"
		  "2. Zadania ze wskaznikow (suma kontrolna przez string)\n"
		  "3. Zadania ze wskaznikow (suma kontrolna przez char*)\n"
		  "4. Kopiowanie łańcucha\n"
		  "5. Autotesty jednostkowe zadania ze wskaźników \n"
		  "6. Zadania z klas abstrakcyjnych (klasa CzytaczPlikuAbs i jej implementacje)\n"
		  "7. Przykład na błąd podczas rzutowania int do łańcucha\n"
		  "8. Zadania z przeładowania operatorów (testy jednostkowe przeładowań)\n"
		  "0. Koniec\n";
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
			zadania::kopiowanieLancuchow();
			break;
		}
		case '5': {
			zadania::testyJednostkowe();
			break;
		}
		case '6': {
			zadania::klasyAbstrakcyjne();
			break;
		}
		case '7': {
			zadania::przykladNaDodawanieLiczbyDoLancucha();
			break;
		}
		case '8': {
			zadania::przeladowanieOperatorow();
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
