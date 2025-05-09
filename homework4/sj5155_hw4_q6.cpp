#include <iostream>
using namespace std;

int main() {
  int n;
  cout << "Please enter a positive integer: ";
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    int temp = i;
    int evenCount = 0;
    int oddCount = 0;

    while (temp > 0) {
      int digit = temp % 10;
      if (digit % 2 == 0)
        ++evenCount;
      else
        ++oddCount;
      temp /= 10;
    }

    if (evenCount > oddCount) {
      cout << i << endl;
    }
  }

  return 0;
}
