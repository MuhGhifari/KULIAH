#include <iostream>

using namespace std;

int main() {
  int item1, item2, item3, total;

  cout << "============ PROGRAM TOKO MAROON ============\n";
  cout << "Berikut adalah katalog toko : \n";
  cout << "1) Pulpen    = Rp 5.000\n";
  cout << "2) Binder    = Rp 30.000\n";
  cout << "3) Buku      = Rp 10.000\n";
  cout << "4) Jaket     = Rp 150.000\n";
  cout << "5) Flashdisk = Rp 50.000\n";
  cout << "=============================================\n";
  cout << "MASUKKAN NO BARANG YANG DIINGINKAN\n";

  cout << "Masukkan barang ke-1 : "; cin >> item1;
  switch (item1) {
  case 1:
    item1 = 5000; break;
  case 2:
    item1 = 30000; break;
  case 3:
    item1 = 10000; break;
  case 4:
    item1 = 150000; break;
  case 5:
    item1 = 50000; break;
  default:
    cout << "Tolong pilih barang yang ada di katalog!" << endl;
    break;
  }

  cout << "Masukkan barang ke-2 : "; cin >> item2;
  switch (item2) {
  case 1:
    item2 = 5000; break;
  case 2:
    item2 = 30000; break;
  case 3:
    item2 = 10000; break;
  case 4:
    item2 = 150000; break;
  case 5:
    item2 = 50000; break;
  default:
    cout << "Tolong pilih barang yang ada di katalog!" << endl;
    break;
  }

  cout << "Masukkan barang ke-3 : "; cin >> item3;
  switch (item3) {
  case 1:
    item3 = 5000; break;
  case 2:
    item3 = 30000; break;
  case 3:
    item3 = 10000; break;
  case 4:
    item3 = 150000; break;
  case 5:
    item3 = 50000; break;
  default:
    cout << "Tolong pilih barang yang ada di katalog!" << endl;
    break;
  }

  cout << "=============================================\n";
  total = item1 + item2 + item3;
  if (total > 200000) {
    cout << "Wow... Belanjaan kamu banyak banget!!\n";
  } else if (total > 100000) {
    cout << "Belanjaan kamu lumayan banyak ya...\n";
  } else if (total <= 50000) {
    cout << "Yaaa... Belanjaan kamu sedikit banget :(\n";
  }

  cout << "Total belanjaan kamu adalah " << total << " Rupiah" << endl;
  return 0;
}