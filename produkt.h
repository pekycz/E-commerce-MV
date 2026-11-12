#ifndef PRODUKT_H
#define PRODUKT_H

#include <string>

using namespace std;

class Produkt {
  private:
    int id;
    string nazwa;
    double cena;
    string kategoria;

  public:
    Produkt();

    Produkt(int idProduktu, string nazwaProduktu, double cenaProduktu);
    Produkt(int idProduktu, string nazwaProduktu, double cenaProduktu,
            string kategoriaProduktu);

    int pobierzId() const;
    const string& pobierzNazwe() const;
    double pobierzCene() const;
    const string& pobierzKategorie() const;
};

#endif // PRODUKT_H
