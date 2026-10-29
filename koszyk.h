#ifndef KOSZYK_H
#define KOSZYK_H

#include "produkt.h"

#include <map>
#include <stdexcept>

using namespace std;

class Koszyk {
  public:
    struct Pozycja {
      Produkt produkt;
      int ilosc;
    };

  private:
    map<int, Pozycja> produkty_;

  public:
    void dodajProdukt(const Produkt& produkt, int ilosc) {
      if (ilosc <= 0) {
        throw invalid_argument("Ilosc musi byc wieksza od zera.");
      }

      auto pozycja = produkty_.find(produkt.id);
      if (pozycja == produkty_.end()) {
        produkty_.emplace(produkt.id, Pozycja{produkt, ilosc});
      } else {
        pozycja->second.ilosc += ilosc;
      }
    }

    void usunProdukt(const Produkt& produkt, int ilosc) {
      if (ilosc <= 0) {
        throw invalid_argument("Ilosc musi byc wieksza od zera.");
      }

      auto pozycja = produkty_.find(produkt.id);
      if (pozycja == produkty_.end()) {
        throw out_of_range("Produktu nie ma w koszyku.");
      }

      if (ilosc >= pozycja->second.ilosc) {
        produkty_.erase(pozycja);
      } else {
        pozycja->second.ilosc -= ilosc;
      }
    }

    const map<int, Pozycja>& pobierzProdukty() const {
      return produkty_;
    }

    void wyczysc() {
      produkty_.clear();
    }
};

#endif // KOSZYK_H
