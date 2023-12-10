#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct Item {
  string nama;
  int harga;
};

string formatRupiah(int number) {
  const locale loc("");
  stringstream ss;
  ss.imbue(loc);

  ss << "Rp. " << number;
  return ss.str();
}

int main() {
  ifstream data("data.txt");
  if (!data) {
    cout << "File 'data.txt' tidak bisa ditemukan!\nProgram dihentikan..." << endl;
    return 1;
  }
  
  vector<Item> items;

  int i;
  string str;
  Item temp;
  while (getline(data, str)) {
    i++;
    if (i % 2 == 1) {
      temp.nama = str;
    } else {
      try {
        temp.harga = stoi(str);
        items.push_back(temp);
      }
      catch(const exception& e) {
        cerr << "\x1b[31m[WARNING] : baris " << i << " di file \"data.txt\" bukanlah angka numerik, Detail = " << e.what() << "\x1b[0m" << endl;
      }
    }
  }

  cout << "=============\x1b[34m PROGRAM KASIR \x1b[0m=============" << endl;
  for (int j = 0; j < items.size(); j++) {
    cout << j + 1 << ") " << items[j].nama << "\t: \x1b[34m" << formatRupiah(items[j].harga) << "\x1b[0m" << endl;
  }
  cout << "=========================================" << endl;
  
  int noItem, jumlah;
  int total = 0;
  char ulang;

  input_no_item:
  cout << "\x1b[32mMasukkan nomor item\t: "; cin >> str;
  try {
    noItem = stoi(str);
    if (noItem > items.size()) {
      cerr << "\x1b[31m[ERROR] : Item " << noItem << " tidak ada di data!" << endl;
      cerr << "\x1b[33mSilahkan coba kembali...\x1b[0m" << endl;
      goto input_no_item;
    }
    
  }
  catch(const exception& e) {
    cerr << "\x1b[31m[ERROR] : Input harus berbentuk angka!\x1b[0m" << endl;
    cerr << "\x1b[33mSilahkan coba kembali...\x1b[0m" << endl;
    goto input_no_item;
  }
  
  input_jumlah_item:
  cout << "\x1b[32mMasukkan jumlah item\t: "; cin >> str;
  try {
    jumlah = stoi(str);
  }
  catch(const exception& e) {
    cerr << "\x1b[31m[ERROR] : Input harus berbentuk angka!\033[0m\x1b[0m" << endl;
    cerr << "\x1b[33mSilahkan coba kembali...\x1b[0m" << endl;
    goto input_jumlah_item;
  }

  cout << "\x1b[0m-----------------------------------------" << endl;
  total = total + (items[noItem-1].harga * jumlah);
  cout << "\x1b[35mTotal\t= " << formatRupiah(total) << endl;
  cout << "\x1b[0m-----------------------------------------" << endl;

  input_ulang:
  cout << "\x1b[32mSudah selesai? (Y/N)\t: "; cin >> ulang;
  if (tolower(ulang) == 'n') {
    cout << "\x1b[0m-----------------------------------------" << endl;
    goto input_no_item;
  } else if (tolower(ulang) == 'y') {
    goto input_kembalian;
  } else {
    cerr << "\x1b[31m[ERROR] : Input harus huruf y atau n!\x1b[0m" << endl;
    cerr << "\x1b[33mSilahkan coba kembali...\x1b[0m" << endl;
    goto input_ulang;
  }
  
  input_kembalian: 
  int kembalian, tunai;
  cout << "\x1b[0m=========================================" << endl;
  cout << "\x1b[32mMasukkan uang tunai\t: "; cin >> str;
  try {
    tunai = stoi(str);
  }
  catch(const exception& e) {
    cerr << "\x1b[31m[ERROR] : Input harus berbentuk angka!\x1b[0m" << endl;
    cerr << "\x1b[33mSilahkan coba kembali...\x1b[0m" << endl;
    goto input_kembalian;
  }

  if (tunai < total) {
    cerr << "\x1b[33m[ERROR] : uang tidak cukup untuk membayar!\x1b[0b" << endl;
    cerr << "\x1b[33mSilahkan coba kembali...\x1b[0m" << endl;
    goto input_kembalian;
  }
  kembalian = tunai - total;
  cout << "\x1b[0m=========================================" << endl;
  cout << "\x1b[0m============\x1b[34m Detail Transaksi \x1b[0m===========" << endl;
  cout << "\x1b[36mTotal Belanja\t= " << formatRupiah(total) << endl;
  cout << "Uang Tunai\t= " << formatRupiah(tunai) << endl;
  cout << "\x1b[0m-----------------------------------------" << endl;
  cout << "\x1b[36mTotal Kembalian\t= " << formatRupiah(kembalian) << endl;
  cout << "Pecahan Kembalian : " << endl;

  const int pecahanRupiah[] = {100000, 50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100};
  int n = sizeof(pecahanRupiah) / sizeof(pecahanRupiah[0]);
  vector<int> banyakPecahan(n, 0);

  for (int i = 0; i < n; i++) {
    while (kembalian >= pecahanRupiah[i]) {
      kembalian -= pecahanRupiah[i];
      banyakPecahan[i]++;
    }
  }
  
  for (int i = 0; i < banyakPecahan.size(); i++) {
    if (banyakPecahan[i] > 0) {
      cout << "(" << banyakPecahan[i] << "x) " << formatRupiah(pecahanRupiah[i]) << endl;
    }
  }
  cout << "\x1b[0m=========================================" << endl;
  
  return 0;
}