#include <iostream>
#include <string>
using namespace std;

int main() {
  int original;
  cout << "Enter decimal number:" << endl;
  cin >> original;

  int n = original;
  string roman;

  while (n >= 1000) {
    roman += 'M';
    n -= 1000;
  }

  if (n >= 500) {
    roman += 'D';
    n -= 500;
  }

  int count = n / 100;
  for (int i = 0; i < count; ++i) {
    roman += 'C';
  }
  n %= 100;

  if (n >= 50) {
    roman += 'L';
    n -= 50;
  }

  count = n / 10;
  for (int i = 0; i < count; ++i) {
    roman += 'X';
  }
  n %= 10;

  if (n >= 5) {
    roman += 'V';
    n -= 5;
  }

  count = n;
  for (int i = 0; i < count; ++i) {
    roman += 'I';
  }

  cout << original << " is " << roman << endl;
  return 0;
}
