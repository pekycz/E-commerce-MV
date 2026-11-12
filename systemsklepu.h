#ifndef SYSTEMSKLEPU_H
#define SYSTEMSKLEPU_H

#include "administrator.h"
#include "klient.h"
#include "produkt.h"
#include "zamowienie.h"

#include <list>
#include <stdexcept>
#include <string>

using namespace std;

class SystemSklepu {
  private:
    list<Klient> klienci_;
    list<Administrator> administratorzy_;
    list<Produkt> produkty_;
    list<Zamowienie> zamowienia_;

public:
  Produkt znajdzProdukt(int id) const;
  Klient& zarejestrujKlienta(string nazwa, string haslo);
  void dodajAdministratora(const Administrator& administrator);
  Uzytkownik zaloguj(string nazwa, string haslo) const;
  void dodajProdukt(const Produkt& produkt);
  void edytujProdukt(const Produkt& produkt);
  void dodajZamowienie(const Zamowienie& zamowienie);
  const list<Produkt>& pobierzProdukty() const;
  const list<Zamowienie>& pobierzZamowienia() const;
};

#endif // SYSTEMSKLEPU_H
