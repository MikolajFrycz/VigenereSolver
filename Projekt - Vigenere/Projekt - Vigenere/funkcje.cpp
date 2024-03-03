#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "funkcje.h"

using namespace std;



int ArgWejscia(const int argc)
{
    if (argc < 3)
    {
       cout <<
           "Nie podano argumentow!"<<endl;
       cout << "Program uruchamiany jest z linii polecen z wykorzystaniem nastepujacych przelacznikow :" << endl;
       cout << "Dla szyfrowania :" << endl;
       cout << "    --en flaga szyfrowania" << endl;
       cout << "    - i plik tekstowy wejsciowy jawny" << endl;
       cout << "    - o plik tekstowy wyjsciowy zaszyfrowany" << endl;
       cout << "    - k plik tekstowy z kluczem" << endl;
       cout << "Dla deszyfrowania :" << endl;
       cout << "    --de flaga deszyfrowania" << endl;
       cout << "    - i plik tekstowy wejsciowy zaszyfrowany" << endl;
       cout << "    - o plik tekstowy wyjsciowy jawny" << endl;
       cout << "    - k plik tekstowy z kluczem" << endl;
       cout << "Dla lamania szyfru :" << endl;
       cout << "    --br flaga lamania szyfru" << endl;
       cout << "    - i plik tekstowy wejsciowy zaszyfrowany" << endl;
       cout << "    - o plik tekstowy wyjsciowy jawny" << endl;
       return -1;
    }
    if (argc > 8)
    {
        cout << "Podano za duzo argumentow!"<<endl;
        cout << "Program uruchamiany jest z linii polecen z wykorzystaniem nastepujacych przelacznikow :" << endl;
        cout << "Dla szyfrowania :" << endl;
        cout << "    --en flaga szyfrowania" << endl;
        cout << "    - i plik tekstowy wejsciowy jawny" << endl;
        cout << "    - o plik tekstowy wyjsciowy zaszyfrowany" << endl;
        cout << "    - k plik tekstowy z kluczem" << endl;
        cout << "Dla deszyfrowania :" << endl;
        cout << "    --de flaga deszyfrowania" << endl;
        cout << "    - i plik tekstowy wejsciowy zaszyfrowany" << endl;
        cout << "    - o plik tekstowy wyjsciowy jawny" << endl;
        cout << "    - k plik tekstowy z kluczem" << endl;
        cout << "Dla lamania szyfru :" << endl;
        cout << "    --br flaga lamania szyfru" << endl;
        cout << "    - i plik tekstowy wejsciowy zaszyfrowany" << endl;
        cout << "    - o plik tekstowy wyjsciowy jawny" << endl;
        return -1;
    }
    
    return 0;
}
zadanie_prog flaga_prog(const string& flaga)
{
    if (flaga == "--en")
    {
        return zadanie_prog::szyfrowanie;
    }
    else if (flaga == "--de")
    {
        return zadanie_prog::deszyfrowanie;
    }
    else if (flaga == "--br")
    {
        return zadanie_prog::lamanie_szyfru;
    }
    else if (flaga == "-h")
    {
        cout << "Program uruchamiany jest z linii polecen z wykorzystaniem nastepujacych przelacznikow :" << endl;
        cout << "Dla szyfrowania :" << endl;
        cout << "    --en flaga szyfrowania" << endl;
        cout << "    - i plik tekstowy wejsciowy jawny" << endl;
        cout << "    - o plik tekstowy wyjsciowy zaszyfrowany" << endl;
        cout << "    - k plik tekstowy z kluczem" << endl;
        cout << "Dla deszyfrowania :" << endl;
        cout << "    --de flaga deszyfrowania" << endl;
        cout << "    - i plik tekstowy wejsciowy zaszyfrowany" << endl;
        cout << "    - o plik tekstowy wyjsciowy jawny" << endl;
        cout << "    - k plik tekstowy z kluczem" << endl;
        cout << "Dla lamania szyfru :" << endl;
        cout << "    --br flaga lamania szyfru" << endl;
        cout << "    - i plik tekstowy wejsciowy zaszyfrowany" << endl;
        cout << "    - o plik tekstowy wyjsciowy jawny" << endl;
        return zadanie_prog::error;
    }

    else
    {
        cout << "Niepoprawnie podana flaga!" << endl;
        cout << "Program uruchamiany jest z linii polecen z wykorzystaniem nastepujacych przelacznikow :" << endl;
        cout << "Dla szyfrowania :"<<endl;
        cout << "    --en flaga szyfrowania" << endl;
        cout << "    - i plik tekstowy wejsciowy jawny" << endl;
        cout << "    - o plik tekstowy wyjsciowy zaszyfrowany" << endl;
        cout << "    - k plik tekstowy z kluczem" << endl;
        cout << "Dla deszyfrowania :" << endl;
        cout << "    --de flaga deszyfrowania" << endl;
        cout << "    - i plik tekstowy wejsciowy zaszyfrowany" << endl;
        cout << "    - o plik tekstowy wyjsciowy jawny" << endl;
        cout << "    - k plik tekstowy z kluczem" << endl;
        cout << "Dla lamania szyfru :" << endl;
        cout << "    --br flaga lamania szyfru" << endl;
        cout << "    - i plik tekstowy wejsciowy zaszyfrowany" << endl;
        cout << "    - o plik tekstowy wyjsciowy jawny" << endl;
        return zadanie_prog::error;
    }
}
void sciezka(const string& przelacznik, string& sciezka, string& sciezka_wejscie, string&sciezka_wyjscie, string&sciezka_klucz)
{
    if (przelacznik == "-i")
    {
        sciezka_wejscie = sciezka;
    }
    else if (przelacznik == "-o")
    {
        sciezka_wyjscie = sciezka;
    }
    else if (przelacznik == "-k")
    {
        sciezka_klucz = sciezka;
    }
    else
        cout << "Blednie podany przelacznik!" << endl;
}
void odczytaj(const string& sciezka_wejscie, string&zawartoscp)
{
    int indeks = 0;
    string tekst;
    string linia;
    ifstream pwejsciowy(sciezka_wejscie);
    if (pwejsciowy) {
            stringstream bufor;
            while (getline(pwejsciowy, linia)) {
                bufor << linia;
            }
            tekst = bufor.str();
    }
    //oczyszczenie zawartosci pliku ze zbednych symboli + zapisanie wiadomosci wielkimi literami
    for (int i = 0; unsigned (i) < tekst.size(); i++)
    {
        if (isalpha(tekst[i]))
        {
            if(isupper(tekst[i]))
            zawartoscp += tekst[i];
            else if (islower(tekst[unsigned(i)]))
            {
                indeks=(int)tekst[i]-32;
                zawartoscp += (char)indeks;
            }
        }
    }
    pwejsciowy.close();
}
void zapisz(const string& sciezka_wyjscie, string& szyfrwiad)
{
    ofstream pwyjsciowy(sciezka_wyjscie);
    
    if (pwyjsciowy) { 
        pwyjsciowy << szyfrwiad;
    }
    pwyjsciowy.close();
}
void szyfruj(const string& wiadomosc, const string& klucz, string& szyfrwiad)
{
    int przesunieciePion = 0;
    int przesunieciePoziom = 0;
    string alfabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int j = 0;

    for (int i = 0; unsigned(i) < wiadomosc.size(); i++)
    {
              int indexPowt = j % klucz.size();

              przesunieciePion = (int)klucz[indexPowt] - 65;            
              przesunieciePoziom = (int)wiadomosc[i] - 65;
              
              szyfrwiad += alfabet[(przesunieciePion + przesunieciePoziom) % alfabet.size()];
              j++;           
        
    }
}
void odszyfruj(const string& szyfrwiad, const string& klucz, string& wiadomosc )
{
    string alfabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int index_s = 0;
    int index_k = 0;
    int indexPowt = 0;
    for (int i = 0; i < szyfrwiad.size(); i++)
    {
            indexPowt = i % klucz.size();            
            index_s = (int)szyfrwiad[i]-65;
            index_k = (int)klucz[indexPowt] - 65;
            
            if ((index_s - index_k) < 0)
            {
                wiadomosc += alfabet[26 + (index_s - index_k)];
            }
            else if ((index_s - index_k) >= 0) {
                wiadomosc += alfabet[(index_s - index_k)];
            }
        
    }
}
void znajdz_klucz_dlugosc(const string& szyfrwiad, int& dlugosc_klucza)
{
    vector<int> zdarzenia;
    int licznik_zdarzen = 0;
    int rzad = 1;
    dlugosc_klucza = 1;
    //przesuwanie tekstu w prawo o 1 litere i sprawdzanie liczby pokrywajacych sie liter dla kazdego przesuniecia.
    for (int i = 0; i < szyfrwiad.size(); i++)
    {
        
        licznik_zdarzen = 0;
        int litera = 0;
        for (rzad; rzad < szyfrwiad.size(); rzad++)
        {
            if (szyfrwiad[litera] == szyfrwiad[rzad])
            {
                licznik_zdarzen++;
            }
            litera++;
        }
        zdarzenia.push_back(licznik_zdarzen);
        rzad=i+2;       
    }
    double srednia = 0;
    for (int i = 0; i < 49; i++)
    {
        srednia += zdarzenia[i];
    }
    srednia = srednia / 50;
    
    //automatyzacja wyszukiwania klucza
    for (int i = 2; i < 51; i++)
    {
        if (zdarzenia[i] > srednia * 1.15) {
            i++;
            while (zdarzenia[i]<srednia*1.15)
            {
                dlugosc_klucza++;
                i++;
                
            }
            break;
        }
    }
}
void znajdz_klucz(const string& szyfrwiad, const int& dlugosc_klucza, string& klucz)
{
    
    //czestotliwosci wystepowania liter w polskim alfabecie
    double czestotliwosc_pl[26] = { 0.0891, 0.0147, 0.0396, 0.0325, 0.0766, 0.003, 0.0142,
                                    0.0108, 0.0821, 0.0228, 0.0351, 0.021,  0.028, 0.0552,
                                    0.0775, 0.0313, 0.0014 ,0.0469, 0.0432, 0.0398, 0.025, 
                                    0.0004 ,0.0465, 0.0002, 0.0376, 0.0564 }; 


    double licznik[26] = {};
    double suma = 0;
    char alf[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    double iloczyn = 0;
    double suma_il = 0;
    double suma_max = 0;
    int x = 0;

    for (x = 0; x < dlugosc_klucza; x++) 
    {
        suma = 0;
        //zliczenie wystepowan liter na odpowiednich miejscach zaleznych od dlugosci klucza
        for (int i = x ; i < szyfrwiad.length(); i += dlugosc_klucza)
        {
            
            
            for (int j = 0; j < 26; j++)
            {
                if (szyfrwiad[i] == alf[j])
                {
                    licznik[j]++;
                }

            }

        }
   
        for (int i = 0; i < 26; i++)
        {      
            suma += licznik[i];
        }
        
        //obliczenie czestotliwosci wystepowania liter w zaszyfrowanej wiadomosci i przekazanie ich do zmiennych licznik
        for (int i = 0; i < 26; i++)
        {
            licznik[i] = licznik[i] / suma;
            
        }
 
        iloczyn = 0;
        suma_il = 0;
        suma_max = 0;
        double suma_il_tab[26] = {};

        int k = 0, n = 0;
        int index_najw_sumy = 0; //indeks szukanej litery klucza
        for (int j = 0; j < 26; j++) {

            suma_il = 0;
            k = n;
            for (int i = 0; i < 26; i++)
            {
                if (k > 25)
                {
                    k = k - 26;
                }
                
                iloczyn = licznik[k] * czestotliwosc_pl[i];
                suma_il += iloczyn;
                k++;
            }
            suma_il_tab[j] = suma_il;
            n++;
            
        }
        for (int i = 0; i < 26; i++)
        {
            if (suma_max < suma_il_tab[i])
            {
                suma_max = suma_il_tab[i];             
            }
            
        }
        
        
        for (int i = 0; i < 26; i++)
        {
            if (suma_il_tab[i] == suma_max) {
                index_najw_sumy = i;
            }
            
        }
        klucz += alf[index_najw_sumy];
    }
}