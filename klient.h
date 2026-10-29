#ifndef KLIENT_H
#define KLIENT_H

#include "koszyk.h"
#include "uzytkownik.h"
#include "zamowienie.h"

#include <string>

class Klient : public Uzytkownik {
  public:
    Koszyk koszyk;

    Klient(int id, const std::string& nazwa, const std::string& haslo) {
      Uzytkownik::id = id;
      Uzytkownik::nazwa = nazwa;
      Uzytkownik::haslo = haslo;
    }

    zamowienie zlozZamowienie() const {
      return zamowienie();
    }
};


#endif // KLIENT_H
