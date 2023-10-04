#include <iostream> // library yang memberi program fungsi input/output

using namespace std; // buat library standar c++ menjadi global

int main() {
    // deklarasi variabel
    double x1, x2, x3, x4, x5, total;
    
    // mengeluarkan judul
    cout << "=================== PROGRAM PENGHITUNG RATA-RATA ===================\n";

    // prompt untuk bilangan ke 1
    cout << "Masukkan bilangan ke-1 : ";
    cin >> x1;
    
    // prompt untuk bilangan ke 2
    cout << "Masukkan bilangan ke-2 : ";
    cin >> x2;
    
    // prompt untuk bilangan ke 3
    cout << "Masukkan bilangan ke-3 : ";
    cin >> x3;
    
    // prompt untuk bilangan ke 4
    cout << "Masukkan bilangan ke-4 : ";
    cin >> x4;
    
    // prompt untuk bilangan ke 5
    cout << "Masukkan bilangan ke-5 : ";
    cin >> x5;
    
    // rumus menghitung rata-rata
    total = (x1 + x2 + x3 + x4 + x5) / 5;
    
    // output hasil perhitungan
    cout << "\nHasil rata-rata dari bilangan-bilangan tersebut adalah : " << total << endl;
    return 0;
}
