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
    Produkt znajdzProdukt(int id) const {
      for (const Produkt& produkt : produkty_) {
        if (produkt.id == id) {
          return produkt;
        }
      }
      throw out_of_range("Nie znaleziono produktu.");
    }

    Klient& zarejestrujKlienta(string nazwa, string haslo) {
      for (const Klient& klient : klienci_) {
        if (klient.nazwa == nazwa) {
          throw invalid_argument("Uzytkownik o takiej nazwie juz istnieje.");
        }
      }

      klienci_.emplace_back(static_cast<int>(klienci_.size()) + 1, nazwa, haslo);
      return klienci_.back();
    }

    void dodajAdministratora(const Administrator& administrator) {
      administratorzy_.push_back(administrator);
    }

    Uzytkownik zaloguj(string nazwa, string haslo) const {
      for (const Klient& klient : klienci_) {
        if (klient.nazwa == nazwa && klient.haslo == haslo) {
          return klient;
        }
      }

      for (const Administrator& administrator : administratorzy_) {
        if (administrator.nazwa == nazwa && administrator.haslo == haslo) {
          return administrator;
        }
      }

      throw invalid_argument("Nieprawidlowa nazwa uzytkownika lub haslo.");
    }

    void dodajProdukt(const Produkt& produkt) {
      for (const Produkt& istniejacyProdukt : produkty_) {
        if (istniejacyProdukt.id == produkt.id) {
          throw invalid_argument("Produkt o takim id juz istnieje.");
        }
      }
      produkty_.push_back(produkt);
    }

    void edytujProdukt(const Produkt& produkt) {
      for (Produkt& istniejacyProdukt : produkty_) {
        if (istniejacyProdukt.id == produkt.id) {
          istniejacyProdukt = produkt;
          return;
        }
      }
      throw out_of_range("Nie znaleziono produktu do edycji.");
    }

    void dodajZamowienie(const Zamowienie& zamowienie) {
      zamowienia_.push_back(zamowienie);
    }

    const list<Produkt>& pobierzProdukty() const {
      return produkty_;
    }

    const list<Zamowienie>& pobierzZamowienia() const {
      return zamowienia_;
    }
};

inline void Administrator::dodajProdukt(const Produkt& produkt, SystemSklepu& sklep) {
  sklep.dodajProdukt(produkt);
}

inline void Administrator::edytujProdukt(const Produkt& produkt, SystemSklepu& sklep) {
  sklep.edytujProdukt(produkt);
}

#endif // SYSTEMSKLEPU_H
