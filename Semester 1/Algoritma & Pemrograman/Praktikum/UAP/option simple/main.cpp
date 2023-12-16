#include <iostream>
#include <sstream>

using namespace std;

string formatRupiah(int number) {
  const locale loc("");
  stringstream ss;
  ss.imbue(loc);

  ss << "Rp. " << number;
  return ss.str();
}

int main() {
  const int pecahanRupiah[] = {100000, 50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100};
  int n = sizeof(pecahanRupiah) / sizeof(pecahanRupiah[0]);
  vector<int> banyakPecahan(n, 0);
  int tunai;
  cout <<"\x1b[0m======================\x1b[34m Program Penghitung Pecahan Rupiah \x1b[0m======================" << endl;
  cout << "\x1b[32mMasukkan total uang : \x1b[0m"; cin >> tunai;

  for (int i = 0; i < n; i++) {
    while (tunai >= pecahanRupiah[i]) {
      tunai -= pecahanRupiah[i];
      banyakPecahan[i]++;
    }
  }
  
  cout << "\x1b[0m--------------------------------------------" << endl;
  for (int i = 0; i < banyakPecahan.size(); i++) {
    if (banyakPecahan[i] > 0) {
      cout << "\x1b[0m(\x1b[35m" << banyakPecahan[i] << "x\x1b[0m) \x1b[36m" << formatRupiah(pecahanRupiah[i]) << endl;
    }
  }
}