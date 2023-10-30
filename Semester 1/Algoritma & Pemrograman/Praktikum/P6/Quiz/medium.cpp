#include <iostream>

using namespace std;

int main() {
  int input;

  cout << "-------- PROGRAM PENENTU BILANGAN GANJIL/GENAP --------\n";
  cout << "Masukkan angka : "; cin >> input;

  if (input % 2 == 0) {
    cout << "Bilangan tersebut adalah angka genap!" << endl;
  } else {
    cout << "Bilangan tersebut adalah angka ganjil!" << endl;
  }
  return 0;
}