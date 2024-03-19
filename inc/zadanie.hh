#pragma once
#include <fstream>
#include "szeregowanie.hh"


using namespace std;
class Zadanie
{
    public:
        int r; // termin dostepnoci
        int p; // czas oblsugi
        int q; // czas dostarczenia zadania
        int id; // do identyfikacji zadan

        Zadanie(){};
        Zadanie(int _r, int _p, int _q);
};

istream &operator>>(istream &str, Zadanie &zad);
ostream &operator<<(ostream &str, Zadanie &zad);
bool byR(const Zadanie &zad1, const Zadanie &zad2);
bool byQ(const Zadanie &zad1, const Zadanie &zad2);