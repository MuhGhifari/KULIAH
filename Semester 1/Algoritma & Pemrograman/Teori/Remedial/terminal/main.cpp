#include <iostream>

using namespace std;

int main()
{
  int arr[] = {23,1,5,903,29,382,23,53,123,283,321,232,234,432,664};

  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Array: ";
  for (int i = 0; i < n; i++) {
    cout << i << ". " << arr[i] << " " << endl;
  }
  cout << endl;
  cout << "nilai min = " << *min_element(arr, arr + n) << endl;

  cout << "nilai maks = " << *max_element(arr, arr + n) << endl;
  return 0;
}