#ifndef KLIENT_H
#define KLIENT_H

#include "koszyk.h"
#include "uzytkownik.h"
#include "zamowienie.h"

#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

class Klient : public Uzytkownik {
  private:
    Koszyk koszyk;

  public:
    Klient() = default;

    Klient(int id, string nazwa, string haslo) {
      Uzytkownik::id = id;
      Uzytkownik::nazwa = nazwa;
      Uzytkownik::haslo = haslo;
    }

    void dodajDoKoszyka(const Produkt& produkt, int ilosc) {
      koszyk.dodajProdukt(produkt, ilosc);
    }

    Zamowienie zlozZamowienie() {
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
};

using klient = Klient;

#endif // KLIENT_H
