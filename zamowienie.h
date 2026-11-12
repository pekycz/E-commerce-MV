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
  Zamowienie(int idZamowienia, const vector<PozycjaZamowienia>& pozycje);
  double obliczKoszt() const;
  const vector<PozycjaZamowienia>& pobierzPozycje() const;

private:
  static double obliczKosztPozycji(
      const vector<PozycjaZamowienia>& pozycje);
};

using zamowienie = Zamowienie;

#endif // ZAMOWIENIE_H
