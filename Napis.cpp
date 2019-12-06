#include <string.h>
#include "Napis.h"

using namespace std;

Napis::Napis (const char *napis) {
  this->m_nDl = strlen(napis);
  this->m_pszNapis = new char[this->m_nDl];
  strcpy(this->m_pszNapis, napis);
}

Napis::Napis (const Napis &wzor) {
  this->m_nDl = wzor.m_nDl;
  this->m_pszNapis = new char[this->m_nDl];
  strcpy(this->m_pszNapis, wzor.m_pszNapis);
}

Napis::~Napis () {
  this->m_nDl = -1;
  delete[] this->m_pszNapis;
}

Napis &Napis::operator= (const Napis &wzor) {
  delete[] this->m_pszNapis;
  this->m_nDl = wzor.m_nDl;
  this->m_pszNapis = new char[this->m_nDl];
  strcpy(this->m_pszNapis, wzor.m_pszNapis);

  return *this;
}

bool Napis::operator== (const Napis &wzor) const {
  return strcmp(this->m_pszNapis, wzor.m_pszNapis) == 0;
}

const char *Napis::Zwroc () const {
  return this->m_pszNapis;
}

void Napis::Ustaw (const char *nowy_napis) {
  delete[] this->m_pszNapis;
  this->m_nDl = strlen(nowy_napis);
  this->m_pszNapis = new char[this->m_nDl];
  strcpy(this->m_pszNapis, nowy_napis);
}

void Napis::Wypisz () const {
  cout << this->m_pszNapis;
}

void Napis::Wpisz () {
  char buf[256];
  cin.width(256);
  cin >> buf;

  this->Ustaw(buf);
}

int Napis::SprawdzNapis (const char *por_napis) const {
  return strcmp(this->m_pszNapis, por_napis);
}

ostream &operator<< (ostream &wy, const Napis &p) {
  return wy << p.m_pszNapis;
}

istream &operator>> (istream &we, Napis &p) {
  char buf[256];
  we.width(256);
  we >> buf;

  p.Ustaw(buf);

  return we;
}
