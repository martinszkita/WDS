#include "../inc/zadanie.hh"

Zadanie::Zadanie(int _r, int _p, int _q, int _id){
    r = _r;
    p = _p;
    q = _q;
    id = _id;
}

istream & operator >> (istream & str, Zadanie & zad){
    str >> zad.r>> zad.p >> zad.q ;
    return str;
}

ostream & operator << (ostream & str, Zadanie & zad){
    str <<"["<<zad.id<<"] \t"<< zad.r<<"\t" << zad.p<<"\t" << zad.q<<endl ;
    return str;
}

bool byR(const Zadanie & zad1, const Zadanie & zad2){
    return zad1.r < zad2.r;
}

bool byQ(const Zadanie & zad1, const Zadanie & zad2){
    return zad1.q < zad2.q;
}

bool operator<(const Zadanie &z1, const Zadanie &z2) // do porzadku leksykograficznego
{
    return z1.id < z2.id;
}

// int czasZakonczeniaZadania(){

// }
