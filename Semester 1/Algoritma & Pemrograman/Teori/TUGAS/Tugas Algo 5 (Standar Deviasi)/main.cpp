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
  int i = 0, n = 0;
  double total, rata, standarDeviasi;

  output << "=================== PROGRAM STANDAR DEVIASI ===================" << endl;
  while(getline(input, str)) {
    i++;
    double temp;
    size_t idx;

    if (i % 2 == 1) {
      output << n + 1 << ". " << str << " : ";
    } else {
      try {
        temp = stod(str, &idx);
        if (idx != str.length()) {
          cerr << "[WARNING] : input.txt di baris " << i << ", gagal mengkonversi ke angka. Baris dilewat!" << endl;
        } else {
          n++;
          int x = stod(str);
          data.push_back(x);
          output << str << endl;
          total = total + x;
        }
      }
      catch(const exception& e) {
        cerr << "[WARNING] : input.txt di baris " << i << ", gagal mengkonversi ke angka. Baris dilewat!" << endl;
      }
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

  string hasil;

  if (standarDeviasi > 0 && standarDeviasi < 10) {
    hasil = "Standar deviasi tidak beda jauh";
  } else if (standarDeviasi < rata) {
    hasil = "Standar deviasi sedikit jauh";
  } else {
    hasil = "Standar deviasi berbeda jauh";
  }

  output << "Hasil\t\t\t\t\t\t: " << hasil << endl;

  output.close();
  
  return 0;
}