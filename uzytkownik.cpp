#include "uzytkownik.h"

const string& Uzytkownik::pobierzNazwe() const {
  return nazwa;
}

bool Uzytkownik::hasloPasuje(const string& podaneHaslo) const {
  return haslo == podaneHaslo;
}
