// Nama   : Muhammad Ghifari
// NPM    : 065123020
// Kelas  : A (Semester 1)

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  const float v_float = 3.141592653589793;
  const double v_double = 3.141592653589793;
  int v_int = numeric_limits<int>::max();
  long v_long = numeric_limits<long>::max();
  char v_char = 'A';
  cout << setprecision(16);
  cout << "------------ PENGENALAN ------------\n";
  cout << "\nPi dalam tipe data float adalah " <<  v_float;
  cout << "\nPi dalam tipe data double adalah " <<  v_double;
  cout << "\nNilai maksimum tipe data int adalah " << v_int;
  cout << "\nNilai maksimum tipe data long adalah " << v_long;
  cout << "\nContoh tipe data char adalah : " << v_char << endl;
  return 0;
}