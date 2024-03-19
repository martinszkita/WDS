#pragma once
#include <vector>
#include <iostream>
#include "zadanie.hh"

using namespace std;

class Zadanie;
class Szeregowanie
{
public:
    vector<Zadanie> zadania_v;

    Szeregowanie(){};
    void Szeregowanie_r();
    void Szeregowanie_q();
};