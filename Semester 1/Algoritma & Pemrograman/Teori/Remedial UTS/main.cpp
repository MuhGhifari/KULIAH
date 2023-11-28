#include <iostream>
#include <fstream>

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
    output << "Data ke-" << i << ": " << str << endl;
  }

  output << endl;
  output << "nilai min = " << *min_element(v.begin(), v.end()) << endl;
  output << "nilai maks = " << *max_element(v.begin(), v.end()) << endl;
  output.close();
  input.close();
  return 0;
}