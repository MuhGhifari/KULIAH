#include <iostream>

using namespace std;

// function untuk mengubah integer menjadi format rupiah
string formatRupiah(int number) {
  
  // convert var number ke tipe data string
  string str = to_string(number);
  
  // ambil jumlah karakter var str 
  int len = str.length();

  // jumlah digit yg akan dipisahkan
  int dLen = 3;

  // tambahkan kutip setiap 3 digit
  while (len > dLen) {
    str.insert(len - dLen, 1, ',');
    dLen += 4;
    len += 1;
  }
  return "Rp. " + str;
}

int main() {

  // bersihkan layar terminal
  system("clear");

  cout <<"\x1b[0m======================\x1b[34m Program Penghitung Pecahan Rupiah \x1b[0m======================" << endl;
  
  // deklarasi pecahan rupiah
  const int pecahanRupiah[] = {100000, 50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100};
  const int n = sizeof(pecahanRupiah) / sizeof(pecahanRupiah[0]);
  
  input:
  // array sebesar array pecahanRupiah dengan isi default 0
  int pecahanTerpakai[n] = {0};
  
  // var utk menampung input dr user
  int nominal;

  // var utk menampung input konfirmasi dr user
  char ulang;

  cout << "\x1b[32mMasukkan total uang : \x1b[0m"; 
  // cin >> nominal;
  // mengeluarkan error apabila input dari user menghasilkan error atau input kurang dari 0
  if (!(cin >> nominal) || nominal < 0) {
    // membersihkan error yang dihasilkan dari input user (jika ada)
    cin.clear();

    // skip data buffer yang dihasilkan dari input user (jika ada)
    cin.ignore(INT_MAX, '\n');

    cerr << "\x1b[31m[ERROR] : Input invalid, harus berbentuk angka dan lebih dari 0!\033[0m\x1b[0m" << endl;
    cerr << "\x1b[33mSilahkan coba kembali...\x1b[0m" << endl;
    goto input;
  }

  cin.clear();
  cin.ignore(INT_MAX, '\n');

  // loop banyak pecahan rupiah
  for (int i = 0; i < n; i++) {
    // loop selama nominal input lebih besar daripada daripada pecahan rupiah
    while (nominal >= pecahanRupiah[i]) {

      // kurang nominal dengan pecahan
      nominal = nominal - pecahanRupiah[i];

      // tambah 1 apabila pecahan dipakai
      pecahanTerpakai[i]++;
    }
  }
  
  cout << "\x1b[0m-------------------------------------------------------------------------------" << endl;
  cout << "Pecahan uang yang dibutuhkan :" << endl;

  // loop banyak pecahan rupiah
  for (int i = 0; i < n; i++) {

    // tampilkan pecahan yg terpakai 
    if (pecahanTerpakai[i] > 0) {
      cout << "\x1b[0m(\x1b[35m" << pecahanTerpakai[i] << "x\x1b[0m) \x1b[36m" << formatRupiah(pecahanRupiah[i]) << endl;
    }
  }

  // output sisa (jika ada)
  if (nominal > 0) {
    cout << "\x1b[33mSisa : " << formatRupiah(nominal) << endl;
  }

  konfirmasi_selesai:
  cout << "\x1b[0m-------------------------------------------------------------------------------" << endl;
  cout << "\x1b[32mApakah anda ingin input ulang? (Y/N) : \x1b[0m"; 
  
  // mengeluarkan error apabila input dari user menghasilkan error atau input adalah nilai konfirmasi adalah selain 'y' dan 'n'
  if (!(cin >> ulang) || (tolower(ulang) != 'y' && tolower(ulang) != 'n')) {
    // membersihkan error yang dihasilkan dari input user (jika ada)
    cin.clear();

    // skip data buffer yang dihasilkan dari input user (jika ada)
    cin.ignore(INT_MAX, '\n');

    cerr << "\x1b[31m[ERROR] : Input harus huruf y atau n!\x1b[0m" << endl;
    cerr << "\x1b[33mSilahkan coba kembali...\x1b[0m" << endl;
    goto konfirmasi_selesai;
  }

  // apabila perulangan dikonfirmasi user
  if (tolower(ulang) == 'y') {
    cout << "\x1b[0m-------------------------------------------------------------------------------" << endl;

    // membersihkan error yang dihasilkan dari input user (jika ada)
    cin.clear();

    // skip data buffer yang dihasilkan dari input user (jika ada)
    cin.ignore(INT_MAX, '\n');

    goto input;
  } else {
    cout << "Terima kasih..." << endl;
  }
  
  return 0;
}