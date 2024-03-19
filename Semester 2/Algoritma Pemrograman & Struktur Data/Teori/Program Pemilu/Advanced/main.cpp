#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <random>
#include <string>
#include <vector>
#include <map>

using namespace std;

string buatPersentase(int pembilang, int penyebut, size_t digitDesimal);

void printTabel(vector<vector<string>>& tabel, ofstream& output);

int main() {
  ifstream fileInput("input.csv");
  ofstream fileOutput;
  fileOutput.open("output.txt");

  if(!fileInput) {
		cerr << "[\x1b[31mERROR\x1b[0m] : file 'input.csv' tidak terdeteksi!" << endl;
		exit(1);
	}

  map<string, int> totalSuaraKandidat, totalSuaraTPS;
  map<string, map<string, int>> suaraTPS;
  vector<string> headerTabel = {"Kode TPS", "Suara TPS"};
  vector<vector<string>> tabelHasil;
  string str;
  int totalSuara;

  while (getline(fileInput,str)) {
    vector<string> input;
    stringstream ss(str);
    string v;

    while (getline(ss, v, ',')) {
      input.push_back(v);
    }

    if (input.size() > 2) {
      continue;
    }
    
    totalSuaraTPS[input[0]]++;
    suaraTPS[input[0]][input[1]]++;
    totalSuaraKandidat[input[1]]++;
    totalSuara++;
  }
  fileInput.close();

  for (auto& tps : suaraTPS) {
    if (totalSuaraTPS[tps.first] >= 300) {
      continue;
    }

    random_device acak;
    mt19937 gen(acak());
    uniform_int_distribution<int> distribusi(60, 300 - totalSuaraTPS[tps.first]);
    int suaraTambahan = distribusi(gen);
    cout << "Suara Tambahan " << tps.first << " : " << suaraTambahan << endl;

    tps.second["02"] += suaraTambahan;
    totalSuaraTPS[tps.first] += suaraTambahan;
    totalSuaraKandidat["02"] += suaraTambahan;
    totalSuara += suaraTambahan;
  }

  for (auto& kandidat : totalSuaraKandidat) {
    headerTabel.push_back(kandidat.first);
  }
  tabelHasil.push_back(headerTabel);
  
  for (auto& tps : suaraTPS) {
    vector<string> barisTPS;
    vector<string> suaraKandidatTPS;
    barisTPS.push_back(tps.first);

    if (tps.second.size() != totalSuaraKandidat.size()) {
      for (auto& kandidat : totalSuaraKandidat) {
        if (tps.second.find(kandidat.first) == tps.second.end()) {
          tps.second[kandidat.first] = 0;
        }
      }
    }

    for (auto& kandidatTPS : tps.second) {
      string persentaseSuaraKandidat = buatPersentase(kandidatTPS.second, totalSuaraTPS[tps.first], 1);
      suaraKandidatTPS.push_back(persentaseSuaraKandidat);
    }
    barisTPS.push_back(to_string(totalSuaraTPS[tps.first]));

    for (auto& suara : suaraKandidatTPS) {
      barisTPS.push_back(suara);
    }

    tabelHasil.push_back(barisTPS);
  }

  vector<string> suaraAkhir = {"", "Total Suara"};

  for (auto& kandidat : totalSuaraKandidat) {
    string persentaseSuaraKandidat = buatPersentase(kandidat.second, totalSuara, 1);
    suaraAkhir.push_back(persentaseSuaraKandidat);
  }

  tabelHasil.push_back(suaraAkhir);
  printTabel(tabelHasil, fileOutput);

  return 0;
}

string buatPersentase(int pembilang, int penyebut, size_t digitDesimal) {
  ostringstream persentase;
  float persen;
  
  persen = (static_cast<float>(pembilang) / penyebut) * 100;
  persentase << fixed << setprecision(digitDesimal) << persen << "%";
  return persentase.str();
}

void printTabel(vector<vector<string>>& tabel, ofstream& output) {
  vector<size_t> lebarKolom(tabel[0].size(), 0);
  for (auto& baris : tabel) {
    for (size_t i = 0; i < baris.size(); ++i) {
      lebarKolom[i] = max(lebarKolom[i], baris[i].size());
    }
  }

  for (size_t i = 0; i < lebarKolom.size(); ++i) {
    output << "+" << string(lebarKolom[i] + 2, '-');
  }
  output << "+" << endl;

  auto indeksTabel = tabel.begin();
  for (auto& baris : tabel) {
    while (baris.size() < lebarKolom.size()) {
      baris.push_back("");
    }

    for (size_t i = 0; i < baris.size(); ++i) {
      output << "| " << setw(lebarKolom[i] + 1) << left << baris[i];
    }
    output << "|" << endl;

    if (indeksTabel == tabel.begin() || indeksTabel == tabel.end() - 2) {
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