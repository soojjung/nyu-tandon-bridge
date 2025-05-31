#include <iostream>
using namespace std;

int fib(int n) {
  if (n <= 2) {
    return 1;
  }

  int a = 1;
  int b = 1;
  int c;

  for (int i = 3; i <= n; i++) {
    c = a + b;
    a = b;
    b = c;
  }

  return b;
}

int main() {
  int num;

  cout << "Please enter a positive integer: ";
  if (!(cin >> num) || num <= 0) {
    return 0;
  }

  int result = fib(num);
  cout << result << "\n";

  return 0;
}
