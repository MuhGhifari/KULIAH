#include <iostream>

using namespace std;

int main() {
	int n;

	cout << "Masukkan Jumlah Bilangan : ";
	cin >> n;
	cout << endl;

	float total = 0.0;
	for (int i = 1; i <= n; i++) {
		float bilangan;
		cout << "Masukkan bilangan ke-" << i << " : ";
		cin >> bilangan;
		total = total + bilangan;
	}

	total = total / n;
	cout << "\nHasil rata-rata dari bilangan-bilangan tersebut adalah : " << total << endl;
	return 0;
}