#include "Data.h"

using namespace std;

Data::Data (int d, int m, int r) {
  this->Ustaw(d, m, r);
}

int Data::Dzien () const {
  return this->m_nDzien;
}

int Data::Miesiac () const {
  return this->m_nMiesiac;
}

int Data::Rok () const {
  return this->m_nRok;
}

void Data::Ustaw (int d, int m, int r) {
  this->m_nDzien = d;
  this->m_nMiesiac = m;
  this->m_nRok = r;

  this->Koryguj();
}

void Data::Wypisz () const {
  cout << this->m_nDzien << '-' << this->m_nMiesiac << '-' << this->m_nRok << '\n';
}

void Data::Wpisz () {
  int d, m, r;
  cin >> d >> m >> r;

  this->Ustaw(d, m, r);
}

void Data::Koryguj () {
  if (this->m_nRok < 0) this->m_nRok = 0;
  if (this->m_nMiesiac < 1) this->m_nMiesiac = 1;
  else if (this->m_nMiesiac > 12) this->m_nMiesiac = 12;

  int max = this->m_nMiesiac == 2 ? 28 + (this->m_nRok % 4 ? 0 : 1)
    : 30 + (this->m_nMiesiac > 7 ? (1 - this->m_nMiesiac % 2) : (this->m_nMiesiac % 2));

  if (this->m_nDzien < 1) this->m_nDzien = 1;
  else if (this->m_nDzien > max) this->m_nDzien = max;
}

int Data::Porownaj (const Data &wzor) const {
  int a = this->m_nRok * 10000 + this->m_nMiesiac * 100 + this->m_nDzien;
  int b = wzor.m_nRok * 10000 + wzor.m_nMiesiac * 100 + wzor.m_nDzien;

  return a == b ? 0 : a > b ? 1 : -1;
}

ostream &operator<< (ostream &wy, const Data &d) {
  return wy << d.m_nDzien << '-' << d.m_nMiesiac << '-' << d.m_nRok << '\n';
}

istream &operator>> (istream &we, Data &d) {
  char c;

  if (&we == &cin) we >> d.m_nDzien >> d.m_nMiesiac >> d.m_nRok;
  else we >> d.m_nDzien >> c >> d.m_nMiesiac >> c >> d.m_nRok;

  d.Koryguj();
  
  return we;
}
