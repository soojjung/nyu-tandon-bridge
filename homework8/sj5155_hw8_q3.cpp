#include <iostream>
using namespace std;

void reverseArray(int arr[], int arrSize) {
  int i = 0, j = arrSize - 1;
  while (i < j) {
    int tmp = arr[i];
    arr[i++] = arr[j];
    arr[j--] = tmp;
  }
}

void removeOdd(int arr[], int& arrSize) {
  int write = 0;
  for (int read = 0; read < arrSize; ++read) {
    if (arr[read] % 2 == 0) {
      arr[write++] = arr[read];
    }
  }
  arrSize = write;
}

void splitParity(int arr[], int arrSize) {
  int left = 0, right = arrSize - 1;
  while (left < right) {
    while (left < right && arr[left] % 2 != 0) {
      ++left;
    }

    while (left < right && arr[right] % 2 == 0) {
      --right;
    }
    if (left < right) {
      int tmp = arr[left];
      arr[left++] = arr[right];
      arr[right--] = tmp;
    }
  }
}

void printArray(int arr[], int arrSize) {
  for (int i = 0; i < arrSize; ++i) {
    cout << arr[i] << ' ';
  }
  cout << '\n';
}

int main() {
  int arr1[10] = {9, 2, 14, 12, -3};
  int size1 = 5;
  reverseArray(arr1, size1);
  cout << "reverseArray: ";
  printArray(arr1, size1);

  int arr2[10] = {21, 12, 6, 7, 14};
  int size2 = 5;
  removeOdd(arr2, size2);
  cout << "removeOdd:   ";
  printArray(arr2, size2);

  int arr3[10] = {3, 6, 4, 1, 12};
  int size3 = 5;
  splitParity(arr3, size3);
  cout << "splitParity:";
  printArray(arr3, size3);

  return 0;
}
