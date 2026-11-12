#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H

#include <string>

using namespace std;

class Uzytkownik {
  protected:
    int id = 0;
    string nazwa;
    string haslo;

  public:
    virtual ~Uzytkownik() = default;
    virtual string rola() const = 0;
    const string& pobierzNazwe() const;
    bool hasloPasuje(const string& podaneHaslo) const;
};

#endif // UZYTKOWNIK_H