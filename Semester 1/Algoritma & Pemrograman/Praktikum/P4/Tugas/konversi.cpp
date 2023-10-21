// Nama   : Muhammad Ghifari
// NPM    : 065123020
// Kelas  : A (Semester 1)
#include <iostream>

using namespace std;

int main() {
	int metode;
	double suhu, hasil;

	cout << "======== PROGRAM KONVERSI SUHU ========\n"; 
	cout << "1.) Celcius    -> Fahrenheit\n"; 
	cout << "2.) Fahrenheit -> Celcius\n"; 
	cout << "=======================================\n";

	cout << "Pilih metode konversi : "; cin >> metode;
	switch (metode) {
		case 1:
			cout << "Masukkan suhu dalam Celsius : "; cin >> suhu;
			hasil = (suhu * 9 / 5) + 32;
			cout << "=======================================\n";
			cout << "Suhu dalam Fahrenheit adalah : " << suhu << endl;
			break;
		case 2:
			cout << "Masukkan suhu dalam Fahrenheit : "; cin >> suhu;
			hasil = (suhu - 32) * 5 / 9;
			cout << "=======================================\n";
			cout << "Suhu dalam Celsius adalah : " << suhu << endl;
			break;
		default:
			cout << "=======================================\n";
			cout << "Pilihan yang dimasukkan salah!!!" << endl;
	} 
	return 0;
}