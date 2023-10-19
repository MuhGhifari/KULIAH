#include <iostream>

using namespace std;

int main(){
  int a,b;
  cout << "Masukkan Angka A : "; cin >> a;
  cout << "Masukkan angka B : "; cin >> b;

  // operator aritmatika
  cout << "======= Hasil =======" << endl;
  cout << "Perkalian (*)    : " << a * b << endl;
  cout << "Pembagian (/)    : " << a / b << endl;
  cout << "Penjumlahan (+)  : " << a + b << endl;
  cout << "Pengurangan (-)  : " << a - b << endl;
  cout << "Modulo (%)       : " << a % b << endl;

  int c = 10; // operator assignment
  cout << endl;
  cout << "c = " << c << endl;

  // operator increment
  cout << "pre increment a  = " << ++a << endl;
  cout << "post increment b = " << b++ << endl;
  
  // operator decrement
  cout << "pre decrement a  = " << --a << endl;
  cout << "post decrement b = " << b-- << endl;

  // operator and
  cout << endl;
  int d;
  d = 0 && 1;
  cout << "hasil operator and : " << d << endl;
  d = 1 && 1;
  cout << "hasil operator and : " << d << endl;
  d = 0 && 0;
  cout << "Hasil operator and : " << d << endl;

  // operator or
  cout << endl;
  d = 0 || 1;
  cout << "hasil operator or : " << d << endl;
  d = 1 || 1;
  cout << "hasil operator or : " << d << endl;
  d = 0 || 0;
  cout << "Hasil operator or : " << d << endl;

  // operator not
  cout << endl;
  d = !1;
  cout << "hasil operator not : " << d << endl;
  d = !0;
  cout << "hasil operator not : " << d << endl;

  return 0;
}