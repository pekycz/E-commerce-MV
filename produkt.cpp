#include "produkt.h"

Produkt::Produkt() : id(0), cena(0.0) {}

Produkt::Produkt(int idProduktu, string nazwaProduktu, double cenaProduktu)
    : id(idProduktu), nazwa(nazwaProduktu), cena(cenaProduktu) {}
