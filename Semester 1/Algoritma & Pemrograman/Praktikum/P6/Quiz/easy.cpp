#include <iostream>

using namespace std;

int main() {
  int idr, usd;

  cout << "------- PROGRAM KONVERSI USD KE IDR -------\n";
  cout << "Masukkan jumlah usd : "; cin >> usd;
  idr = usd * 15000;
  cout << usd << " dollar adalah " << idr << " rupiah" << endl;
  return 0;
}