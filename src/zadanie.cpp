#include "../inc/zadanie.hh"

Zadanie::Zadanie(int _r, int _p, int _q){
    r = _r;
    p = _p;
    q = _q;
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
