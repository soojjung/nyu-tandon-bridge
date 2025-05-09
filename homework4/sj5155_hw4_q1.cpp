#include <iostream>
using namespace std;

int main() {
  int n;
  cout << "Please enter a positive integer: ";
  cin >> n;

  cout << "section a" << endl;
  int count = 1;
  while (count <= n) {
    cout << count * 2 << endl;
    ++count;
  }

  cout << "section b" << endl;
  for (int i = 1; i <= n; ++i) {
    cout << i * 2 << endl;
  }

  return 0;
}
