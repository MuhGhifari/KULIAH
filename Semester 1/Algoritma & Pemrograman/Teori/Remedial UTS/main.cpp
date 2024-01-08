#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
  ifstream input ("input.txt");
  ofstream output;
  output.open("output.txt");
  string str;
  int i = 0;
  vector<int> v;
  
  while (getline(input, str)) {
    ++i;
    v.push_back(stoi(str));
    output << "Data ke-" << i << "\t: " << str << endl;
  }
  input.close();

  output << endl;
  output << "nilai min\t\t: " << *min_element(v.begin(), v.end()) << endl;
  output << "nilai maks\t: " << *max_element(v.begin(), v.end()) << endl;
  output.close();
  return 0;
}