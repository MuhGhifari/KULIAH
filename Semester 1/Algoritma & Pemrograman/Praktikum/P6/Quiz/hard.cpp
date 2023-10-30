#include <iostream>

using namespace std;

int main() {
  int item1, item2, item3, total;

  cout << "---------- TOKO MAROON LABKOM ----------\n";
  cout << "Katalog Barang : \n";
  cout << "1) Pulpen    = Rp 5.000\n";
  cout << "2) Binder    = Rp 30.000\n";
  cout << "3) Buku      = Rp 20.000\n";
  cout << "4) Jaket     = Rp 150.000\n";
  cout << "5) Flashdisk = Rp 50.000\n";
  cout << "----------------------------------------\n";

  cout << "Masukkan item 1 : "; cin >> item1;
  switch (item1){
  case 1:
    item1 = 5000; break;
  case 2:
    item1 = 30000; break;
  case 3:
    item1 = 20000; break;
  case 4:
    item1 = 150000; break;
  case 5:
    item1 = 50000; break;
  default: 
    cout << "Item 1 tidak ada di gudang!!!" << endl;
    return 0; break;
  }

  cout << "Masukkan item 2 : "; cin >> item2;
  switch (item2){
  case 1:
    item2 = 5000; break;
  case 2:
    item2 = 30000; break;
  case 3:
    item2 = 20000; break;
  case 4:
    item2 = 150000; break;
  case 5:
    item2 = 50000; break;
  default: 
    cout << "Item 2 tidak ada di gudang!!!" << endl;
    return 0; break;
  }

  cout << "Masukkan item 3 : "; cin >> item3;
  switch (item3){
  case 1:
    item3 = 5000; break;
  case 2:
    item3 = 30000; break;
  case 3:
    item3 = 20000; break;
  case 4:
    item3 = 150000; break;
  case 5:
    item3 = 50000; break;
  default: 
    cout << "Item 3 tidak ada di gudang!!!" << endl;
    return 0; break;
  }

  cout << "----------------------------------------\n";
  
  total = item1 + item2 + item3;
  if (total < 50000) {
    cout << "Belanja kamu sedikit banget, tambah lagi!" << endl;
  } 
  if (total > 100000 && total < 200000) {
    cout << "Belanja kamu lumayan banyak!" << endl;
  } 
  if (total > 200000) {
    cout << "Belanja kamu banyak banget!" << endl;
  }

  cout << "Total belanja kamu adalah : " << total << endl;
  return 0;
}