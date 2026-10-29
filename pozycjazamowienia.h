#ifndef POZYCJAZAMOWIENIA_H
#define POZYCJAZAMOWIENIA_H

#include "produkt.h"

using namespace std;

class PozycjaZamowienia {
  public:
    int id;
    Produkt produkt;
    int ilosc;
    double cena;

    PozycjaZamowienia(int idPozycji, const Produkt& produktZamowienia, int liczbaSztuk)
        : id(idPozycji),
          produkt(produktZamowienia),
          ilosc(liczbaSztuk),
          cena(produktZamowienia.cena) {}

    double obliczKoszt() const {
      return ilosc * cena;
    }
};

#endif // POZYCJAZAMOWIENIA_H
