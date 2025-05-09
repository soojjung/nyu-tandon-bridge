#include <iostream>
using namespace std;

int main() {
  int n;
  cout << "Please enter a positive integer: ";
  cin >> n;

  int width = 2 * n - 1;

  for (int i = 0; i < n; ++i) {
    int stars = width - 2 * i;
    int spaces = i;

    for (int s = 0; s < spaces; ++s) cout << ' ';
    for (int k = 0; k < stars; ++k) cout << '*';
    cout << '\n';
  }

  for (int i = 0; i < n; ++i) {
    int stars = 2 * i + 1;
    int spaces = n - 1 - i;

    for (int s = 0; s < spaces; ++s) cout << ' ';
    for (int k = 0; k < stars; ++k) cout << '*';
    cout << '\n';
  }

  return 0;
}
