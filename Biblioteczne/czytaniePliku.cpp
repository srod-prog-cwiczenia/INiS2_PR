/*
TODO: sprawdzi� (prze�ledzi�) jak funkcjonuje ta klasa:
ona czyta ca�y bufor z pliku a ,,symuluje'' pobieranie po jednym
elemencie. 
TODO: dorobi� header do tego modu�u, do��czy� do projektu
i napisa� test tego modu�u.
*/
constexpr auto ROZMIAR_BUFORA_TFI = 4096;
constexpr auto POCZATEK_WCZYTYWANIA_TFI = -1;
class TFIn {
	private:
		FILE *fff;
		char buff[ROZMIAR_BUFORA_TFI];
		unsigned int miejsce, liczbaZnakowWBuff;
	public:
		TFIn(const char *nazwaPliku) {
			fff = fopen(nazwaPliku, "rb");
			miejsce = 0;
			liczbaZnakowWBuff = POCZATEK_WCZYTYWANIA_TFI;
		}
		bool plikOK() {
			return !!fff;
		}
		bool get(char* ch) {
			if (liczbaZnakowWBuff == POCZATEK_WCZYTYWANIA_TFI || miejsce == ROZMIAR_BUFORA_TFI) {
				liczbaZnakowWBuff = fread(buff, 1, ROZMIAR_BUFORA_TFI, fff);
        miejsce = 0;
			}
			if (miejsce < liczbaZnakowWBuff) {
				*ch = buff[miejsce++];
				return true;
			} else if (liczbaZnakowWBuff < ROZMIAR_BUFORA_TFI) {
        return false;
			}
		}
		~TFIn() {
			if (fff) fclose(fff);
		}
};
/*
  spos�b u�ycia tej klasy:
    TFIn fin(<scie�ka>)
	 do {
	   char znak;
	   dalej = FIn2->get(&znak);
	   if (dalej) cout << znak;
     } while (dalej);

*/
