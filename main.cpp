#include "systemsklepu.h"

#include <iomanip>
#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
  SystemSklepu sklep;
  Administrator administrator(1, "admin", "haslo");
  sklep.dodajAdministratora(administrator);

  administrator.dodajProdukt(Produkt(1, "Klawiatura", 149.99), sklep);
  administrator.dodajProdukt(Produkt(2, "Mysz", 79.99), sklep);
  administrator.dodajProdukt(Produkt(3, "Sluchawki", 199.99), sklep);

  Klient& klient = sklep.zarejestrujKlienta("Ala", "haslo");

  cout << "Witaj w sklepie, " << klient.nazwa << "!\n";

  while (true) {
    cout << "\nMENU SKLEPU\n"
         << "1. Dodaj produkt do koszyka\n"
         << "2. Zloz zamowienie\n"
         << "0. Zakoncz bez skladania zamowienia\n";

    int wybor;
    cout << "Wybierz opcje: ";
    cin >> wybor;

    if (wybor == 0) {
      cout << "Dziekujemy za wizyte!\n";
      break;
    }

    if (wybor == 1) {
      cout << "\nDostepne produkty:\n";
      for (const Produkt& produkt : sklep.pobierzProdukty()) {
        cout << produkt.id << ". " << produkt.nazwa << " - "
             << produkt.cena << " zl\n";
      }

      int idProduktu;
      cout << "Podaj numer produktu: ";
      cin >> idProduktu;

      Produkt wybranyProdukt;
      bool znalezionoProdukt = false;
      for (const Produkt& produkt : sklep.pobierzProdukty()) {
        if (produkt.id == idProduktu) {
          wybranyProdukt = produkt;
          znalezionoProdukt = true;
          break;
        }
      }

      if (!znalezionoProdukt) {
        cout << "Nie ma produktu o takim numerze.\n";
        continue;
      }

      int ilosc;
      cout << "Podaj ilosc: ";
      cin >> ilosc;

      klient.dodajDoKoszyka(wybranyProdukt, ilosc);
      cout << "Dodano do koszyka: " << wybranyProdukt.nazwa
           << ", ilosc: " << ilosc << ".\n";

      float sumaKoszyka = 0.00;
      cout << "\nZawartosc koszyka:\n";
      for (const auto& wpis : klient.pobierzProduktyWKoszyku()) {
        const Produkt& produkt = wpis.second.produkt;
        int iloscProduktu = wpis.second.ilosc;
        float kosztPozycji = produkt.cena * iloscProduktu;
        sumaKoszyka += kosztPozycji;

        cout << produkt.nazwa << " x " << iloscProduktu << " - "
              << kosztPozycji << " zl\n";
      }
      cout << "Razem: "  << sumaKoszyka << " zl\n";
      continue;
    }

    if (wybor == 2) {
      try {
        Zamowienie zamowienie = klient.zlozZamowienie();
        sklep.dodajZamowienie(zamowienie);

        cout << fixed << setprecision(2)
             << "Zamowienie nr " << zamowienie.id
             << " zlozone. Koszt: " << zamowienie.obliczKoszt() << " zl\n";
        break;
      } catch (const runtime_error& blad) {
        cout << blad.what() << "\n";
        continue;
      }
    }

    cout << "Nieprawidlowa opcja. Wybierz 0, 1 lub 2.\n";
  }

  return 0;
}
