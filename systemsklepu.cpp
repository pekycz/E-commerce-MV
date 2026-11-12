#include "systemsklepu.h"

Produkt SystemSklepu::znajdzProdukt(int id) const {
  for (const Produkt& produkt : produkty_) {
    if (produkt.id == id) {
      return produkt;
    }
  }
  throw out_of_range("Nie znaleziono produktu.");
}

Klient& SystemSklepu::zarejestrujKlienta(string nazwa, string haslo) {
  for (const Klient& klient : klienci_) {
    if (klient.nazwa == nazwa) {
      throw invalid_argument("Uzytkownik o takiej nazwie juz istnieje.");
    }
  }
  klienci_.emplace_back((klienci_.size()) + 1, nazwa, haslo);
  return klienci_.back();
}

void SystemSklepu::dodajAdministratora(const Administrator& administrator) {
  administratorzy_.push_back(administrator);
}

Uzytkownik SystemSklepu::zaloguj(string nazwa, string haslo) const {
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

void SystemSklepu::dodajProdukt(const Produkt& produkt) {
  for (const Produkt& istniejacyProdukt : produkty_) {
    if (istniejacyProdukt.id == produkt.id) {
      throw invalid_argument("Produkt o takim id juz istnieje.");
    }
  }
  produkty_.push_back(produkt);
}

void SystemSklepu::edytujProdukt(const Produkt& produkt) {
  for (Produkt& istniejacyProdukt : produkty_) {
    if (istniejacyProdukt.id == produkt.id) {
      istniejacyProdukt = produkt;
      return;
    }
  }
  throw out_of_range("Nie znaleziono produktu do edycji.");
}

void SystemSklepu::dodajZamowienie(const Zamowienie& zamowienie) {
  zamowienia_.push_back(zamowienie);
}

const list<Produkt>& SystemSklepu::pobierzProdukty() const {
  return produkty_;
}

const list<Zamowienie>& SystemSklepu::pobierzZamowienia() const {
  return zamowienia_;
}
