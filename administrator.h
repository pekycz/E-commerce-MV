#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "produkt.h"
#include "uzytkownik.h"

#include <string>

using namespace std;

class SystemSklepu;

class Administrator : public Uzytkownik {
  public:
    Administrator() = default;

    Administrator(int id, string nazwa, string haslo);

    void dodajProdukt(const Produkt& produkt, SystemSklepu& sklep);
    void edytujProdukt(const Produkt& produkt, SystemSklepu& sklep);
};

#endif // ADMINISTRATOR_H
