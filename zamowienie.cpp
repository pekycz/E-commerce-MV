#include "zamowienie.h"

Zamowienie::Zamowienie(
    int idZamowienia, const vector<PozycjaZamowienia>& pozycje)
    : id(idZamowienia),
      data(time(nullptr)),
      platnosc(idZamowienia, obliczKosztPozycji(pozycje)),
      pozycje_(pozycje) {}

double Zamowienie::obliczKoszt() const {
  return platnosc.kwota;
}

const vector<PozycjaZamowienia>& Zamowienie::pobierzPozycje() const {
  return pozycje_;
}

double Zamowienie::obliczKosztPozycji(
    const vector<PozycjaZamowienia>& pozycje) {
  double koszt = 0.0;
  for (const PozycjaZamowienia& pozycja : pozycje) {
    koszt += pozycja.obliczKoszt();
  }
  return koszt;
}
