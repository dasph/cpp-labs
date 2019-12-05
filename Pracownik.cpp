#include <iostream>
#include <string.h>
#include "Pracownik.h"

using namespace std;

Pracownik::Pracownik (const char *imie, const char *nazwisko, int d, int m, int r) {
  this->Imie(imie);
  this->Nazwisko(nazwisko);
  this->DataUrodzenia(d, m ,r);
}

const char *Pracownik::Imie () const {
  return this->m_Imie.Zwroc();
}

const char *Pracownik::Nazwisko () const {
  return this->m_Nazwisko.Zwroc();
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
  this->m_Imie.Wypisz();
  cout << "        ";
  this->m_Nazwisko.Wypisz();
  cout << "        ";
  this->m_DataUrodzenia.Wypisz();
}

void Pracownik::Wpisz () {
  cout << "Enter workers name: ";
  this->m_Imie.Wpisz();
  cout << "Enter workers surname: ";
  this->m_Nazwisko.Wpisz();
  cout << "Enter workers date of birth: \n";
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
