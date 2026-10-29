#ifndef PRODUKT_H
#define PRODUKT_H

#include <string>

using namespace std;

class Produkt {
  public:
    int id;
    string nazwa;
    double cena;

    Produkt() : id(0), cena(0.0) {}

    Produkt(int idProduktu, string nazwaProduktu, double cenaProduktu)
        : id(idProduktu), nazwa(nazwaProduktu), cena(cenaProduktu) {}
};

#endif // PRODUKT_H
