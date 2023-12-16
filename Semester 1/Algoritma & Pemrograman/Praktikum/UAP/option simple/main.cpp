#include <iostream>
#include <vector>

using namespace std;

string formatRupiah(int number) {
  string str = to_string(number);
  int len = str.length();
  int dlen = 3;

  while (len > dlen) {
    str.insert(len - dlen, 1, ',');
    dlen += 4;
    len += 1;
  }
  return "Rp. " + str;
}

int main() {
  const int pecahanRupiah[] = {100000, 50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100};
  int n = sizeof(pecahanRupiah) / sizeof(pecahanRupiah[0]);
  vector<int> banyakPecahan(n, 0);
  string str;
  int tunai;
  char ulang;
  input:
  cout <<"\x1b[0m======================\x1b[34m Program Penghitung Pecahan Rupiah \x1b[0m======================" << endl;
  cout << "\x1b[32mMasukkan total uang : \x1b[0m"; cin >> str;
  try {
    tunai = stoi(str);
  }
  catch(const exception& e) {
    cerr << "\x1b[31m[ERROR] : Input harus berbentuk angka!\033[0m\x1b[0m" << endl;
    cerr << "\x1b[33mSilahkan coba kembali...\x1b[0m" << endl;
    goto input;
  }

  for (int i = 0; i < n; i++) {
    while (tunai >= pecahanRupiah[i]) {
      tunai -= pecahanRupiah[i];
      banyakPecahan[i]++;
    }
  }
  
  cout << "\x1b[0m-------------------------------------------------------------------------------" << endl;
  cout << "Pecahan uang yang dibutuhkan :" << endl;
  for (int i = 0; i < banyakPecahan.size(); i++) {
    if (banyakPecahan[i] > 0) {
      cout << "\x1b[0m(\x1b[35m" << banyakPecahan[i] << "x\x1b[0m) \x1b[36m" << formatRupiah(pecahanRupiah[i]) << endl;
    }
  }

  konfirmasi_selesai:
  cout << "\x1b[0m-------------------------------------------------------------------------------" << endl;
  cout << "\x1b[32mApakah anda ingin input ulang? (Y/N) : \x1b[0m"; cin >> ulang;
  if (tolower(ulang) == 'y') {
    cout << "\x1b[0m-------------------------------------------------------------------------------" << endl;
    goto input;
  } else if (tolower(ulang) == 'n') {
    cout << "Terima kasih..." << endl;
  } else {
    cerr << "\x1b[31m[ERROR] : Input harus huruf y atau n!\x1b[0m" << endl;
    cerr << "\x1b[33mSilahkan coba kembali...\x1b[0m" << endl;
    goto konfirmasi_selesai;
  }
  
  return 0;
}