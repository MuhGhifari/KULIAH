#include <iostream>
using namespace std;

// Sub_Routine
// Prosedur (Tanpa Nilai Balik)
void sapaPagi() {
  cout << "Selamat Pagi " << endl;
}

// Sub_Routine
// Function (Dengan Nilai Balik)
int penjumlahan(int angka1, int angka2) {
  return angka1 + angka2;
}

// Main Routine (Main Program)
int main() {

  // Cara memanggil Sub-Routing
  sapaPagi();
  int hasil = penjumlahan(12, 5); // Parameter Aktual

  cout << "Hasil Penjumlahan 12 + 5 = " << hasil << endl;
  
  return 0;
}