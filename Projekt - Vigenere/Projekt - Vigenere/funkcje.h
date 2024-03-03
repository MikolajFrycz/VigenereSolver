#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

/// This type is used to numerate the programm's task
enum class zadanie_prog
{
    szyfrowanie,
    deszyfrowanie,
    lamanie_szyfru,
    error,
};

/// This function checks if user entered a correct number of arguemnts.
/// @param argc           number of arguments, provided by user
int ArgWejscia(const int argc);

/// This function checks the type of given flag and indicates, what the program should do, by returning the enum class variable value.
/// @param flaga          flag of the programm, provided by user
zadanie_prog flaga_prog(const string& flaga);

/// This function recognizes input/output files, based on the switch before a file name and stores the directory into a path string
/// @param przelacznik         switch, which indicates if given file is an input/output/key file
/// @param sciezka_wejscie     input file path
/// @param sciezka_wyjscie     output file path
/// @param sciezka_klucz       key file path
/// @param sciezka             recognized directory further stored and given to the main function 
void sciezka(const string& przelacznik, string& sciezka_wejscie, string& sciezka_wyjscie, string& sciezka_klucz, string& sciezka);

/// This function reads the message from an input file and stores it into a string (unencryptable symbols are omitted)
/// @param sciezka_wejscie    input file path
/// @param zawartoscp         input file content 
void odczytaj(const string& sciezka_wejscie, string& zawartoscp);

/// This function saves the text message into an output file
/// @param sciezka_wyjscie    ouput file path
/// @param szyfrwiad          message written to the output file
void zapisz(const string& sciezka_wyjscie, string& szyfrwiad);

/// This function encrypts a message, using a key
/// @param wiadomosc        message to encrypt
/// @param klucz            key, used to encrypt
/// @param szyfrwiad        encrypted message
void szyfruj(const string& wiadomosc, const string& klucz, string& szyfrwiad);

/// This function decrypts a message, using a key
/// @param szyfrwiad        encrypted message
/// @param klucz            key, used to decrypt
/// @param wiadomosc        decrypted message
void odszyfruj(const string& szyfrwiad, const string& klucz, string& wiadomosc);

/// This function searches for the length of the key, by which the message was encrypted
/// @param szyfrwiad        encrypted message
/// @param dlugosc_klucza   found length of the key
void znajdz_klucz_dlugosc(const string& szyfrwiad, int& dlugosc_klucza);

/// This function looks for the key, knowing the length of it
/// @param szyfrwiad        encrypted message
/// @param dlugosc_klucza   length of the key
/// @param klucz            found key
void znajdz_klucz(const string& szyfrwiad, const int& dlugosc_klucza, string& klucz);