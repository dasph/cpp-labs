#include <fstream>
#include "TablicaPracownikow.h"

using namespace std;

void help () {
  cout << "\nPease select a function:\n\t"
       << "a - add new worker\t\t\t"            << "r - remove a worker\n\t"
       << "S - search for a worker by dob\t\t"  << "s - search for a worker by name/surname\n\t"
       << "i - import workers from a file\t\t"  << "e - export workers to a file\n\t"
       << "p - print all workers\t\t\t"         << "q - quit\n"
       << "> Selected function: ";
}

int main (int argc, char **argv) {
  char c = '\0';
  TablicaPracownikow workers;

  while (c != 'q') {
    switch (c) {
      case 'a': {
        Pracownik tmp;
        tmp.Wpisz();
        workers.Dodaj(tmp);
        cout << "< New worker has been added:\n";
        tmp.Wypisz();
      } break;

      case 'r': {
        char name[64];
        char surname[64];

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
        cout << "List of all workers:\n" << workers;
      } break;

      case 's':
      case 'S': {
        char name[64];
        char surname[64];
        Data date;

        cout << "> Please enter worker\'s ";
        if (c == 's') {
          cout << "name and surname: ";
          cin >> name >> surname;
        } else {
          cout << "date of birth: ";
          cin >> date;
        }

        const Pracownik *worker = c == 's' ? workers.Szukaj(surname, name) : workers.Szukaj(date);
        if (!worker) {
          cout << "< Worker not found!\n";
          break;
        }

        cout << "< Info about " << worker->Imie() << ' ' << worker->Nazwisko() << ":\n" << *worker;
      } break;

      case 'e': {
        char filename[64];
        cout << "> Enter output file\'s name: ";
        cin >> filename;

        ofstream file(filename);
        file << workers;
        file.close();

        cout << "< List of workers has been successfully exported to " << filename << '\n';
      } break;

      case 'i': {
        char filename[64];
        cout << "> Enter input file\'s name: ";
        cin >> filename;

        ifstream file(filename);
        if (!file.good()) {
          cout << "< File doesn\'t exist!\n";
          break;
        }

        file >> workers;

        cout << "< List of workers has been successfully imported from " << filename << '\n';
        file.close();
      }
    }

    help();
    cin >> c;
  }

  return 0;
}
