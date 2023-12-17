#include <iostream>

using namespace std;

// Variabel Global
string teks1 = "Mahasiswa Ilmu Komputer";

void tampilkan() {
  cout << teks1 << endl;
}

int main() {
  // Variabel Lokal
  string teks2 = "Algoritma dan Pemrograman Dasar";

  tampilkan();

  cout << teks1 << " Sedang Belajar " << teks2 << endl;

  return 0;
}