#include "../inc/zadanie.hh"
#include "../inc/rozm_instacji_testowej.hh"
#include <iostream>
#include <algorithm>

using namespace std;

ostream &operator<<(ostream &str, Zadanie &zad);
ostream &operator<<(ostream &str, Szeregowanie &szer)
{
    cout << "id\tr\tp\tq\n";

    for ( Zadanie &zad : szer.zadania_v) {
        str << zad ;
    }
    return str;
}

void Szeregowanie::Szeregowanie_r(){
    cout << "SORTOWANIE PO R" << endl;
    sort(zadania_v.begin(), zadania_v.end(), byR);
}
void Szeregowanie::Szeregowanie_q(){
    cout << "SORTOWANIE PO Q" << endl;
    sort(zadania_v.begin(), zadania_v.end(), byQ);
}

void Szeregowanie::UtworzInstancjeTestowa(int n){
    int rr, pp, qq;

    if(!this->zadania_v.empty()){
        cout << "Nadpisuje obecne dane!\n";
    }

    for (int i = 0; i < n; i++)
    {
        rr = rand() % ZAKRES_INSTANCJI_TESTOWEJ + 1;
        pp = rand() % ZAKRES_INSTANCJI_TESTOWEJ + 1;
        qq = rand() % ZAKRES_INSTANCJI_TESTOWEJ + 1;

        Zadanie *tmp = new Zadanie(rr, pp, qq, i);
        this->zadania_v.push_back(*tmp);
    }
}

unsigned int Szeregowanie::CzasJednejPermutacji(){
    unsigned int czas = 0;
    unsigned int c_max = 0;
    unsigned int c_j;

    for ( Zadanie & zad : this->zadania_v){
        while(czas < zad.r){ // dopoki nie mozesz wykonac zadania (bo termin)
            czas++;
        }
        c_j = czas + zad.p + zad.q;
        c_max = max(c_max, c_j);
        czas += zad.p;
    }

    return c_max;
}
// brute force - obliczenie c_max dla kazdego z zadan i wybranie tego ktore wykona sie najszybciej
void Szeregowanie::PrzegladZupelny(){
    unsigned int index_najlepszego;
    unsigned int c_max = INT32_MAX;
    unsigned int licznik = 0;

    do {
        if(this->CzasJednejPermutacji() < c_max){
            c_max = this->CzasJednejPermutacji();
            index_najlepszego = licznik;
        }
        licznik++;

    } while (next_permutation(zadania_v.begin(), zadania_v.end()));

    cout << "najlepszy c_max: " << c_max << endl;
}