#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  cout << "section a" << endl;
  cout << "Please enter the length of the sequence: ";
  int n;
  cin >> n;

  cout << "Please enter your sequence:" << endl;
  double product = 1.0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    product *= x;
  }
  double gm = pow(product, 1.0 / n);
  cout << fixed << setprecision(4) << "The geometric mean is: " << gm << endl;

  cout << "section b" << endl;
  cout << "Please enter a non-empty sequence of positive integers, each one in "
          "a separate line. "
          "End your sequence by typing -1:"
       << endl;
  product = 1.0;
  int count = 0;
  while (true) {
    int x;
    cin >> x;
    if (x == -1)
      break;
    product *= x;
    ++count;
  }
  gm = pow(product, 1.0 / count);
  cout << fixed << setprecision(4) << "The geometric mean is: " << gm << endl;

  return 0;
}
