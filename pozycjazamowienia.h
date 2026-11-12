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

  PozycjaZamowienia(int idPozycji, const Produkt& produktZamowienia,
                    int liczbaSztuk);
  double obliczKoszt() const;
};

#endif // POZYCJAZAMOWIENIA_H
