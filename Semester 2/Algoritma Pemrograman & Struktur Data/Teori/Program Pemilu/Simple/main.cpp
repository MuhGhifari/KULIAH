#include <iostream>
#include <fstream>
#include <random>
#include <iomanip>
#include <sstream>

using namespace std;

void printTabel(const vector<vector<string>>& tabel, ofstream& output);

int main() {
  ifstream fileInput("input.txt");
  ofstream fileOutput;
  fileOutput.open("output.txt");

  if(!fileInput) {
		cerr << "[\x1b[31mERROR\x1b[0m] : file 'input.csv' tidak terdeteksi!" << endl;
		exit(1);
	}

  string str;
  int totalSuara = 0, suaraPaslon01 = 0, suaraPaslon02 = 0, suaraPaslon03 = 0;

  while (getline(fileInput, str)) {
    if (totalSuara >= 300) {
      break;
    }

    if (str == "01") {
      suaraPaslon01++;
      cout << suaraPaslon01 << endl;
    } else if (str == "02") {
      suaraPaslon02++;
    } else if (str == "03") {
      suaraPaslon03++;
    }
  }
  fileInput.close();

  random_device acak;
  mt19937 gen(acak());
  uniform_int_distribution<int> distribution(60, 100);
  int suaraTambahan = distribution(gen);

  suaraPaslon02 += suaraTambahan;

  fileOutput << "--------------------------------------------------" << endl;
  fileOutput << "Paslon 01 : " << suaraPaslon01 << " Suara" << endl;
  fileOutput << "Paslon 02 : " << suaraPaslon02 << " Suara" << endl;
  fileOutput << "Paslon 03 : " << suaraPaslon03 << " Suara" << endl;
  fileOutput << "--------------------------------------------------";
  fileOutput.close();
  
  return 0;
}