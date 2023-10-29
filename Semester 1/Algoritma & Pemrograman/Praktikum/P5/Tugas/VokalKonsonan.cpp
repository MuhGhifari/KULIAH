// Nama   : Muhammad Ghifari
// NPM    : 065123020
// Kelas  : A

#include <iostream>

using namespace std;

int main() {
  char input;

  cout << "---------- Program Alfabet ----------\n";
  cout << "Masukkan huruf : "; cin >> input;

  if (isalpha(tolower(input))) {
    if (input == 'a' || input == 'i' || input == 'u' || input == 'e' || input == 'o') {
      cout << "Huruf tersebut adalah vokal" << endl;
    } else {
      cout << "Huruf tersebut adalah konsonan" << endl;
    }
  } else {
    cout << "Error karena yang dimasukkan bukanlah huruf" << endl;
  }
  return 0;
}