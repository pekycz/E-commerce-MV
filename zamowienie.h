#ifndef ZAMOWIENIE_H
#define ZAMOWIENIE_H

#include <string>

class zamowienie {
  private:
    int id;
    double koszt;
    int pozycjaZamowienia;

  public:
    zamowienie() : id(0), koszt(0.0), pozycjaZamowienia(0) {}

    std::string zamowienieKomunikat() const {
      return "Zamowienie zlozone";
    }
};

#endif // ZAMOWIENIE_H
