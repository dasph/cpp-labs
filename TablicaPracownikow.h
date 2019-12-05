#pragma once
#include "Pracownik.h"

class TablicaPracownikow {
  private:
    Pracownik m_pTablica[20];
    int m_nLiczbaPracownikow {};

  public:
    TablicaPracownikow ();
    void Dodaj (const Pracownik &p);
    void Usun (const Pracownik &wzorzec);
    void WypiszPracownikow () const;
    const Pracownik *Szukaj (const char *nazwisko, const char *imie) const;
    const Pracownik *Szukaj (const Data &wzorzec) const;
};
