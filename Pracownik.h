#pragma once
#include "Data.h"
#include "Napis.h"

class Pracownik {
  private:
    Napis m_Imie;
    Napis m_Nazwisko;
    Data m_DataUrodzenia;
    const int m_nIDZatrudnienia;

  public:
    Pracownik (const char *im = "", const char *naz = "", int d = 1, int m = 1, int r = 2000);
    Pracownik (const Pracownik &wzor);
    ~Pracownik () {};

    Pracownik &operator= (const Pracownik &wzor);
    bool operator== (const Pracownik &wzor) const;

    const char *Imie () const;
    const char *Nazwisko () const;
    void Imie (const char *nowe_imie);
    void Nazwisko (const char *nowe_nazwisko);
    void DataUrodzenia (int nowy_dzien, int nowy_miesiac, int nowy_rok);
    void Wypisz () const;
    void Wpisz ();
    int SprawdzImie (const char *por_imie) const;
    int SprawdzNazwisko (const char *por_nazwisko) const;
    int SprawdzDate (const Data &por_data) const;
    int Porownaj (const Pracownik &wzorzec) const;

    friend std::ostream &operator<< (std::ostream &wy, const Pracownik &p);
    friend std::istream &operator>> (std::istream &we, Pracownik &p);
};
