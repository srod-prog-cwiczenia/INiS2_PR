#pragma once
#include "define.h"
class CzytaczePlikow
{
public:
	class CzytaczPlikuAbs { /*to jest klasa abstrakcyjna (i zarazem
klasa wewnêtrzna, czyli
nie mo¿na tworzyæ jej obiektów, natomiast s³u¿y do definiowania
klas potomnych */
	public:
		virtual char getZnak() = 0;
		virtual bool koniecPliku() = 0;
		CzytaczPlikuAbs(const string& sciezkaDoPliku) {};
		virtual ~CzytaczPlikuAbs() {};
	};
	/*
  stworzyæ interfejs (=klasa abstrakcyjn¹) do pobierania
  zawartoœci pliku znak po znaku.
*/
	class CzytaczPliku : public CzytaczPlikuAbs {
	private:
		FILE* ff = NULL;
	public:
		char getZnak() {
			char znak;
			fread(&znak, 1, 1, ff);
			return znak;
		};
		bool koniecPliku() { return feof(ff); };
		CzytaczPliku(const string& sciezkaDoPliku) :
			CzytaczPlikuAbs(sciezkaDoPliku) {
#ifdef KOMPILATOR_CPP_VISUAL
			fopen_s(&ff, sciezkaDoPliku.c_str(), "rb");
#else
			ff = fopen(sciezkaDoPliku.c_str(), "rb");
#endif 
			//w visualu u¿ywamy raczej fopen_s - lepsza metoda ale
							//ma inn¹ trochê sk³adniê
							/*rb to tryb otwarcia pliku - r - tylko na odczyt,
							b - binarny */
		};
		~CzytaczPliku() { fclose(ff); };
	};
};

