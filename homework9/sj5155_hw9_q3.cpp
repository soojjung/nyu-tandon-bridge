#include <iostream>
using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {
  outPosArrSize = 0;

  for (int i = 0; i < arrSize; ++i)
    if (arr[i] > 0)
      ++outPosArrSize;

  int* result = new int[outPosArrSize];
  int idx = 0;
  for (int i = 0; i < arrSize; ++i)
    if (arr[i] > 0)
      result[idx++] = arr[i];
  return result;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr) {
  *outPosArrSizePtr = 0;
  for (int i = 0; i < arrSize; ++i)
    if (arr[i] > 0)
      ++(*outPosArrSizePtr);
  int* result = new int[*outPosArrSizePtr];
  int idx = 0;
  for (int i = 0; i < arrSize; ++i)
    if (arr[i] > 0)
      result[idx++] = arr[i];
  return result;
}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {
  outPosArrSize = 0;
  for (int i = 0; i < arrSize; ++i)
    if (arr[i] > 0)
      ++outPosArrSize;
  outPosArr = new int[outPosArrSize];
  int idx = 0;
  for (int i = 0; i < arrSize; ++i)
    if (arr[i] > 0)
      outPosArr[idx++] = arr[i];
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr,
                 int* outPosArrSizePtr) {
  *outPosArrSizePtr = 0;
  for (int i = 0; i < arrSize; ++i)
    if (arr[i] > 0)
      ++(*outPosArrSizePtr);
  *outPosArrPtr = new int[*outPosArrSizePtr];
  int idx = 0;
  for (int i = 0; i < arrSize; ++i)
    if (arr[i] > 0)
      (*outPosArrPtr)[idx++] = arr[i];
}

int main() {
  int arr[] = {3, -1, -3, 0, 6, 4};
  int n = sizeof(arr) / sizeof(arr[0]);

  int size1;
  int* pos1 = getPosNums1(arr, n, size1);
  cout << "getPosNums1 (" << size1 << " elements): ";
  for (int i = 0; i < size1; ++i) cout << pos1[i] << ' ';
  cout << endl;
  delete[] pos1;

  int size2;
  int* pos2 = getPosNums2(arr, n, &size2);
  cout << "getPosNums2 (" << size2 << " elements): ";
  for (int i = 0; i < size2; ++i) cout << pos2[i] << ' ';
  cout << endl;
  delete[] pos2;

  int* pos3;
  int size3;
  getPosNums3(arr, n, pos3, size3);
  cout << "getPosNums3 (" << size3 << " elements): ";
  for (int i = 0; i < size3; ++i) cout << pos3[i] << ' ';
  cout << endl;
  delete[] pos3;

  int* pos4;
  int size4;
  getPosNums4(arr, n, &pos4, &size4);
  cout << "getPosNums4 (" << size4 << " elements): ";
  for (int i = 0; i < size4; ++i) cout << pos4[i] << ' ';
  cout << endl;
  delete[] pos4;

  return 0;
}
