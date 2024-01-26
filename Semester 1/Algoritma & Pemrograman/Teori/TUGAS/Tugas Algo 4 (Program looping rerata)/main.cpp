#include <iostream>
#include <fstream>

using namespace std;

int main() {

	// deklarasi file input
	ifstream input("input.txt");
	
	// deklarasi file output
	ofstream output;
	output.open("output.txt"); // membuka file output.txt untuk diedit

	// deklarasi variabel 
	int i = 0, n = 0; // "i" sebagai banyak baris & "n" sebagai banyak data
	double total = 0; // variabel untuk menyimpan hasil akhir
	string str; // variabel untuk menampung teks per baris di file input.txt

	// mengeluarkan judul di file output.txt
	output << "================ PROGRAM PENGHITUNG RATA-RATA ================" << endl;
	
	// membaca baris diulang sesuai banyak baris di file input.txt
	while (getline(input,str)) { // isi teks di baris n dimasukkan ke var str
		++i; // i ditambah 1 setiap perulangan

		// apabila i adalah bilangan ganjil
		if (i % 2 == 1) {
			// mengeluarkan label data di output.txt
			output << n + 1 << ". " << str << " : ";
		} 
		// apabila i bukan bilangan ganjil
		else {
			n++; // n ditambah 1 setiap baris genap
			total = total + stod(str); // total ditambah isi str yg dikonversi ke double
			output << str << endl; // mengeluarkan isi baris di output.txt
		}
	}

	// menutup file input setelah selesai dibaca
	input.close();

	// mengeluarkan footer di file output.txt
	output << "==============================================================" << endl;
	
	// mencari rata-rata menggunakan rumus
	
	double rata = total / n;
	// mengeluarkan n dan total di file output.txt
	output << "Jumlah Data : " << n << endl;
	output << "Rata-rata : " << rata << endl;
	
	// menutup file output.txt
	output.close();

	// menutup program
	return 0;
}