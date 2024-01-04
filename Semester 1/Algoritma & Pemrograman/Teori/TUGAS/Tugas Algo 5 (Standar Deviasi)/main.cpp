#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  ifstream input("input.txt");
  if (!input){
    cerr << "[ERROR] : File input.txt tidak ditemukan!" << endl;
    exit(1);
  }

  ofstream output;
  output.open("output.txt");

  vector<double> data;
  string str;
  int i = 0;
  double total, rata, standarDeviasi;

  output << "=================== PROGRAM STANDAR DEVIASI ===================" << endl;
  while(getline(input, str)) {
    double temp;
    size_t idx;

    try {
      temp = stod(str, &idx);
      if (idx != str.length()) {
        cerr << "[WARNING] : input.txt di baris " << i + 1 << ", gagal mengkonversi ke angka. Baris dilewat!" << endl;
      } else {
        data.push_back(stod(str));
        output << "Data ke-" << i + 1 << " : " << data[i] << endl;
        total = total + data[i];
        i++;
      }
    }
    catch(const exception& e) {
      cerr << "[WARNING] : input.txt di baris " << i + 1 << ", gagal mengkonversi ke angka. Baris dilewat!" << endl;
    }
  }
  input.close();
  output << "===============================================================" << endl;

  rata = total / data.size();
  double sigma, x;
  
  for (int i = 0; i < data.size(); i++) {
    x = pow(data[i] - rata, 2);
    sigma += x;
  }
  sigma = sigma / data.size();
  standarDeviasi = sqrt(sigma);
  
  output << "Rata-rata\t\t\t\t: " << rata << endl;
  output << "Standar Deviasi\t: " << standarDeviasi << endl;
  output.close();
  
  return 0;
}