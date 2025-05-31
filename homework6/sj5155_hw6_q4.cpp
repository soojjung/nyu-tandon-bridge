#include <iostream>
using namespace std;

void printDivisors(int num) {
  int i;

  for (i = 1; i * i <= num; i++) {
    if (num % i == 0) {
      cout << i << ' ';
    }
  }

  for (int j = i - 1; j >= 1; j--) {
    if (num % j == 0) {
      if (j * j == num)
        continue;
      cout << (num / j) << ' ';
    }
  }

  cout << '\n';
}

int main() {
  int n;

  cout << "Please enter a positive integer >= 2: ";
  cin >> n;
  if (n < 2)
    return 0;

  printDivisors(n);
  return 0;
}
