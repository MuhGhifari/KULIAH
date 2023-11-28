#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream input("input.txt");
	ofstream output;
	output.open("output.txt");
	int n = 0;
	string str;
	double total = 0;

	output << "================ PROGRAM PENGHITUNG RATA-RATA ================" << endl;
	output << "Bilangan : [ ";
	while (getline(input,str)) {
		++n;
		total = total + stod(str);
		if (n == 1) {
			output << str;
		} else {
			output << ", " << str;
		}
	}
	output << " ]" << endl;
	output << "==============================================================" << endl;
	total = total / n;
	output << "Maka rata-rata dari bilangan-bilangan tersebut adalah : " << total << endl;
	output.close();
	input.close();
	return 0;
}