#include <iostream>
using namespace std;

int main() {
  int n;
  cout << "Please enter a positive integer: ";
  if (!(cin >> n) || n <= 0) {
    cout << "Invalid input." << endl;
    return 1;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << (i * j);
      if (j < n)
        cout << "\t";
    }
    cout << "\n";
  }

  return 0;
}
