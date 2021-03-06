#pragma once
#include "define.h"
class CzytaczePlikow
{
public:
	class CzytaczPlikuAbs { /*to jest klasa abstrakcyjna (i zarazem
klasa wewn�trzna, czyli
nie mo�na tworzy� jej obiekt�w, natomiast s�u�y do definiowania
klas potomnych */
	public:
		virtual char getZnak() = 0;
		virtual bool koniecPliku() = 0;
		CzytaczPlikuAbs(const string& sciezkaDoPliku) {};
		virtual ~CzytaczPlikuAbs() {};
	};
	/*
  stworzy� interfejs (=klasa abstrakcyjn�) do pobierania
  zawarto�ci pliku znak po znaku.
*/
	class CzytaczPliku1 : public CzytaczPlikuAbs {
	private:
		FILE* ff = NULL;
	public:
		char getZnak() {
			char znak;
			fread(&znak, 1, 1, ff);
			return znak;
		};
		bool koniecPliku() { return feof(ff); };
		CzytaczPliku1(const string& sciezkaDoPliku) :
			CzytaczPlikuAbs(sciezkaDoPliku) {
#ifdef KOMPILATOR_CPP_VISUAL
			fopen_s(&ff, sciezkaDoPliku.c_str(), "rb");
#else
			ff = fopen(sciezkaDoPliku.c_str(), "rb");
#endif 
			//w visualu u�ywamy raczej fopen_s - lepsza metoda ale
							//ma inn� troch� sk�adni�
							/*rb to tryb otwarcia pliku - r - tylko na odczyt,
							b - binarny */
		};
		~CzytaczPliku1() { fclose(ff); };
	};
	/*TODO: napisa� CzytaczPliku2 bazuj�cy na fstream */
	class CzytaczPliku2 : public CzytaczPlikuAbs {
	private:
		fstream ff;
	public:
		char getZnak() {
			char znak;
			ff >> znak;
			return znak;
		};
		bool koniecPliku() { return ff.eof(); };
		CzytaczPliku2(const string& sciezkaDoPliku) :
			CzytaczPlikuAbs(sciezkaDoPliku) {
			ff.open(sciezkaDoPliku.c_str(), ios::in); /*tylko na odczyt */
		};
		~CzytaczPliku2() { ff.close(); };
	};
};

