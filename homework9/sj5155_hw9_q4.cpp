#include <iostream>
using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize) {
  int* buf = new int[arrSize];
  int writePos = 0;

  for (int i = 0; i < arrSize; ++i)
    if (arr[i] % 2 != 0)
      buf[writePos++] = arr[i];

  for (int i = arrSize - 1; i >= 0; --i)
    if (arr[i] % 2 == 0)
      buf[writePos++] = arr[i];

  for (int i = 0; i < arrSize; ++i) arr[i] = buf[i];

  delete[] buf;
}

int main() {
  int n;
  cout << "Please enter the array size: ";
  cin >> n;

  int* arr = new int[n];
  cout << "Please enter " << n << " integers:" << endl;
  for (int i = 0; i < n; ++i) {
    cout << "arr[" << i << "] = ";
    cin >> arr[i];
  }

  cout << "\nBefore: ";
  for (int i = 0; i < n; ++i) cout << arr[i] << ' ';
  cout << "\n";

  oddsKeepEvensFlip(arr, n);

  cout << "After:  ";
  for (int i = 0; i < n; ++i) cout << arr[i] << ' ';
  cout << "\n";

  delete[] arr;
  return 0;
}
