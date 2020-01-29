#include "WirtualnaTablicaPracownikow.h"

using namespace std;

WirtualnaTablicaPracownikow::WirtualnaTablicaPracownikow (int roz) {
  this->m_nRozmiarTablicy = roz;
  this->m_nLiczbaPracownikow = 0;
  this->tablica = new Pracownik*[this->m_nRozmiarTablicy];
}

WirtualnaTablicaPracownikow::~WirtualnaTablicaPracownikow () {
  for (int i = 0; i < this->m_nLiczbaPracownikow; i++) delete this->tablica[i];
  this->m_nRozmiarTablicy = -1;
  this->m_nLiczbaPracownikow = -1;
}

void WirtualnaTablicaPracownikow::Dodaj (const Pracownik &p) {
  int i = 0;

  for (i = 0; i < this->m_nLiczbaPracownikow; i++) {
    int cmp = this->tablica[i]->Porownaj(p);
    if (cmp == 0) return;
    if (cmp == 1) break;
  }

  if (i > this->m_nRozmiarTablicy - 1) i = this->m_nRozmiarTablicy - 1;
  int n = this->m_nLiczbaPracownikow > this->m_nRozmiarTablicy - 1
    ? this->m_nRozmiarTablicy - 1 : this->m_nLiczbaPracownikow;
  
  // BUG: i + 1 element gets overwritten!
  for (; i < n; n--) this->tablica[n] = this->tablica[n - 1];

  delete this->tablica[i];
  this->tablica[i] = new Pracownik(p);
  this->m_nLiczbaPracownikow = this->m_nLiczbaPracownikow < this->m_nRozmiarTablicy
    ? this->m_nLiczbaPracownikow + 1 : this->m_nRozmiarTablicy;
}

void WirtualnaTablicaPracownikow::Usun (const Pracownik &wzorzec) {
  int index = -1;
  
  for (int i = 0; i < this->m_nLiczbaPracownikow; i++) {
    if (this->tablica[i]->Porownaj(wzorzec) == 0) {
      index = i;
      break;
    }
  }

  if (index == -1) return;

  delete this->tablica[index];

  for (int i = index; i < this->m_nLiczbaPracownikow - 1; i++) {
    this->tablica[i] = this->tablica[i + 1];
  }

  this->m_nLiczbaPracownikow = this->m_nLiczbaPracownikow - 1;
  this->tablica[this->m_nLiczbaPracownikow] = nullptr;
}

void WirtualnaTablicaPracownikow::WypiszPracownikow () const {
  for (int i = 0; i < this->m_nLiczbaPracownikow; i++) {
    this->tablica[i]->Wypisz();
  }
}

const Pracownik *WirtualnaTablicaPracownikow::Szukaj (const char *nazwisko, const char *imie) const {
  for (int i = 0; i < this->m_nLiczbaPracownikow; i++) {
    if (this->tablica[i]->SprawdzNazwisko(nazwisko) == 0 &&
      this->tablica[i]->SprawdzImie(imie) == 0) return this->tablica[i];
  }

  return nullptr;
}

const Pracownik *WirtualnaTablicaPracownikow::Szukaj (const Data &wzorzec) const {
  for (int i = 0; i < this->m_nLiczbaPracownikow; i++) {
    if (this->tablica[i]->SprawdzDate(wzorzec) == 0) return this->tablica[i];
  }

  return nullptr;
}

ostream &operator<< (ostream &wy, const WirtualnaTablicaPracownikow &t) {
  for (int i = 0; i < t.m_nLiczbaPracownikow; i++) wy << *t.tablica[i] << '\n';
  
  return wy;
}

istream &operator>> (istream &we, WirtualnaTablicaPracownikow &t) {
  Pracownik p;
  
  while (we.peek() != -1) {
    we >> p;
    t.Dodaj(p);
    we.ignore();
  }

  return we;
}
