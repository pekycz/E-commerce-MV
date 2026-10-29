#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "systemsklepu.h"
#include "uzytkownik.h"

#include <string>

class Administrator : public Uzytkownik {
  private:
    SystemSklepu& systemSklepu_;

  public:
    Administrator(int id, const std::string& nazwa, const std::string& haslo,
                  SystemSklepu& systemSklepu)
        : systemSklepu_(systemSklepu) {
      Uzytkownik::id = id;
      Uzytkownik::nazwa = nazwa;
      Uzytkownik::haslo = haslo;
    }

    void dodajProdukt(const Produkt& produkt) {
      systemSklepu_.dodajProdukt(produkt);
    }

    void edytujProdukt(const Produkt& produkt) {
      systemSklepu_.edytujProdukt(produkt);
    }
};

#endif // ADMINISTRATOR_H
