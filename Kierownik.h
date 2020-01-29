#include "Pracownik.h"

class Kierownik : public Pracownik {
  private:
    Napis m_NazwaDzailu;
    int m_nLiczbaPracownikow;
  
  public:
    Kierownik (const char *nd = "", int lp = 0, const char *im = "", const char *naz = "", int d = 1, int m = 1, int r = 2000);
    Kierownik (const Kierownik &wzor);

    Kierownik &operator= (const Kierownik &wzor);
    bool operator== (const Kierownik &wzor) const;

    virtual void WypiszDane () const;
    virtual Pracownik *KopiaObiektu ();

    friend std::ostream &operator<< (std::ostream &wy, const Kierownik &s);
    friend std::istream &operator>> (std::istream &we, Kierownik &s);
};
