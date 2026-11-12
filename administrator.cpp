#include "administrator.h"

#include "systemsklepu.h"

Administrator::Administrator(int id, string nazwa, string haslo) {
  Uzytkownik::id = id;
  Uzytkownik::nazwa = nazwa;
  Uzytkownik::haslo = haslo;
}


void Administrator::dodajProdukt(const Produkt& produkt, SystemSklepu& sklep) {
  sklep.dodajProdukt(produkt);
}

void Administrator::edytujProdukt(const Produkt& produkt, SystemSklepu& sklep) {
  sklep.edytujProdukt(produkt);
}

void Administrator::zmienStatusZamowienia(
    int idZamowienia, StatusZamowienia status, SystemSklepu& sklep) {
  sklep.zmienStatusZamowienia(idZamowienia, status);
}

string Administrator::rola() const {
  return "Administrator";
}