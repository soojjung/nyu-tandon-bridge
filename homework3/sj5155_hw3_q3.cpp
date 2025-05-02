#include <cmath>
#include <iostream>
using namespace std;

int main() {
  double a, b, c;

  cout << "Please enter value of a: ";
  cin >> a;
  cout << "Please enter value of b: ";
  cin >> b;
  cout << "Please enter value of c: ";
  cin >> c;

  if (a == 0 && b == 0 && c == 0) {
    cout << "Infinite number of solutions" << endl;
  } else if (a == 0 && b == 0) {
    cout << "No solution" << endl;
  } else {
    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
      cout << "This equation has no real solution" << endl;
    } else if (discriminant == 0) {
      double x = -b / (2 * a);
      cout << "This equation has a single real solution x=" << x << endl;
    } else {
      double x1 = (-b + sqrt(discriminant)) / (2 * a);
      double x2 = (-b - sqrt(discriminant)) / (2 * a);
      cout << "This equation has two real solutions x=" << x1 << " and x=" << x2
           << endl;
    }
  }

  return 0;
}
