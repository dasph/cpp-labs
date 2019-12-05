#pragma once

class Data {
  private:
    int m_nDzien;
    int m_nMiesiac;
    int m_nRok;
    void Koryguj ();

  public:
    Data (int d = 1, int m = 1, int r = 2000);
    int Dzien () const;
    int Miesiac () const;
    int Rok () const;
    void Ustaw (int d, int m, int r);
    void Wypisz () const;
    void Wpisz ();
    int Porownaj (const Data &wzor) const;
};
