// PROJECT     : 01
// PROGRAM     : MENGHITUNG LUAS SEGITIGA
// AUTHOR      : MUHAMMAD GHIFARI
// NPM         : 065123020
// TANGGAL     : 28/09/2023

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    char str[9];
    float alas, tinggi, luas;
    
    luas = 0.0;
    
    ifstream file_in ("01_input.txt");
    
    if(!file_in) {
        cout << "INPUT FILE TIDAK BISA DIBUKA, ERROR, PROGRAM DIHENTIKAN" << endl;
        exit(-1);
    }
    else {
        file_in.getline(str, 9, '\n');
        file_in.getline(str, 9, '\n');
        alas = atof(str);
        
        file_in.getline(str, 9, '\n');
        file_in.getline(str, 9, '\n');
        tinggi = atof(str);
    }
    
    luas = 0.5 * alas * tinggi;
    ofstream file_out;
    file_out.open("01_output.txt");
    
    if(!file_out) {
        cout << "OUTPUT FILE TIDAK BISA DIBUKA, ERROR, PROGRMA DIHENTIKAN" << endl;
        exit(-1);
    }
    else {
        file_out << "program selesai dieksekusi" << endl;
        file_out << "Hasil Eksekusi Program adalah sebagai berikut : " << endl;
        file_out << "-------------------------------------------------" << endl;
        file_out << endl;
        
        file_out << "Alas Segitiga      = " << alas << endl;
        file_out << "Tinggi Segitiga    = " << tinggi << endl;
        file_out << "Luas Segitiga      = " << luas << endl;
    }
    
    file_in.close();
    file_out.close();
    
    cout << "Program selesai dieksekusi";
    cout << endl;
    cout << "Silahkan hasilnya dilihat pada 'OUTPUT FILE'";
    cout << endl;
}
