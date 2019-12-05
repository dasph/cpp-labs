#include <iostream>
#include "TablicaPracownikow.h"

using namespace std;

void help () {
  cout << "\nPease select a function:\n"
       << "\ta - add new worker\n"
       << "\tr - remove a worker\n"
       << "\tp - print all workers\n"
       << "\ts - search for a worker by name/surname\n"
       << "\tS - search for a worker by dob\n"
       << "\tq - quit\n"
       << "> Selected function: ";
}

int main (int argc, char **argv) {
  char c = '\0';
  TablicaPracownikow workers;

  while (c != 'q') {
    switch (c) {
      case 'a': {
        Pracownik tmp = Pracownik();
        tmp.Wpisz();
        workers.Dodaj(tmp);
        cout << "< New worker has been added:\n";
        tmp.Wypisz();
      } break;

      case 'r': {
        char name[40];
        char surname[40];

        cout << "> Please enter worker\'s name and surname: ";
        cin >> name >> surname;

        const Pracownik *worker = workers.Szukaj(surname, name);
        if (!worker) {
          cout << "< Worker not found!\n";
          break;
        }

        workers.Usun(*worker);
        cout << "< Worker " << name << ' ' << surname << " has been successfully removed\n";
      } break;

      case 'p': {
        cout << "List of all workers:\n";
        workers.WypiszPracownikow();
      } break;

      case 's':
      case 'S': {
        char name[40];
        char surname[40];
        Data date;

        cout << "> Please enter worker\'s ";
        if (c == 's') {
          cout << "name and surname: ";
          cin >> name >> surname;
        } else {
          cout << "date of birth:\n  ";
          date.Wpisz();
        }

        const Pracownik *worker = c == 's' ? workers.Szukaj(surname, name) : workers.Szukaj(date);
        if (!worker) {
          cout << "< Worker not found!\n";
          break;
        }

        cout << "< Info about " << name << ' ' << surname << ":\n";
        worker->Wypisz();
      }
    }

    help();
    cin >> c;
  }

  return 0;
}
