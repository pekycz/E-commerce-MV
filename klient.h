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

    Klient(int id, string nazwa, string haslo);

    string rola() const override;
    void dodajDoKoszyka(const Produkt& produkt, int ilosc);
    void usunZKoszyka(const Produkt& produkt, int ilosc);

    const map<int, Koszyk::Pozycja>& pobierzProduktyWKoszyku() const;
    double obliczKosztKoszyka() const;

    Zamowienie zlozZamowienie();
};

using klient = Klient;

#endif // KLIENT_H
