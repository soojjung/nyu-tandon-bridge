#include <iostream>
#include <vector>
using namespace std;

int minInArray(int arr[], int arrSize) {
  int minVal = arr[0];
  for (int i = 1; i < arrSize; ++i) {
    if (arr[i] < minVal) {
      minVal = arr[i];
    }
  }
  return minVal;
}

vector<int> findIndices(int arr[], int arrSize, int value) {
  vector<int> indices;
  for (int i = 0; i < arrSize; ++i) {
    if (arr[i] == value) {
      indices.push_back(i);
    }
  }
  return indices;
}

int main() {
  const int SIZE = 20;
  int arr[SIZE];

  cout << "Please enter 20 integers separated by a space:\n";
  for (int i = 0; i < SIZE; ++i) {
    cin >> arr[i];
  }

  int minValue = minInArray(arr, SIZE);
  vector<int> indices = findIndices(arr, SIZE, minValue);

  cout << "The minimum value is " << minValue
       << ", and it is located in the following indices: ";
  for (size_t i = 0; i < indices.size(); ++i) {
    cout << indices[i];
    if (i + 1 < indices.size())
      cout << " ";
  }
  cout << endl;

  return 0;
}
