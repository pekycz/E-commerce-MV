#include "systemsklepu.h"

#include <algorithm>
#include <cctype>

namespace
{
  string malymiLiterami(const string &tekst)
  {
    string wynik = tekst;
    transform(wynik.begin(), wynik.end(), wynik.begin(),
              [](unsigned char znak)
              { return static_cast<char>(tolower(znak)); });
    return wynik;
  }
}

Produkt SystemSklepu::znajdzProdukt(int id) const
{
  for (const Produkt &produkt : produkty_)
  {
    if (produkt.pobierzId() == id)
    {
      return produkt;
    }
  }
  throw out_of_range("Nie znaleziono produktu.");
}

Klient &SystemSklepu::zarejestrujKlienta(string nazwa, string haslo)
{
  for (const Klient &klient : klienci_)
  {
    if (klient.pobierzNazwe() == nazwa)
    {
      throw invalid_argument("Uzytkownik o takiej nazwie juz istnieje.");
    }
  }
  klienci_.emplace_back((klienci_.size()) + 1, nazwa, haslo);
  return klienci_.back();
}

void SystemSklepu::dodajAdministratora(const Administrator &administrator)
{
  administratorzy_.push_back(administrator);
}

const Uzytkownik &SystemSklepu::zaloguj(
    const string &nazwa, const string &haslo) const
{
  for (const Klient &klient : klienci_)
  {
    if (klient.pobierzNazwe() == nazwa && klient.hasloPasuje(haslo))
    {
      return klient;
    }
  }

  for (const Administrator &administrator : administratorzy_)
  {
    if (administrator.pobierzNazwe() == nazwa &&
        administrator.hasloPasuje(haslo))
    {
      return administrator;
    }
  }

  throw invalid_argument("Nieprawidlowa nazwa uzytkownika lub haslo.");
}

void SystemSklepu::dodajProdukt(const Produkt &produkt)
{
  for (const Produkt &istniejacyProdukt : produkty_)
  {
    if (istniejacyProdukt.pobierzId() == produkt.pobierzId())
    {
      throw invalid_argument("Produkt o takim id juz istnieje.");
    }
  }
  produkty_.push_back(produkt);
}

void SystemSklepu::edytujProdukt(const Produkt &produkt)
{
  for (Produkt &istniejacyProdukt : produkty_)
  {
    if (istniejacyProdukt.pobierzId() == produkt.pobierzId())
    {
      istniejacyProdukt = produkt;
      return;
    }
  }
  throw out_of_range("Nie znaleziono produktu do edycji.");
}

void SystemSklepu::dodajZamowienie(const Zamowienie &zamowienie)
{
  zamowienia_.push_back(zamowienie);
}

void SystemSklepu::oplacZamowienie(int idZamowienia)
{
  for (Zamowienie &zamowienie : zamowienia_)
  {
    if (zamowienie.id == idZamowienia)
    {
      zamowienie.platnosc.oplac();
      return;
    }
  }
  throw out_of_range("Nie znaleziono zamowienia.");
}

vector<Produkt> SystemSklepu::wyszukajProdukty(
    const string &nazwa, const string &kategoria) const
{
  vector<Produkt> wyniki;
  const string szukanaNazwa = malymiLiterami(nazwa);
  const string szukanaKategoria = malymiLiterami(kategoria);

  for (const Produkt &produkt : produkty_)
  {
    const bool pasujeNazwa =
        szukanaNazwa.empty() ||
        malymiLiterami(produkt.pobierzNazwe()).find(szukanaNazwa) !=
            string::npos;
    const bool pasujeKategoria =
        szukanaKategoria.empty() ||
        malymiLiterami(produkt.pobierzKategorie()).find(szukanaKategoria) !=
            string::npos;
    if (pasujeNazwa && pasujeKategoria)
    {
      wyniki.push_back(produkt);
    }
  }
  return wyniki;
}

void SystemSklepu::zmienStatusZamowienia(
    int idZamowienia, StatusZamowienia status)
{
  for (Zamowienie &zamowienie : zamowienia_)
  {
    if (zamowienie.id == idZamowienia)
    {
      zamowienie.zmienStatus(status);
      return;
    }
  }
  throw out_of_range("Nie znaleziono zamowienia.");
}

const list<Produkt> &SystemSklepu::pobierzProdukty() const
{
  return produkty_;
}

const list<Zamowienie> &SystemSklepu::pobierzZamowienia() const
{
  return zamowienia_;
}