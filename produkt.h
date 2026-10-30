#ifndef PRODUKT_H
#define PRODUKT_H

#include <string>

using namespace std;

class Produkt {
  public:
    int id;
    string nazwa;
    double cena;

    Produkt();

    Produkt(int idProduktu, string nazwaProduktu, double cenaProduktu);
};

#endif // PRODUKT_H
