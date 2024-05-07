#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

struct NilaiMahasiswa {
  string nama;
  char npm[9];
  int nilaiAbsen;
  int nilaiTugas;
  int nilaiPraktikum;
  int nilaiUTS;
  int nilaiUAS;
};

void printTabel(const vector<vector<string>>& tabel, ofstream& output);

int main() {
  ifstream input("input.csv");

  int i = 0, n = 0;
  float total = 0, rata;
  string str;

  vector<string> header;
  vector<vector<string>> tabelHasil;

  while (getline(input, str)) {
    ++i;
    vector<string> baris;
    stringstream ss(str);
    string value;

    while (getline(ss, value, ';')) {
      baris.push_back(value);
    }

    if (i == 1) {
      header.push_back("No");
      for (auto& kolom : baris) {
        header.push_back(kolom);
      }
      tabelHasil.push_back(header);
      continue;
    }

    NilaiMahasiswa nilaiMahasiswa;
    size_t npmLen = sizeof(nilaiMahasiswa.npm)/sizeof(char);

    nilaiMahasiswa.nama = baris[0];
    strncpy(nilaiMahasiswa.npm, baris[1].c_str(), npmLen);
    nilaiMahasiswa.nilaiAbsen = stoi(baris[2]);
    nilaiMahasiswa.nilaiTugas = stoi(baris[3]);
    nilaiMahasiswa.nilaiPraktikum = stoi(baris[4]);
    nilaiMahasiswa.nilaiUTS = stoi(baris[5]);
    nilaiMahasiswa.nilaiUAS = stoi(baris[6]);

    vector<string> barisNilaiMahasiswa;

    char huruf;
    int nilaiAkhir = (0.1 * nilaiMahasiswa.nilaiAbsen) + (0.3 * nilaiMahasiswa.nilaiTugas) + (0.1 * nilaiMahasiswa.nilaiPraktikum) + (0.2 * nilaiMahasiswa.nilaiUTS) + (0.3 * nilaiMahasiswa.nilaiUAS);

    if (nilaiAkhir < 40) {
      huruf = 'E';
    } else if (nilaiAkhir <= 55) {
      huruf = 'D';
    } else if (nilaiAkhir <= 66) {
      huruf = 'C';
    } else if (nilaiAkhir <= 74) {
      huruf = 'B';
    } else if (nilaiAkhir <= 100) {
      huruf = 'A';
    }

    barisNilaiMahasiswa.push_back(to_string(i - 1));
    barisNilaiMahasiswa.push_back(baris[0]);
    barisNilaiMahasiswa.push_back(baris[1]);
    barisNilaiMahasiswa.push_back(baris[2]);
    barisNilaiMahasiswa.push_back(baris[3]);
    barisNilaiMahasiswa.push_back(baris[4]);
    barisNilaiMahasiswa.push_back(baris[5]);
    barisNilaiMahasiswa.push_back(baris[6]);
    barisNilaiMahasiswa.push_back(to_string(nilaiAkhir));
    string temp(1, huruf);
    barisNilaiMahasiswa.push_back(temp);

    tabelHasil.push_back(barisNilaiMahasiswa);
  }

  ofstream fileOutput;
  fileOutput.open("output.txt");

  printTabel(tabelHasil, fileOutput);
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