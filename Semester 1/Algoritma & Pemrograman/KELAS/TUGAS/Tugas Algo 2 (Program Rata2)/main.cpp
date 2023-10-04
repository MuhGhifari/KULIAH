#include <iostream>

using namespace std;

int main() {
    double x1, x2, x3, x4, x5, total;
    
    cout << "=================== PROGRAM PENGHITUNG RATA-RATA ===================\n";

    cout << "Masukkan bilangan ke-1 : ";
    cin >> x1;
    
    cout << "Masukkan bilangan ke-2 : ";
    cin >> x2;
    
    cout << "Masukkan bilangan ke-3 : ";
    cin >> x3;
    
    cout << "Masukkan bilangan ke-4 : ";
    cin >> x4;
    
    cout << "Masukkan bilangan ke-5 : ";
    cin >> x5;
    
    total = x1 + x2 + x3 + x4 + x5;
    total = total / 5;
    
    cout << "\nHasil rata-rata dari bilangan-bilangan tersebut adalah : " << total << endl;
    return 0;
}
