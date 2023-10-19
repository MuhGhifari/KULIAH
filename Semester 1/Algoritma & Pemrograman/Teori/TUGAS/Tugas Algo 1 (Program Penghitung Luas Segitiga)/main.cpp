#include <iostream> // library yang memberi program fungsi input/output
#include <fstream> // library yang memberi program akses read/write file 

using namespace std;

int main() {
    // deklarasi variabel
    char str[9];
    float alas, tinggi, luas = 0.0;
    
    // read file 01_input.txt
    ifstream file_in ("01_input.txt"); // file_in itu seperti variabel kelas ifstream
    
    if(!file_in) { // jika file gagal dibaca
        cout << "INPUT FILE TIDAK BISA DIBUKA, ERROR, PROGRAM DIHENTIKAN" << endl;
        exit(-1);
    }
    else { // jika file berhasil dibaca
        // membaca baris ke 2 dari file 01_input.txt dan memasukkannya ke dalam variabel str
        file_in.getline(str, 9, '\n');
        file_in.getline(str, 9, '\n');

        // masukkan nilai str ke dalam variabel alas
        alas = atof(str); // atof() untuk konversi nilai karakter ke numerik
        
        // membaca baris ke 4 dari file 01_input.txt dan memasukkannya ke dalam variabel str
        file_in.getline(str, 9, '\n');
        file_in.getline(str, 9, '\n');

        // masukkan nilai str ke dalam variabel tinggi
        tinggi = atof(str); // atof() untuk konversi nilai karakter ke numerik
    }
    
    // rumus aritmatik mencari luas segitiga
    luas = 0.5 * alas * tinggi;
    
    // deklarasi variabel kelas ofstream
    ofstream file_out;

    // buat/edit file 01_output.txt
    file_out.open("01_output.txt");
    
    if(!file_out) { // jika file gagal dibuat
        cout << "OUTPUT FILE TIDAK BISA DIBUKA, ERROR, PROGRAM DIHENTIKAN" << endl;
        exit(-1);
    }
    else { // jika file berhasil dibuat
        file_out << "program selesai dieksekusi" << endl;
        file_out << "Hasil Eksekusi Program adalah sebagai berikut : " << endl;
        file_out << "-------------------------------------------------" << endl;
        file_out << endl;
        
        file_out << "Alas Segitiga      = " << alas << endl;
        file_out << "Tinggi Segitiga    = " << tinggi << endl;
        file_out << "Luas Segitiga      = " << luas << endl;
    }
    
    // tutup akses ke file 01_input.txt & 01_output.txt
    file_in.close();
    file_out.close();
    
    cout << "Program selesai dieksekusi";
    cout << endl;
    cout << "Silahkan hasilnya dilihat pada 'OUTPUT FILE'";
    cout << endl;
}