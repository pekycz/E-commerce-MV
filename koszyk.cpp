#include "produkt.h"
#include "koszyk.h"
#include <map>
#include <stdexcept>

using namespace std;

void Koszyk::dodajProdukt(const Produkt& produkt, int ilosc) {
    if (ilosc <= 0) {
    throw invalid_argument("Ilosc musi byc wieksza od zera.");
    }

    auto pozycja = produkty_.find(produkt.id);
    if (pozycja == produkty_.end()) {
    produkty_.emplace(produkt.id, Pozycja{produkt, ilosc});
    } else {
    pozycja->second.ilosc += ilosc;
    }
}

void Koszyk::usunProdukt(const Produkt& produkt, int ilosc) {
    if (ilosc <= 0) {
    throw invalid_argument("Ilosc musi byc wieksza od zera.");
    }

    auto pozycja = produkty_.find(produkt.id);
    if (pozycja == produkty_.end()) {
    throw out_of_range("Produktu nie ma w koszyku.");
    }

    if (ilosc >= pozycja->second.ilosc) {
    produkty_.erase(pozycja);
    } else {
    pozycja->second.ilosc -= ilosc;
    }
}

map<int, Koszyk::Pozycja>& Koszyk::pobierzProdukty(){
    return produkty_;
}

void Koszyk::wyczysc() {
    produkty_.clear();
};
