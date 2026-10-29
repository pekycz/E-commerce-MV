#ifndef PRODUKT_H
#define PRODUKT_H

#include <string>

class Produkt {
  public:
    int id;
    std::string nazwa;
    double cena;

    Produkt() : id(0), cena(0.0) {}

    Produkt(int idProduktu, const std::string& nazwaProduktu, double cenaProduktu)
        : id(idProduktu), nazwa(nazwaProduktu), cena(cenaProduktu) {}
};

#endif // PRODUKT_H
