#include <iostream>

using namespace std;

int main() {
	int n, i = 1;
	float total = 0.0;

	cout << "Masukkan Jumlah Bilangan : ";
	cin >> n;
	cout << endl;

	while (i <= n) {
		float bilangan;
		cout << "Masukkan bilangan ke-" << i << " : ";
		cin >> bilangan;
		total = total + bilangan;
		i++;
	}

	total = total / n;
	cout << "\nHasil rata-rata dari bilangan-bilangan tersebut adalah : " << total << endl;
	return 0;
}