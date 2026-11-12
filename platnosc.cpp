#include "platnosc.h"

Platnosc::Platnosc(int idPlatnosci, double kwotaPlatnosci)
    : id(idPlatnosci),
      kwota(kwotaPlatnosci),
      status(StatusPlatnosci::Oczekujaca) {}

void Platnosc::oplac() {
  if (status != StatusPlatnosci::Oczekujaca) {
    throw invalid_argument("Platnosc nie oczekuje na oplacenie.");
  }
  status = StatusPlatnosci::Oplacona;
}
