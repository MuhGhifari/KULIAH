#include <iostream>

using namespace std;

int main() {
  string nama, jurusan, universitas, hobby;
  int umur, semester;

  cout << "Masukkan nama : "; getline(cin, nama);
  cout << "Masukkan jurusan : "; getline(cin, jurusan);
  cout << "Masukkan universitas : "; getline(cin, universitas);
  cout << "Masukkan semester : "; cin >> semester;
  cout << "Masukkan hobby : "; cin >> hobby;
  cout << "Masukkan umur : "; cin >> umur;

  cout << "-------------------------------------\n";
  cout << "Nama         : " << nama << endl;
  cout << "Jurusan      : " << jurusan << endl;
  cout << "Universitas  : " << universitas << endl;
  cout << "Semester     : " << semester << endl;
  cout << "Hobby        : " << hobby << endl;
  cout << "Umur         : " << umur << endl;
  return 0;
}