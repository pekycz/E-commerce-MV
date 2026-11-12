#include "pozycjazamowienia.h"

PozycjaZamowienia::PozycjaZamowienia(
    int idPozycji, const Produkt& produktZamowienia, int liczbaSztuk)
    : id(idPozycji),
      produkt(produktZamowienia),
      ilosc(liczbaSztuk),
      cena(produktZamowienia.cena) {}

double PozycjaZamowienia::obliczKoszt() const {
  return ilosc * cena;
}
