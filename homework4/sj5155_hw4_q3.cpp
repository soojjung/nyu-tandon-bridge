#include <iostream>
using namespace std;

void printBinary(int n) {
  if (n > 1) {
    printBinary(n / 2);
  }
  cout << (n % 2);
}

int main() {
  int n;
  cout << "Enter decimal number:" << endl;
  cin >> n;

  cout << "The binary representation of " << n << " is ";
  printBinary(n);
  cout << endl;

  return 0;
}
