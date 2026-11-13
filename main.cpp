#include "systemsklepu.h"

#include <iomanip>
#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
  SystemSklepu sklep;
  Administrator administrator(1, "admin", "haslo");
  sklep.dodajAdministratora(administrator);

  administrator.dodajProdukt(Produkt(1, "Klawiatura", 149.99), sklep);
  administrator.dodajProdukt(Produkt(2, "Mysz", 79.99), sklep);
  administrator.dodajProdukt(Produkt(3, "Sluchawki", 199.99), sklep);

  Klient &klient = sklep.zarejestrujKlienta("Ala", "haslo");

  vector<PozycjaZamowienia> pozycjeTestowe;
  pozycjeTestowe.emplace_back(1, sklep.znajdzProdukt(1), 1);
  pozycjeTestowe.emplace_back(2, sklep.znajdzProdukt(2), 2);
  Zamowienie zamowienieTestowe(100, pozycjeTestowe);
  sklep.dodajZamowienie(zamowienieTestowe);
  sklep.oplacZamowienie(100);

  int rola;
  cout << "Wybierz role:\n1. Klient\n2. Administrator\n";
  cin >> rola;
  bool czyAdministrator = rola == 2;
  cout << "Zalogowano jako "
       << (czyAdministrator ? "Administrator" : "Klient") << ".\n";

  while (true)
  {
    cout << "\nMENU SKLEPU\n"
         << "1. Wyszukaj produkt\n";
    if (czyAdministrator)
    {
      cout << "2. Dodaj produkt do systemu\n"
           << "3. Pokaz zamowienia\n"
           << "4. Zmien status zamowienia\n"
           << "5. Zmien cene produktu\n";
    }
    else
    {
      cout << "2. Dodaj produkt do koszyka\n"
           << "3. Zloz zamowienie\n"
           << "4. Wyswietl zawartosc koszyka\n"
           << "5. Pokaz zamowienia\n"
           << "6. Sprawdz platnosci\n"
           << "7. Usun produkt z koszyka\n";
    }
    cout
        << "0. Zakoncz bez skladania zamowienia\n";

    int wybor;
    cout << "Wybierz opcje: ";
    cin >> wybor;

    if (wybor == 0)
    {
      cout << "Dziekujemy za wizyte!\n";
      break;
    }

    if (wybor == 1)
    {
      string nazwa;
      string kategoria;
      cout << "Podaj nazwe produktu (lub -): ";
      cin >> nazwa;
      cout << "Podaj kategorie (lub -): ";
      cin >> kategoria;
      if (kategoria == "-")
      {
        kategoria = "";
      }
      if (nazwa == "-")
      {
        nazwa = "";
      }
      for (const Produkt &produkt : sklep.wyszukajProdukty(nazwa, kategoria))
      {
        cout << produkt.pobierzId() << ". " << produkt.pobierzNazwe()
             << " - " << produkt.pobierzCene() << " zl\n";
      }
      continue;
    }

    if (!czyAdministrator && wybor == 2)
    {
      cout << "\nDostepne produkty:\n";
      for (const Produkt &produkt : sklep.pobierzProdukty())
      {
        cout << produkt.pobierzId() << ". " << produkt.pobierzNazwe() << " - "
             << produkt.pobierzCene() << " zl\n";
      }

      int idProduktu;
      cout << "Podaj numer produktu: ";
      cin >> idProduktu;

      Produkt wybranyProdukt;
      bool znalezionoProdukt = false;
      for (const Produkt &produkt : sklep.pobierzProdukty())
      {
        if (produkt.pobierzId() == idProduktu)
        {
          wybranyProdukt = produkt;
          znalezionoProdukt = true;
          break;
        }
      }

      if (!znalezionoProdukt)
      {
        cout << "Nie ma produktu o takim numerze.\n";
        continue;
      }

      int ilosc;
      cout << "Podaj ilosc: ";
      cin >> ilosc;

      klient.dodajDoKoszyka(wybranyProdukt, ilosc);
      cout << "Dodano do koszyka: " << wybranyProdukt.pobierzNazwe()
           << ", ilosc: " << ilosc << ".\n";

      cout << "\nZawartosc koszyka:\n";
      for (const auto &wpis : klient.pobierzProduktyWKoszyku())
      {
        const Produkt &produkt = wpis.second.produkt;
        int iloscProduktu = wpis.second.ilosc;
        float kosztPozycji = produkt.pobierzCene() * iloscProduktu;

        cout << produkt.pobierzNazwe() << " x " << iloscProduktu << " - "
             << kosztPozycji << " zl\n";
      }
      cout << "Razem: " << klient.obliczKosztKoszyka() << " zl\n";
      continue;
    }

    if (!czyAdministrator && wybor == 3)
    {
      try
      {
        Zamowienie zamowienie = klient.zlozZamowienie();
        sklep.dodajZamowienie(zamowienie);
        sklep.oplacZamowienie(zamowienie.id);

        cout << fixed << setprecision(2)
             << "Zamowienie nr " << zamowienie.id
             << " zlozone. Koszt: " << zamowienie.obliczKoszt() << " zl\n";
      }
      catch (const exception &blad)
      {
        cout << blad.what() << "\n";
        continue;
      }
    }
    if (!czyAdministrator && wybor == 4)
    {
      cout << "\nZawartosc koszyka:\n";
      for (const auto &wpis : klient.pobierzProduktyWKoszyku())
      {
        const Produkt &produkt = wpis.second.produkt;
        int iloscProduktu = wpis.second.ilosc;
        float kosztPozycji = produkt.pobierzCene() * iloscProduktu;

        cout << produkt.pobierzNazwe() << " x " << iloscProduktu << " - "
             << kosztPozycji << " zl\n";
      }
      cout << "Razem: " << klient.obliczKosztKoszyka() << " zl\n";
      continue;
    }
    if (!czyAdministrator && wybor == 5)
    {
      for (const Zamowienie &zamowienie : sklep.pobierzZamowienia())
      {
        cout << "Zamowienie " << zamowienie.id
             << ", koszt: " << zamowienie.obliczKoszt() << " zl\n";
      }
      continue;
    }
    if (!czyAdministrator && wybor == 6)
    {
      for (const Zamowienie &zamowienie : sklep.pobierzZamowienia())
      {
        string status = "Oczekujaca";
        if (zamowienie.platnosc.status == StatusPlatnosci::Oplacona)
        {
          status = "Oplacona";
        }
        else if (zamowienie.platnosc.status == StatusPlatnosci::Odrzucona)
        {
          status = "Odrzucona";
        }
        cout << "Platnosc " << zamowienie.platnosc.id
             << ", kwota: " << zamowienie.platnosc.kwota
             << " zl, status: " << status << "\n";
      }
      continue;
    }
    if (!czyAdministrator && wybor == 7)
    {
      int idProduktu;
      int ilosc;
      cout << "Podaj id produktu: ";
      cin >> idProduktu;
      cout << "Podaj ilosc: ";
      cin >> ilosc;
      try
      {
        klient.usunZKoszyka(sklep.znajdzProdukt(idProduktu), ilosc);
        cout << "Produkt usunieto z koszyka.\n";
      }
      catch (const exception& blad)
      {
        cout << "Blad: " << blad.what() << "\n";
      }
      continue;
    }
    if (czyAdministrator && wybor == 2)
    {
      int id;
      string nazwa;
      double cena;
      cout << "Podaj id, nazwe i cene produktu: ";
      cin >> id >> nazwa >> cena;
      try
      {
        administrator.dodajProdukt(Produkt(id, nazwa, cena), sklep);
        cout << "Produkt dodano.\n";
      }
      catch (const exception &blad)
      {
        cout << "Blad: " << blad.what() << "\n";
      }
      continue;
    }
    if (czyAdministrator && wybor == 3)
    {
      for (const Zamowienie &zamowienie : sklep.pobierzZamowienia())
      {
        cout << "Zamowienie " << zamowienie.id
             << ", koszt: " << zamowienie.obliczKoszt() << " zl\n";
      }
      continue;
    }
    if (czyAdministrator && wybor == 4)
    {
      int idZamowienia;
      int status;
      cout << "Podaj id zamowienia: ";
      cin >> idZamowienia;
      cout << "Status (1 - W realizacji, 2 - Wyslane, 3 - Dostarczone): ";
      cin >> status;
      administrator.zmienStatusZamowienia(
          idZamowienia, static_cast<StatusZamowienia>(status), sklep);
      cout << "Status zmieniono.\n";
      continue;
    }
    if (czyAdministrator && wybor == 5)
    {
      cout << "\nDostepne produkty:\n";
      for (const Produkt &produkt : sklep.pobierzProdukty())
      {
        cout << produkt.pobierzId() << ". " << produkt.pobierzNazwe()
             << " - " << produkt.pobierzCene() << " zl\n";
      }

      int idProduktu;
      double nowaCena;
      cout << "Podaj id produktu: ";
      cin >> idProduktu;

      try
      {
        const Produkt produkt = sklep.znajdzProdukt(idProduktu);
        cout << "Podaj nowa cene: ";
        cin >> nowaCena;
        if (nowaCena < 0)
        {
          cout << "Cena nie moze byc ujemna.\n";
          continue;
        }

        administrator.edytujProdukt(
            Produkt(idProduktu, produkt.pobierzNazwe(), nowaCena,
                    produkt.pobierzKategorie()),
            sklep);
        cout << "Cene produktu zmieniono.\n";
      }
      catch (const exception &blad)
      {
        cout << "Blad: " << blad.what() << "\n";
      }
      continue;
    }
    cout << "Nieprawidlowa opcja.\n";
  }

  return 0;
}
