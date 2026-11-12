#include "zamowienie.h"
#include <stdexcept>

Zamowienie::Zamowienie(
    int idZamowienia, const vector<PozycjaZamowienia> &pozycje)
    : id(idZamowienia),
      data(time(nullptr)),
      platnosc(idZamowienia, obliczKosztPozycji(pozycje)),
      pozycje_(pozycje),
      status_(StatusZamowienia::Nowe) {}

double Zamowienie::obliczKoszt() const
{
  return platnosc.kwota;
}

const vector<PozycjaZamowienia> &Zamowienie::pobierzPozycje() const
{
  return pozycje_;
}

StatusZamowienia Zamowienie::pobierzStatus() const
{
  return status_;
}

void Zamowienie::zmienStatus(StatusZamowienia nowyStatus)
{
  if (static_cast<int>(nowyStatus) != static_cast<int>(status_) + 1)
  {
    throw invalid_argument("Status zamowienia mozna zmieniac tylko na kolejny.");
  }
  status_ = nowyStatus;
}

double Zamowienie::obliczKosztPozycji(
    const vector<PozycjaZamowienia> &pozycje)
{
  double koszt = 0.0;
  for (const PozycjaZamowienia &pozycja : pozycje)
  {
    koszt += pozycja.obliczKoszt();
  }
  return koszt;
}