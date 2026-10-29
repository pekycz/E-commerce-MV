#include "systemsklepu.h"
#include <iostream>
using namespace std;

int main() {
  SystemSklepu sklep;
  Administrator administrator(1, "admin", "haslo");
  sklep.dodajAdministratora(administrator);

  administrator.dodajProdukt(Produkt(1, "Klawiatura", 149.99), sklep);

  Klient& klient = sklep.zarejestrujKlienta("Ala", "haslo");
  klient.dodajDoKoszyka(sklep.znajdzProdukt(1), 3);

  Zamowienie zamowienie = klient.zlozZamowienie();
  sklep.dodajZamowienie(zamowienie);

  cout << "Zamowienie nr " << zamowienie.id
       << " zlozone. Koszt: " << zamowienie.obliczKoszt() << " zl\n";
  return 0;
}
