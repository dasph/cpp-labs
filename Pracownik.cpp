#include "Pracownik.h"

using namespace std;

Pracownik::Pracownik (const char *imie, const char *nazwisko, int d, int m, int r) : m_nIDZatrudnienia(reinterpret_cast<long>(this) & 0xffffffff) {
  this->Imie(imie);
  this->Nazwisko(nazwisko);
  this->DataUrodzenia(d, m ,r);
}

Pracownik::Pracownik (const Pracownik &wzor) : m_nIDZatrudnienia(reinterpret_cast<long>(this) & 0xffffffff) {
  this->m_Imie = wzor.m_Imie;
  this->m_Nazwisko = wzor.m_Nazwisko;
  this->m_DataUrodzenia = wzor.m_DataUrodzenia;
}

Pracownik &Pracownik::operator= (const Pracownik &wzor) {
  if (this == &wzor) return *this;

  this->~Pracownik();
  new (this) Pracownik(wzor);
  
  return *this;
}

bool Pracownik::operator== (const Pracownik &wzor) const {
  return this->Porownaj(wzor) == 0;
}

const char *Pracownik::Imie () const {
  return this->m_Imie.Zwroc();
}

const char *Pracownik::Nazwisko () const {
  return this->m_Nazwisko.Zwroc();
}

Data Pracownik::DataUrodzenia () const {
  return this->m_DataUrodzenia;
}

void Pracownik::Imie (const char *nowe_imie) {
  this->m_Imie.Ustaw(nowe_imie);
}

void Pracownik::Nazwisko (const char *nowe_nazwisko) {
  this->m_Nazwisko.Ustaw(nowe_nazwisko);
}

void Pracownik::DataUrodzenia (int nowy_dzien, int nowy_miesiac, int nowy_rok) {
  this->m_DataUrodzenia.Ustaw(nowy_dzien, nowy_miesiac, nowy_rok);
}

void Pracownik::Wypisz () const {
  cout << "\n    > ID:\t\t\t" << this->m_nIDZatrudnienia
       << "\n    > Name:\t\t\t" << this->m_Imie
       << "\n    > Surname:\t\t\t" << this->m_Nazwisko
       << "\n    > Date of Birth:\t\t" << this->m_DataUrodzenia;
}

void Pracownik::Wpisz () {
  cout << "> Enter workers name, surname and date of birth: ";
  this->m_Imie.Wpisz();
  this->m_Nazwisko.Wpisz();
  this->m_DataUrodzenia.Wpisz();
}

int Pracownik::SprawdzImie (const char *por_imie) const {
  return this->m_Imie.SprawdzNapis(por_imie);
}

int Pracownik::SprawdzNazwisko (const char *por_nazwisko) const {
  return this->m_Nazwisko.SprawdzNapis(por_nazwisko);
}

int Pracownik::SprawdzDate (const Data &por_data) const {
  return this->m_DataUrodzenia.Porownaj(por_data);
}

int Pracownik::Porownaj (const Pracownik &wzorzec) const {
  int nazwisko = this->m_Nazwisko.SprawdzNapis(wzorzec.m_Nazwisko.Zwroc());
  if (nazwisko != 0) return nazwisko > 0 ? 1 : -1;

  int imie = this->m_Imie.SprawdzNapis(wzorzec.m_Imie.Zwroc());
  if (imie != 0) return imie > 0 ? 1 : -1;

  int data = this->m_DataUrodzenia.Porownaj(wzorzec.m_DataUrodzenia);
  return data;
}

void Pracownik::WypiszDane () const {
  cout << "Worker\'s data:";
  this->Wypisz();
}

Pracownik *Pracownik::KopiaObiektu () {
  // TODO: ?
  return this;
}

ostream &operator<< (ostream &wy, const Pracownik &p) {
  return wy << p.m_nIDZatrudnienia << "\t\t" << p.m_Imie << "\t\t" << p.m_Nazwisko << "\t\t" << p.m_DataUrodzenia;
}

istream &operator>> (istream &we, Pracownik &p) {
  return we >> p.m_Imie >> p.m_Nazwisko >> p.m_DataUrodzenia;
}
