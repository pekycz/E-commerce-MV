#ifndef PLATNOSC_H
#define PLATNOSC_H

#include <stdexcept>

using namespace std;

enum class StatusPlatnosci {
  Oczekujaca,
  Oplacona,
  Odrzucona
};

class Platnosc {
  public:
  int id;
  double kwota;
  StatusPlatnosci status;

  Platnosc(int idPlatnosci = 0, double kwotaPlatnosci = 0.0);
  void oplac();
};

#endif // PLATNOSC_H
