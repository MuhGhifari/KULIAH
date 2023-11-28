#include <iostream>

using namespace std;

int main() {
	const double kkm = 90;
	int pilihan;
	double nilai;
	char validasi;

	cout << "========= BAHASA PEMROGRAMAN =========" << endl;
	cout << "1.) Python" << endl;
	cout << "2.) Verilog HDL" << endl;
	cout << "3.) Javascript" << endl;
	cout << "======================================" << endl;
	cout << "Masukkan bahasa pilihan anda	: "; cin >> pilihan;
	input:
	cout << "Masukkan nilai anda		: "; cin >> nilai;
	cout << "======================================" << endl;
	if (pilihan > 1 && pilihan < 4) {
		switch (pilihan) {
			case 1:
				if (nilai >= 80) {
					cout << "Kamu Memasuki Kawasan Python" << endl;
				}
			case 2:
				if (nilai >= 80) {
					cout << "Kamu Memasuki Kawasan Verilog" << endl;
				}
			case 3:
				if (nilai >= 80) {
					cout << "Kamu Memasuki Kawasan Node.JS" << endl;
				}
		}
	} else {
		cout << "Pilihan tidak valid" << endl;
		goto input;
	}

	cout << "======================================" << endl;
	cout << "KKM		: 90" << endl;
	cout << "Nilai Anda	: " << nilai << endl;
	cout << "Apakah data ini benar? (Y/N) : "; cin >> validasi;
	if (tolower(validasi) == 'n') {
		cout << "======================================" << endl;
		goto input;
	} else if (tolower(validasi) == 'y') {
		cout << "======================================" << endl;
		if (nilai < 90) {
			cout << "KAMU TIDAK LULUS" << endl;
		} else {
			cout << "KAMU LULUS" << endl;
		}
	}
	return 0;
}