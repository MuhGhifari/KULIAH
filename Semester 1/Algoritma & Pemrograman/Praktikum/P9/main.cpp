#include <iostream>

using namespace std;

int main() {
  // membuat array kosong
  // int array[3] = {73, 38, 56}; // variabel array dengan ukuran 3

  // array[0] = 73; // index ke 0
  // array[1] = 38; // index ke 1
  // array[2] = 56; // index ke 2
  // cout << "1 : " << sizeof(array) << endl;
  // cout << "2 : " << sizeof("12") << endl;
  // for (int i = 0; i < (sizeof(array)/sizeof(array[0])); i++) {
  //   cout << array[i] << endl;
  // }
  
  // cout << array[1] << endl;
  // cout << array[2] << endl;

  int matriks[3][3];

  cout << "PORGRAM INPUT DATA MATRIKS 3x3" << endl;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << "Input baris " << i + 1 << ", kolom " << j + 1 << " = ";
      cin >> matriks[i][j];
    }
  }

  cout << "\n==============================================\n" << endl;

  cout << "Hasil : " << endl;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << matriks[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}