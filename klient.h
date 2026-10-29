//klient.h
#ifndef KLIENT_H
#define KLIENT_H

#include "koszyk.h"

#include <string>

class klient {
  protected:
    int id_;
    std::string nazwa_;
    std::string email_;
    std::string hashHasla_;
    Koszyk* koszyk_;

  public:
    klient(int id, const std::string& nazwa, const std::string& email)
        : id_(id), nazwa_(nazwa), email_(email), koszyk_(nullptr) {}

    int pobierzId() const {
      return id_;
    }

    const std::string& pobierzNazwe() const {
      return nazwa_;
    }

    const std::string& pobierzEmail() const {
      return email_;
    }

    void zmienDane(const std::string& nazwa, const std::string& email) {
      nazwa_ = nazwa;
      email_ = email;
    }

    void ustawHashHasla(const std::string& hashHasla) {
      hashHasla_ = hashHasla;
    }

    void przypiszKoszyk(Koszyk& koszyk) {
      koszyk_ = &koszyk;
    }

    Koszyk* pobierzKoszyk() const {
      return koszyk_;
    }
};

#endif // KLIENT_H
