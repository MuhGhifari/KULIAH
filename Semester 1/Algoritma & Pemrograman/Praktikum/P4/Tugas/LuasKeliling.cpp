// Nama   : Muhammad Ghifari
// NPM    : 065123020
// Kelas  : A (Semester 1)

#include <iostream>

using namespace std;

int main() {
	const float pi = 3.14159;
	float keliling, luas;
	int bentuk;

	cout << "========= PROGRAM PENGHITUNG LUAS & KELILING =========\n";
	cout << "1.) Lingkaran\n";
	cout << "2.) Segitiga Siku-Siku\n";
	cout << "3.) Persegi Panjang\n";
	cout << "\nPilihlah bangun datar yang akan dihitung : "; cin >> bentuk;
	cout << "======================================================\n";
	
	switch (bentuk) {
	case 1:
		int diameter;
		cout << "Masukkan diameter lingkaran : "; cin >> diameter;
		luas = pi * pow((diameter / 2), 2);
		keliling = 2 * pi *(diameter / 2);
		break;
	case 2:
		int tinggi, alas;
		double sisiMiring;
		cout << "Masukkan tinggi	: "; cin >> tinggi;
		cout << "Masukkan alas	: "; cin >> alas;
		sisiMiring = pow((alas / 2) + tinggi, 0.5);
		keliling = alas + tinggi + sisiMiring;
		luas = 0.5 * alas * tinggi;
		break;
	case 3:
		int panjang, lebar;
		cout << "Masukkan panjang persegi	: "; cin >> panjang;
		cout << "Masukkan lebar persegi		: "; cin >> lebar;
		luas = panjang * lebar;
		keliling = (panjang * 2) + (lebar * 2);
		break;
	default:
		cout << "Pilihan yang dimasukkan salah!!!" << endl;
		return 0;
	}
	cout << "======================================================\n";
	cout << "Keliling	: " << keliling << endl;
	cout << "Luas		: " << luas << endl;
	return 0;
}