#ifndef ZAMOWIENIE_H
#define ZAMOWIENIE_H

#include "platnosc.h"
#include "pozycjazamowienia.h"

#include <vector>

using namespace std;

enum class StatusZamowienia {
  Nowe,
  WRealizacji,
  Wyslane,
  Dostarczone
};

class Zamowienie {
  public:
    int id;
    Platnosc platnosc;

private:
  vector<PozycjaZamowienia> pozycje_;
  StatusZamowienia status_;

public:
  Zamowienie(int idZamowienia, const vector<PozycjaZamowienia>& pozycje);
  double obliczKoszt() const;
  StatusZamowienia pobierzStatus() const;
  void zmienStatus(StatusZamowienia nowyStatus);

private:
  static double obliczKosztPozycji(
      const vector<PozycjaZamowienia>& pozycje);
};

using zamowienie = Zamowienie;

#endif // ZAMOWIENIE_H