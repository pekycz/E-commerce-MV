#include "produkt.h"

Produkt::Produkt() : id(0), cena(0.0) {}

Produkt::Produkt(int idProduktu, string nazwaProduktu, double cenaProduktu)
    : Produkt(idProduktu, nazwaProduktu, cenaProduktu, "Inne") {}

Produkt::Produkt(int idProduktu, string nazwaProduktu, double cenaProduktu,
                 string kategoriaProduktu)
    : id(idProduktu),
      nazwa(nazwaProduktu),
      cena(cenaProduktu),
      kategoria(kategoriaProduktu) {}

int Produkt::pobierzId() const {
  return id;
}

const string& Produkt::pobierzNazwe() const {
  return nazwa;
}

double Produkt::pobierzCene() const {
  return cena;
}

const string& Produkt::pobierzKategorie() const {
  return kategoria;
}
