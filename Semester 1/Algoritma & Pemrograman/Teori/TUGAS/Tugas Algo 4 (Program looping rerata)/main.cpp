#include <iostream>
#include <fstream>

using namespace std;

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

	output << "================ PROGRAM PENGHITUNG RATA-RATA ================" << endl;
	while (getline(input,str)) {
		++i;
		if (i % 2 == 1) {
			output << n + 1 << ". " << str << " : ";
		} else {
			n++; 
			total = total + stod(str); 
			output << str << endl; 
		}
	}
	input.close();
	output << "==============================================================" << endl;
	total = total / n;
	output << "Jumlah Data : " << n << endl;
	output << "Rata-rata : " << total << endl;
	output.close();
	return 0;
}