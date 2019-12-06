#include "TablicaPracownikow.h"

using namespace std;

TablicaPracownikow::TablicaPracownikow () {
  this->m_nLiczbaPracownikow = 0;
}

void TablicaPracownikow::Dodaj (const Pracownik &p) {
  int i;

  for (i = 0; i < this->m_nLiczbaPracownikow; i++) {
    int cmp = this->m_pTablica[i].Porownaj(p);
    if (cmp == 0) return;
    if (cmp == 1) break;
  }

  if (i > 19) i = 19;
  int n = this->m_nLiczbaPracownikow > 19 ? 19 : this->m_nLiczbaPracownikow;
  
  for (; i < n; n--) this->m_pTablica[n] = this->m_pTablica[n - 1];

  this->m_pTablica[i] = p;
  this->m_nLiczbaPracownikow = this->m_nLiczbaPracownikow < 20 ? this->m_nLiczbaPracownikow + 1 : 20;
}

void TablicaPracownikow::Usun (const Pracownik &wzorzec) {
  int index = -1;
  
  for (int i = 0; i < this->m_nLiczbaPracownikow; i++) {
    if (this->m_pTablica[i].Porownaj(wzorzec) == 0) {
      index = i;
      break;
    }
  }

  if (index == -1) return;

  for (int i = index; i < this->m_nLiczbaPracownikow - 1; i++) {
    this->m_pTablica[i] = this->m_pTablica[i + 1];
  }

  this->m_nLiczbaPracownikow = this->m_nLiczbaPracownikow - 1;
  this->m_pTablica[this->m_nLiczbaPracownikow] = Pracownik();
}


void TablicaPracownikow::WypiszPracownikow () const {
  for (int i = 0; i < this->m_nLiczbaPracownikow; i++) {
    this->m_pTablica[i].Wypisz();
  }
}

const Pracownik *TablicaPracownikow::Szukaj (const char *nazwisko, const char *imie) const {
  for (int i = 0; i < this->m_nLiczbaPracownikow; i++) {
    if (this->m_pTablica[i].SprawdzNazwisko(nazwisko) == 0 &&
      this->m_pTablica[i].SprawdzImie(imie) == 0) return &this->m_pTablica[i];
  }

  return nullptr;
}

const Pracownik *TablicaPracownikow::Szukaj (const Data &wzorzec) const {
  for (int i = 0; i < this->m_nLiczbaPracownikow; i++) {
    if (this->m_pTablica[i].SprawdzDate(wzorzec) == 0) return &this->m_pTablica[i];
  }

  return nullptr;
}

ostream &operator<< (ostream &wy, const TablicaPracownikow &t) {
  for (int i = 0; i < t.m_nLiczbaPracownikow; i++) wy << t.m_pTablica[i];
  
  return wy;
}

istream &operator>> (istream &we, TablicaPracownikow &t) {
  Pracownik p;
  
  while (we.peek() != -1) {
    we >> p;
    t.Dodaj(p);
    we.ignore();
  }

  return we;
}
