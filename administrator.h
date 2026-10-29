#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "uzytkownik.h"

#include <string>

class Produkt;

class Administrator : public Uzytkownik {
  public:
    Administrator(int id, const std::string& nazwa, const std::string& haslo) {
      Uzytkownik::id = id;
      Uzytkownik::nazwa = nazwa;
      Uzytkownik::haslo = haslo;
    }

    void dodajProdukt(const Produkt& produkt);
    void edytujProdukt(const Produkt& produkt);
};

#endif // ADMINISTRATOR_H
