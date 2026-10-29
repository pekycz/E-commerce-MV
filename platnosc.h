#ifndef PLATNOSC_H
#define PLATNOSC_H

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

    Platnosc(int idPlatnosci = 0, double kwotaPlatnosci = 0.0)
        : id(idPlatnosci),
          kwota(kwotaPlatnosci),
          status(StatusPlatnosci::Oczekujaca) {}
};

#endif // PLATNOSC_H
