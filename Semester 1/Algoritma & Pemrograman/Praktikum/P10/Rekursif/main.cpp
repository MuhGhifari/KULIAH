#include <iostream>

using namespace std;

// Rekursif
void barisBilangan(int angka) {
  if (angka > 0) {
    barisBilangan(angka - 1);
    cout << angka << " ";
  } else {
    cout << 0 << " ";
  }
}

int main() {
  barisBilangan(15);

  cout << endl;

  return 0;
}