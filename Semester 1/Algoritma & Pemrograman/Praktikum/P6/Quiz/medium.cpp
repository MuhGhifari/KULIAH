#include <iostream>

using namespace std;

int main() {
  int input;
  char ulang;

  cout << "-------- PROGRAM PENENTU BILANGAN GANJIL/GENAP --------\n";
  start:
  cout << "Masukkan angka : "; cin >> input;

  if (input % 2 == 0) {
    cout << "Bilangan tersebut adalah angka genap!" << endl;
  } else {
    cout << "Bilangan tersebut adalah angka ganjil!" << endl;
  }

  cout << "-------------------------------------------------------\n";
  cout << "Apakah anda ingin menginput kembali? (Y/N) : "; cin >> ulang;
  if (tolower(ulang) == 'y') {
    goto start;
  } else if (tolower(ulang) == 'n') {
    cout << "Terima kasih..." << endl;
    return 0;
  } else {
    cout << "Input error, program dimatikan" << endl;
  }

}