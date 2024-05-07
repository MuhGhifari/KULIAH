#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

void printTabel(const vector<vector<string>>& tabel, ofstream& output);
int main() {
  fstream input("input.csv");
  vector<vector<string>> tabelHasil;
  string str;
  while (getline(input, str)) {
    vector<string> baris;
    stringstream ss(str);
    string value;

    while (getline(ss, value, ';')) {
      baris.push_back(value);
    }

    tabelHasil.push_back(baris);
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