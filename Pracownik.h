#pragma once
#include "Data.h"
#include "Napis.h"

class Pracownik {
  private:
    Napis m_Imie;
    Napis m_Nazwisko;
    Data m_DataUrodzenia;

  public:
    Pracownik () {};
    Pracownik (const char *imie, const char *nazwisko, int d, int m, int r);
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
};
