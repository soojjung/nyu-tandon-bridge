#include <iostream>
#include <string>
using namespace std;

int sumOfSquares(int arr[], int arrSize) {
  if (arrSize == 0) {
    return 0;
  }

  int last = arr[arrSize - 1];
  return (last * last) + sumOfSquares(arr, arrSize - 1);
}

bool isSorted(int arr[], int arrSize) {
  if (arrSize <= 1) {
    return true;
  }

  if (arr[arrSize - 2] > arr[arrSize - 1]) {
    return false;
  }

  return isSorted(arr, arrSize - 1);
}

int main() {
  int arrSize;

  cout << "Please enter the number of elements: ";
  cin >> arrSize;

  int arr[arrSize];

  cout << "Please enter integers: \n";
  for (int i = 0; i < arrSize; i++) {
    cin >> arr[i];
  }

  cout << "Sum of squares: " << sumOfSquares(arr, arrSize) << endl;
  cout << "Is sorted ? " << (isSorted(arr, arrSize) ? "true" : "false") << endl;

  return 0;
}