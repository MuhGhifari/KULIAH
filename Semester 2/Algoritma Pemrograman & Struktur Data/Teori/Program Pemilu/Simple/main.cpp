/*
(Input Output Stream)
library utk operasi stream pada input & output
*/
#include <iostream>

/*
(File Stream)
library utk stream pada file seperti read/write
*/
#include <fstream>

/*
(String Stream)
library utk melakukan operasi stream pada string
*/
#include <sstream> 

/* 
(Input Output Manipulation)
library utk memanipulasi input/output
*/
#include <iomanip> 

// library utk generate nomor acak
#include <random>

// library utk memanipulasi string
#include <string>

// library utk tipe data array dinamis
#include <vector>

// library utk tipe data key-value
#include <map>

// memakai nama std di satu scope
using namespace std;

// Deklarasi Function printTabel()
void printTabel(const vector<vector<string>>& tabel, ofstream& output);

int main() {

  // Deklarasi variabel file input stream
  ifstream fileInput("input.txt");

  // Deklararsi variabel file output stream
  ofstream fileOutput;
  fileOutput.open("output.txt");

  // Memastikan file tidak kosong
  if(!fileInput) {
		cerr << "[\x1b[31mERROR\x1b[0m] : file 'input.csv' tidak terdeteksi!" << endl;
		exit(1);
	}

  // Variabel utk menampung isi string sementara
  string str;

  // Deklarasi variabel array 2 dimensi (baris & kolom) utk dijadikan tabel
  vector<vector<string>> tabelHasil;

  // Deklarasi paslon apa saja yg dicari di file input
  vector<string> kandidat = {"01", "02", "03"};

  /*
  Deklarasi variabel key-value untuk menyimpan banyak suara
  key (kata kunci)-nya berbentuk string yang memiliki value nomor paslon : ["01", "02", "03"]
  valuenya berbentuk integer untuk menampung jumlah suara yg didapat paslon 
  */ 
  map<string, int> suaraKandidat;

  // Deklarasi variabel untuk menyimpan banyak suara yang dipungut
  int totalSuara = 0;

  /*
  Loop yang membaca stream dari file input per baris.
  teks setiap baris akan disimpan kedalam variabel 'str'
  */
  while (getline(fileInput, str)) {

    // berhenti membaca file ketika sudah mencapai baris ke-300
    if (totalSuara >= 300) {
      break;
    }

    // deklarasi variabel untuk validasi baris
    bool inputValid = false;

    /*
    Looping array 'kandidat'.
    'auto' mendeteksi tipe data secara otomatis.
    variabel 'paslon' mewakili tiap data dari array 'kandidat' satu per satu saat looping
    */
    for (auto paslon : kandidat) {
      
      // ubah status validasi input apabila data di baris cocok dengan data di array 'kandidat'
      if (str == paslon) {
        inputValid = true;

        // memberhentikan looping ketika data ketemu
        break;
      }
    }

    // apabila input valid, tambah 1 suara kandidat & suara total
    if (inputValid) {
      suaraKandidat[str]++;
      totalSuara++;
    }
  }

  // tutup file input.txt
  fileInput.close();

  /*
  Menghitung persentase suara tiap kandidat
  */

  // Deklarasi variabel array untuk menyimpan baris jumlah suara & persentase suara
  vector<string> suara, persentaseSuara;

  /*
  Looping array 'kandidat'.
  'auto' mendeteksi tipe data secara otomatis.
  variabel 'paslon' mewakili tiap data dari array 'kandidat' satu per satu saat looping
  */
  for (auto paslon : kandidat) {

    /*
    Deklarasi variabel string 'persentase'.
    'ostringstream' adalah class yang berfungsi utk memanipulasi format string
    */
    ostringstream persentase;

    // Deklarasi variabel 'persen' berbentuk float (desimal)
    float persen;

    // menyimpan jumlah suara paslon yg sedang di-loop
    int jumlahSuara = suaraKandidat[paslon];

    // apabila paslon adalah "02", tambah suara dgn angka acak dari 50-100
    if (paslon == "02") {

      // Deklarasi variabel 'acak' dengan class random_device
      random_device acak;

      // Mendefinisikan generator nomor acak dengan metode "Mersenne Twister"
      mt19937 gen(acak());

      // menyatakan distribusi yg diinginkan adalah dari angka 50 sampai 100
      uniform_int_distribution<int> distribution(50, 100);

      // menghasilkan nomor acak antara 50-100 menggunakan metode "Mersenne Twister"
      int suaraTambahan = distribution(gen);

      // menampilkan banyak suara tambahan pada console
      cout << "Suara Tambahan : " << suaraTambahan << endl;

      // menambahkan suara tambahan pada suara kandidat dan total suara
      jumlahSuara += suaraTambahan;
      totalSuara += suaraTambahan;
    }

    /*
    Menghitung persentase suara kandidat yang sedang di-loop.
    'static_cast<float>' digunakan utk konversi integer (bulat) ke tipe data float (desimal)
    */ 
    persen = (static_cast<float>(jumlahSuara) / totalSuara) * 100;

    /*
    Me-format variabel 'persentase' dengan 1 digit desimal dan simbol "%".
    'setprecision(1)' menyatakan bahwa presisi desimalnya adalah 1 (hanya ada 1 digit di belakang koma).
    'fixed' menyatakan pemakaian notasi tetap, bukan notasi scientific. 
    apabila 'fixed' tidak dipakai... angka "123000" akan dinyatakan sebagai "1.23e-05".
    */
    persentase << fixed << setprecision(1) << persen << "%";

    // masukkan hasil kalkulasi ke variabel array 'persentaseSuara'
    persentaseSuara.push_back(persentase.str());

    // masukkan jumlah suara ke variabel array 'suara'
    str = to_string(jumlahSuara) + " suara";
    suara.push_back(str);
  }

  /*
  Memasukkan tiap baris ke dalam variabel array 'tabelHasil'
  */
  // baris 1 = ["01", "02", "03"]
  tabelHasil.push_back(kandidat);
  // baris 2 = ["X suara", "X suara", "X suara"]
  tabelHasil.push_back(suara);
  // baris 2 = ["X.X%", "X.X%", "X.X%"]
  tabelHasil.push_back(persentaseSuara);

  // keluarkan isi variabel 'tabelHasil' pada file output dalam bentuk tabel
  printTabel(tabelHasil, fileOutput);

  // tutup file output.txt
  fileOutput.close();

  // meng-indikasikan eksekusi sukses
  return 0;
}

