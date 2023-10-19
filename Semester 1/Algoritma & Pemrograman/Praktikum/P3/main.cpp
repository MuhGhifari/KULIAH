#include <iostream>

using namespace std;

int main() {
	string namaPanggilan, noHP, kota;

	cout << "Masukkan Nama Panggilan	: "; cin >> namaPanggilan;
	cout << "Masukkan Nomor HP	: "; cin >> noHP;
	cout << "Masukkan Alamat Kota	: "; cin >> kota;

	cout << endl;
	cout << "==================================\n";
	cout << "Berikut adalah data orang tersebut\n";
	cout << "==================================\n";

	cout << "Nama Panggilan	: " << namaPanggilan;
	cout << "\nNomor HP	: " << noHP;
	cout << "\nKota		: " << kota << endl;
	return 0;
}