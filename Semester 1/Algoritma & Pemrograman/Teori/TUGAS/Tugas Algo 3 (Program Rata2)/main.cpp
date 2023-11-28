#include <iostream>
#include <fstream>

using namespace std;

int main () {
	char str[1];
	double x1, x2, x3, x4, x5, hasil;

	ifstream file_input ("input.txt");

	if(!file_input) {
		cout << "INPUT FILE TIDAK BISA DIBUKA, ERROR, PROGRAM DIHENTIKAN!" << endl;
		exit(-1);
	} else {
		file_input.getline(str, 9, '\n');
		file_input.getline(str, 9, '\n');
		x1 = atof(str);
		file_input.getline(str, 9, '\n');
		file_input.getline(str, 9, '\n');
		x2 = atof(str);
		file_input.getline(str, 9, '\n');
		file_input.getline(str, 9, '\n');
		x3 = atof(str);
		file_input.getline(str, 9, '\n');
		file_input.getline(str, 9, '\n');
		x4 = atof(str);
		file_input.getline(str, 9, '\n');
		file_input.getline(str, 9, '\n');
		x5 = atof(str);
	}

	hasil = (x1 + x2 + x3 + x4 + x5) / 5;

	ofstream file_output;
	file_output.open("output.txt");

	if(!file_output) {
		cout << "OUTPUT FILE TIDAK BISA DIBUKA, ERROR, PROGRAM DIHENTIKAN" << endl;
		exit(-1);
	} else {
		file_output << "Program selesai dieksekusi" << endl;
		file_output << "Hasil Eksekusi Program adalah sebagai berikut : " << endl;
		file_output << "-------------------------------------------------" << endl;
		file_output << endl;

		// file_output << "Bilangan : " << x1 << ", " << x2 << ", " << x3 << ", " << x4 << ", " << x5 << endl;
		file_output << "Data 1 : " << x1 << endl;
		file_output << "Data 2 : " << x2 << endl;
		file_output << "Data 3 : " << x3 << endl;
		file_output << "Data 4 : " << x4 << endl;
		file_output << "Data 5 : " << x5 << endl;
		file_output << "Rata-rata dari bilangan tersebut adalah : " << hasil <<endl;
	}

	file_input.close();
	file_output.close();

	cout << "Program selesai dieksekusi";
	cout << endl;
	cout << "Silahkan hasilnya dilihat pada 'OUTPUT FILE'";
	cout << endl;
}