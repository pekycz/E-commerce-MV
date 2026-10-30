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
    void dodajProdukt(const Produkt& produkt, int ilosc);
    void usunProdukt(const Produkt& produkt, int ilosc);
    void wyczysc();
    map<int, Pozycja>& pobierzProdukty();
  };
#endif // KOSZYK_H
