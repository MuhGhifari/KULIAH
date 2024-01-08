#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct DataMahasisa {
	string nama;
	string npm;
	unsigned int nilai;
};

int main() {
	ifstream input("input.txt");
	ofstream output;
	output.open("output.txt");
	  
	if(!input) {
		cout << "FILE INPUT TIDAK TERDETEKSI!!" << endl;
		exit(1);
	}

	int i = 0, n = 0;
	double total = 0;
	string str;

	output << "                         LAPORAN NILAI                        " << endl;
	output << "                    MAHASISWA ILMU KOMPUTER                   " << endl;
	output << "                    			KELAS A & B 			                   " << endl;
	output << "--------------------------------------------------------------" << endl;
	output << "|" << setw(6) << left << "  No";
	output << "|" << setw(28) << left << "       Nama Mahasiswa";
	output << "|" << setw(14) << left << "     NPM";
	output << "|" << setw(10) << left << "   Nilai";
	output << "|" << endl;
	output << "|-------------------------------------------------------------|" << endl;
	while (getline(input,str)) {
		++i;
		if (i % 2 == 1) {
			output << "|" << setw(6) << left << "  " + to_string(n + 1);
			output << "|" << setw(28) << left << " " + str;
			output << "|" << setw(14) << left << " "; 
		} else {
			n++; 
			total = total + stod(str); 
			output << "|" << setw(10) << left <<"    " + str;
			output << "|" << endl; 
		}
	}
	input.close();
	output << "---------------------------------------------------------------" << endl;
	total = total / n;
	output << "Jumlah Data\t: " << n << endl;
	output << "Rata-rata\t\t: " << total << endl;
	output.close();
	
	return 0;
}