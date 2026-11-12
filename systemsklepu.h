#ifndef SYSTEMSKLEPU_H
#define SYSTEMSKLEPU_H

#include "administrator.h"
#include "klient.h"
#include "produkt.h"
#include "zamowienie.h"

#include <list>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

class SystemSklepu
{
private:
  list<Klient> klienci_;
  list<Administrator> administratorzy_;
  list<Produkt> produkty_;
  list<Zamowienie> zamowienia_;

public:
  Produkt znajdzProdukt(int id) const;
  Klient &zarejestrujKlienta(string nazwa, string haslo);
  void dodajAdministratora(const Administrator &administrator);
  const Uzytkownik &zaloguj(const string &nazwa, const string &haslo) const;
  void dodajProdukt(const Produkt &produkt);
  void edytujProdukt(const Produkt &produkt);
  void dodajZamowienie(const Zamowienie &zamowienie);
  void oplacZamowienie(int idZamowienia);
  vector<Produkt> wyszukajProdukty(
      const string &nazwa, const string &kategoria) const;
  void zmienStatusZamowienia(int idZamowienia, StatusZamowienia status);
  const list<Produkt> &pobierzProdukty() const;
  const list<Zamowienie> &pobierzZamowienia() const;
};

#endif // SYSTEMSKLEPU_H