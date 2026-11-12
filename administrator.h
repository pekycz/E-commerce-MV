#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "produkt.h"
#include "zamowienie.h"
#include "uzytkownik.h"

#include <string>

using namespace std;

class SystemSklepu;

class Administrator : public Uzytkownik
{
public:
  Administrator() = default;

  Administrator(int id, string nazwa, string haslo);
  string rola() const override;
  void dodajProdukt(const Produkt &produkt, SystemSklepu &sklep);
  void edytujProdukt(const Produkt &produkt, SystemSklepu &sklep);
  void zmienStatusZamowienia(
      int idZamowienia, StatusZamowienia status, SystemSklepu &sklep);
};

#endif // ADMINISTRATOR_H
