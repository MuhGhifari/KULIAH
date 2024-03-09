#include <iostream>
#include <fstream>
#include <sstream> 
#include <iomanip> 
#include <random>
#include <string>
#include <vector>
#include <map>

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
  vector<vector<string>> tabelHasil;
  vector<string> kandidat = {"01", "02", "03"};
  map<string, int> suaraKandidat;
  int totalSuara = 0;
  while (getline(fileInput, str)) {
    if (totalSuara >= 300) {
      break;
    }
    suaraKandidat[str]++;
    totalSuara++;
  }

  vector<string> suara, persentaseSuara;
  for (auto paslon : kandidat) {
    ostringstream persentase;
    float persen;
    int jumlahSuara = suaraKandidat[paslon];

    if (paslon == "02") {
      random_device random;
      mt19937 gen(random());
      uniform_int_distribution<int> distribution(50, 100);
      int suaraTambahan = distribution(gen);

      cout << "Suara Tambahan : " << suaraTambahan << endl;
      jumlahSuara += suaraTambahan;
      totalSuara += suaraTambahan;
    }

    persen = (static_cast<float>(jumlahSuara) / totalSuara) * 100;

    persentase << fixed << setprecision(1) << persen << "%";
    persentaseSuara.push_back(persentase.str());

    str = to_string(jumlahSuara) + " suara";
    suara.push_back(str);
  }
  tabelHasil.push_back(kandidat);
  tabelHasil.push_back(suara);
  tabelHasil.push_back(persentaseSuara);

  printTabel(tabelHasil, fileOutput);

  return 0;
}

void printTabel(const vector<vector<string>>& tabel, ofstream& output) {
  vector<size_t> lebarKolom(tabel[0].size(), 0);
  for (const auto& baris : tabel) {
    for (size_t i = 0; i < baris.size(); ++i) {
      lebarKolom[i] = max(lebarKolom[i], baris[i].size());
    }
  }

  for (size_t i = 0; i < lebarKolom.size(); ++i) {
    output << "+" << string(lebarKolom[i] + 2, '-');
  }
  output << "+" << endl;

  auto indeksTabel = tabel.begin();
  for (const auto& baris : tabel) {
    for (size_t i = 0; i < baris.size(); ++i) {
      output << "| " << setw(lebarKolom[i] + 1) << left << baris[i];
    }
    output << "|" << endl;
    if (indeksTabel == tabel.begin()) {
      for (size_t i = 0; i < lebarKolom.size(); ++i) {
        output << "+" << string(lebarKolom[i] + 2, '-');
      }
      output << "+" << endl;
    }
    indeksTabel++;
  }

  for (size_t i = 0; i < lebarKolom.size(); ++i) {
    output << "+"<< string(lebarKolom[i] + 2, '-');
  }
  output << "+";
}