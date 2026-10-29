#ifndef ZAMOWIENIE_H
#define ZAMOWIENIE_H

#include "platnosc.h"
#include "pozycjazamowienia.h"

#include <ctime>
#include <vector>

using namespace std;

class Zamowienie {
  public:
    int id;
    time_t data;
    Platnosc platnosc;

  private:
    vector<PozycjaZamowienia> pozycje_;

  public:
    Zamowienie(int idZamowienia, const vector<PozycjaZamowienia>& pozycje)
        : id(idZamowienia),
          data(time(nullptr)),
          platnosc(idZamowienia, obliczKosztPozycji(pozycje)),
          pozycje_(pozycje) {}

    double obliczKoszt() const {
      return platnosc.kwota;
    }

    const vector<PozycjaZamowienia>& pobierzPozycje() const {
      return pozycje_;
    }

  private:
    static double obliczKosztPozycji(
        const vector<PozycjaZamowienia>& pozycje) {
      double koszt = 0.0;
      for (const PozycjaZamowienia& pozycja : pozycje) {
        koszt += pozycja.obliczKoszt();
      }
      return koszt;
    }
};

using zamowienie = Zamowienie;

#endif // ZAMOWIENIE_H
