#include <iostream>
#include <string.h>
#include "Napis.h"

using namespace std;

Napis::Napis (const char *napis) {
  this->Ustaw(napis);
}

const char *Napis::Zwroc () const {
  return this->m_pszNapis;
}

void Napis::Ustaw (const char *nowy_napis) {
  strncpy(this->m_pszNapis, nowy_napis, sizeof(this->m_pszNapis) - 1);
}

void Napis::Wypisz () const {
  cout << this->m_pszNapis;
}

void Napis::Wpisz () {
  char tmp[256];

  cin >> tmp;
  this->Ustaw(tmp);
}

int Napis::SprawdzNapis (const char *por_napis) const {
  return strcmp(this->m_pszNapis, por_napis);
}
