// Nama   : Muhammad Ghifari
// NPM    : 065123020
// Kelas  : A (Semester 1)

#include <iostream>

using namespace std;

int main (){
  string nama;
  int semester;
  char kelas;
  float ipk;

  cout << "----------- FORMULIR BIODATA -----------";
  cout << "\nNama     : "; getline(cin, nama);
  cout << "Semester : "; cin >> semester;
  cout << "Kelas    : "; cin >> kelas;
  cout << "IPK      : "; cin >> ipk;
  cout << endl;
  cout << "----------- BIOATA -----------";
  cout << "\nNama     : " << nama;
  cout << "\nSemester : " << semester;
  cout << "\nKelas    : " << kelas;
  cout << "\nIPK      : " << ipk << endl;

  return 0;
}