/*
Function untuk membuat tabel secara otomatis.
Menerima argumen berbentuk array string 2 dimensi & output filestream
*/
void printTabel(const vector<vector<string>>& tabel, ofstream& output) {
  /* 
  Menghitung lebar kolom dengan mencari
  string yang paling panjang di kolom 
  */

  /*
  Deklarasi var array 'lebarKolom' dgn ukuran yg sama dgn jumlah kolom tabel yg diterima
  dan isi dengan nilai default "0".
  'size_t' adalah integer yg hanya bisa menyimpan bilangan positif
  */
  vector<size_t> lebarKolom(tabel[0].size(), 0);

  /*
  Looping tabel.
  Loop luar = looping baris tabel
  Loop Dadalam = looping kolom tabel
  */
  for (const auto& baris : tabel) {
    for (size_t i = 0; i < baris.size(); ++i) {

      // pilih lebar kolom yang lebih besar antara lebar kolom sebelumnya dan lebar data baru
      lebarKolom[i] = max(lebarKolom[i], baris[i].size());
    }
  }

  // Cetak border atas
  for (size_t i = 0; i < lebarKolom.size(); ++i) {
    
    // cetak border kolom dengan "-" sebagai garis dan "+" sebagai pemisah antara kolom
    output << "+" << string(lebarKolom[i] + 2, '-');
  }
  output << "+" << endl;

  /*
  Cetak konten tabel
  */

  // Deklarasi variabel index tabel
  auto indeksTabel = tabel.begin();

  // Looping tiap baris tabel
  for (const auto& baris : tabel) {

    // looping tiap kolom baris
    for (size_t i = 0; i < baris.size(); ++i) {

      // Gunakan "| " sebagai pemisah kolom dan set lebar kolom menggunakan var 'lebarKolom'
      output << "| " << setw(lebarKolom[i] + 1) << left << baris[i];
    }
    output << "|" << endl;

    // apabila loop adalah baris pertama maka cetak border bawah utk menandakan baris header
    if (indeksTabel == tabel.begin()) {
      for (size_t i = 0; i < lebarKolom.size(); ++i) {
        output << "+" << string(lebarKolom[i] + 2, '-');
      }
      output << "+" << endl;
    }

    // tambah index tabel
    indeksTabel++;
  }

  // Cetak border bawah
  for (size_t i = 0; i < lebarKolom.size(); ++i) {
    output << "+"<< string(lebarKolom[i] + 2, '-');
  }
  output << "+";
}