#include "../inc/zadanie.hh"
#include "../inc/szeregowanie.hh"
#include "../inc/rozm_instacji_testowej.hh"

using namespace std;

int main(int argc, char * argv[]){

    int rozmiar; // liczba danych z pliku
    string str_tmp;
    Szeregowanie szeregowanie;
    ifstream dane_plik("dane1.txt");
    srand(time(NULL)); 

    if(!dane_plik.is_open()){
        cerr << "file error" << endl;
        return -1;
    }

    dane_plik >> rozmiar;
    
    // WCZYTYWANIE DAMYCH DO VECTORA
    for (int i = 0; i < rozmiar; i++){ 
        Zadanie *zad_tmp = new Zadanie;
        dane_plik >> *zad_tmp;
        zad_tmp->id = i;
        szeregowanie.zadania_v.push_back(*zad_tmp);
    }

    szeregowanie.PrzegladZupelny();

    // Szeregowanie s2;
    // s2.UtworzInstancjeTestowa(ROZMIAR_INSTANCJI_TESTOWEJ);
   



    return 0;
}