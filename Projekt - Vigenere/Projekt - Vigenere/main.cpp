#include <iostream>
#include <cmath>
#include <fstream>
#include "funkcje.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char*argv[])
{
	string sciezka_wejscie, sciezka_wyjscie, sciezka_klucz, wiadomosc, szyfrwiad, klucz;
	int nr_zadanie = 0, klucz_dlugosc = 0;
	

	vector<string> arg(argv, argv + argc);
	
	if (ArgWejscia(argc) == -1) {
		return 0;
	}
	zadanie_prog zadanie = flaga_prog(arg[1]);
	
	if (argc == 8) {
		sciezka(arg[2], arg[3], sciezka_wejscie, sciezka_wyjscie, sciezka_klucz);
		sciezka(arg[4], arg[5], sciezka_wejscie, sciezka_wyjscie, sciezka_klucz);
		sciezka(arg[6], arg[7], sciezka_wejscie, sciezka_wyjscie, sciezka_klucz);
	}
	else if (argc == 6) {
		sciezka(arg[2], arg[3], sciezka_wejscie, sciezka_wyjscie, sciezka_klucz);
		sciezka(arg[4], arg[5], sciezka_wejscie, sciezka_wyjscie, sciezka_klucz);
	}
	else {
		cout << "Niepoprawnie podane argumenty!" << endl;
	}

	switch (zadanie)
	{
	   case zadanie_prog::szyfrowanie: 
	   {
		   odczytaj(sciezka_wejscie, wiadomosc);
		   odczytaj(sciezka_klucz, klucz);
		   szyfruj(wiadomosc, klucz, szyfrwiad);
		   zapisz(sciezka_wyjscie, szyfrwiad);
		   cout << "Zaszyfrowano do pliku: " << sciezka_wyjscie << endl;
		   break;
	   }
	   case zadanie_prog::deszyfrowanie: 
	   {
		   odczytaj(sciezka_wejscie, szyfrwiad);
		   odczytaj(sciezka_klucz, klucz);
		   odszyfruj(szyfrwiad, klucz, wiadomosc);
		   zapisz(sciezka_wyjscie, wiadomosc);
		   cout << "Odszyfrowano do pliku: " << sciezka_wyjscie << endl;
		   break;
	   }
	   case zadanie_prog::lamanie_szyfru:
	   {
		   odczytaj(sciezka_wejscie, szyfrwiad);
		   znajdz_klucz_dlugosc(szyfrwiad, klucz_dlugosc);
		   znajdz_klucz(szyfrwiad, klucz_dlugosc, klucz);
		   odszyfruj(szyfrwiad, klucz, wiadomosc);
		   zapisz(sciezka_wyjscie, wiadomosc);
		   cout << "Zlamano szyfr i zapisano wiadomosc do pliku: " << sciezka_wyjscie << endl;
		   break;
	   }
	   case zadanie_prog::error:
	   {
		   return 0;
	   }
	}   
	return 0;
}