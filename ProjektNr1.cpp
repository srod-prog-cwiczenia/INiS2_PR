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
			//ćwiczenie: napisać wersję bazującą na wskaźnikach char*
		} while (true);
		return suma;
	}
	/*
	  zadanie: rozszerzyć działanie tego Factory
	  przyjmując że jak ktoś poda parametr unsigned int to
	  znaczy jaką długość ma mieć generowany łańcuch.
	  Jak nie poda to długość ma być jak do tej pory (losowa).
	*/
	constexpr auto DLUGOSC_DOMYSLNA = -1;
	string losowyLancuchFactory(unsigned int dlugosc = DLUGOSC_DOMYSLNA) {
		srand(time(NULL)); //zainicjowanie generatora liczb losowych
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
		//strcpy(kopia, lancuch.c_str());
		strcpy_s(kopia1, lancuch.c_str());
		cout << kopia1 << endl;
		//drugi sposób - zaalokować odpowiednią ilość pamięci na dane:
		//wskazówka użyć pary malloc i free.
		char* kopia2 = (char*)malloc(lancuch.length() + 1); // + 1 bo na znak \0 na końcu
		//uwaga: malloc tworzy wskaźnik ,,nieokreślonego typu'' void *,
		//jest to tak zwany wskaźnik generyczny
		strcpy_s(kopia2, lancuch.length() + 1, lancuch.c_str());
		cout << kopia2 << endl;
		free(kopia2);
	}
	void klasyAbstrakcyjne() {
		/*
		  stworzyć interfejs (=klasa abstrakcyjną) do pobierania
		  zawartości pliku znak po znaku.
		*/
		class CzytaczPlikuAbs { /*to jest klasa abstrakcyjna, czyli 
    nie można tworzyć jej obiektów, natomiast służy do definiowania
	klas potomnych */
		public:
			virtual char getZnak() = 0;
			virtual bool koniecPliku() = 0;
			CzytaczPlikuAbs(const string& sciezkaDoPliku) {};
			virtual ~CzytaczPlikuAbs() {};
		};
		class CzytaczPliku : public CzytaczPlikuAbs {
			//TODO: do oprogramowania next time ;) !!!
		public:
			char getZnak() { return ' '; };
			bool koniecPliku() { return true; };
			CzytaczPliku(const string& sciezkaDoPliku) : 
				CzytaczPlikuAbs(sciezkaDoPliku) {};
			~CzytaczPliku() {};
		};
		/*implementacja tego interfejsu ma działac tak:
		  CzytaczPliku *cp = new CzytaczPliku("C:\\pliczek.txt");
		  while (!cp->koniecPliku()) {
		    char znak = cp->getZnak();
		  }
		  delete cp;
		*/
		CzytaczPliku* cp = new CzytaczPliku("C:\\pliczek.txt");
		while (!cp->koniecPliku()) {
			char znak = cp->getZnak();
		}
		delete cp;
	}
};
//=======================
int main()
{
	do {
		cout << "1. Zadania z obiektow (Lista, ListaSformatowana)\n";
		cout << "2. Zadania ze wskaznikow (suma kontrolna przez string)\n";
		cout << "3. Zadania ze wskaznikow (suma kontrolna przez char*)\n";
		cout << "4. Kopiowanie łańcucha\n";
		cout << "5. Autotesty jednostkowe \n";
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
			zadania::kopiowanieLancuchow();
			break;
		}
		case '5': {
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
