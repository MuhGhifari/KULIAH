// Nama   : Muhammad Ghifari
// NPM    : 065123020
// Kelas  : A

#include <iostream>

using namespace std;

int main() {
  int input;

  cout << "------------- Program Bilangan Positif/Negatif -------------\n";
  cout << "Masukkan angka : "; cin >> input;
  
  if (input > 0){
    cout << "Angka tersebut adalah bilangan positif" << endl;
  } else if (input < 0){
    cout << "Angka tersebut adalah bilangan negatif" << endl;
  } else {
    cout << "Angka tersebut bukanlah positif maupun negatif" << endl;
  }
  return 0;
}