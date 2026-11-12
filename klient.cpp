#include "koszyk.h"
#include "klient.h"

using namespace std;

Klient::Klient(int id, string nazwa, string haslo) {
      Uzytkownik::id = id;
      Uzytkownik::nazwa = nazwa;
      Uzytkownik::haslo = haslo;
    }


void Klient::dodajDoKoszyka(const Produkt& produkt, int ilosc) {
    koszyk.dodajProdukt(produkt, ilosc);
    }

const map<int, Koszyk::Pozycja>& Klient::pobierzProduktyWKoszyku() const {
      return koszyk.pobierzProdukty();
    }

Zamowienie Klient::zlozZamowienie() {
      if (koszyk.pobierzProdukty().empty()) {
        throw runtime_error("Koszyk jest pusty.");
      }

      static int nastepneIdZamowienia = 1;
      vector<PozycjaZamowienia> pozycje;
      int idPozycji = 1;

      for (const auto& wpis : koszyk.pobierzProdukty()) {
        pozycje.emplace_back(idPozycji++, wpis.second.produkt, wpis.second.ilosc);
      }

      Zamowienie zamowienie(nastepneIdZamowienia++, pozycje);
      koszyk.wyczysc();
      return zamowienie;
    }