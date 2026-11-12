#include "platnosc.h"

Platnosc::Platnosc(int idPlatnosci, double kwotaPlatnosci)
    : id(idPlatnosci),
      kwota(kwotaPlatnosci),
      status(StatusPlatnosci::Oczekujaca) {}
