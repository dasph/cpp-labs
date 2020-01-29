#include "Kierownik.h"

using namespace std;

Kierownik::Kierownik (const char *nd, int lp, const char *im, const char *naz, int d, int m, int r) : Pracownik(im, naz, d, m, r) {
  this->m_NazwaDzailu = nd;
  this->m_nLiczbaPracownikow = lp;
}

Kierownik::Kierownik (const Kierownik &wzor) : Pracownik(wzor) {
  this->m_NazwaDzailu = wzor.m_NazwaDzailu;
  this->m_nLiczbaPracownikow = wzor.m_nLiczbaPracownikow;
}

Kierownik &Kierownik::operator= (const Kierownik &wzor) {
  if (this == &wzor) return *this;

  this->~Kierownik();
  new (this) Kierownik(wzor);
  
  return *this;
}

bool Kierownik::operator== (const Kierownik &wzor) const {
  return this->Porownaj(wzor) == 0
    && this->m_NazwaDzailu.SprawdzNapis(wzor.m_NazwaDzailu.Zwroc()) == 0
    && this->m_nLiczbaPracownikow == wzor.m_nLiczbaPracownikow;
}

void Kierownik::WypiszDane () const {
  cout << "Manager\'s data:";
  this->Wypisz();
  cout << "    > Department Name:\t\t" << this->m_NazwaDzailu
       << "\n    > Number of employees:\t" << this->m_nLiczbaPracownikow << '\n';
}

Pracownik *Kierownik::KopiaObiektu () {
  // TODO: ?
  return this;
}

ostream &operator<< (ostream &wy, const Kierownik &s) {
  return wy << s.Imie() << "\t\t" << s.Nazwisko() << "\t\t" << s.DataUrodzenia()
            << "\t\t" << s.m_NazwaDzailu << "\t\t" << s.m_nLiczbaPracownikow << '\n';
}

istream &operator>> (istream &we, Kierownik &s) {
  Napis im, naz;
  Data data;
  
  we >> im >> naz >> data >> s.m_NazwaDzailu >> s.m_nLiczbaPracownikow;

  s.Imie(im.Zwroc());
  s.Nazwisko(naz.Zwroc());
  s.DataUrodzenia(data.Dzien(), data.Miesiac(), data.Rok());

  return we;
}
