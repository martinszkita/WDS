#include "../inc/zadanie.hh"
#include <iostream>
#include <algorithm>

using namespace std;

ostream &operator<<(ostream &str, Zadanie &zad);
ostream &operator<<(ostream &str, Szeregowanie &szer)
{
    for ( Zadanie &zad : szer.zadania_v) {
        str << zad << endl; // Wywołanie przeciążenia operatora << dla klasy Zadanie
    }
    return str;
}

void Szeregowanie::Szeregowanie_r(){

    cout << "SORTOWANIE PO R" << endl;
    sort(zadania_v.begin(), zadania_v.end(), byR);

    cout << "id\tr\tp\tq\n";
    for (Zadanie & zad : zadania_v){ // wypisywanie uszeregowanego vectora
        cout << zad;
    }
}
void Szeregowanie::Szeregowanie_q(){
    cout << "SORTOWANIE PO Q" << endl;
    sort(zadania_v.begin(), zadania_v.end(), byQ);

    cout << "id\tr\tp\tq\n";
    for (Zadanie & zad : zadania_v){ // wypisywanie uszeregowanego vectora
        cout << zad;
    }
    
}
