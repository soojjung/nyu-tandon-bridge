#include <iostream>
#include <string>
using namespace std;

void printTriangle(int n) {
  if (n == 0)
    return;

  printTriangle(n - 1);

  for (int i = 0; i < n; i++) {
    cout << '*';
  }
  cout << endl;
}

void printOppositeTriangle(int n) {
  if (n == 0)
    return;

  for (int i = 0; i < n; i++) {
    cout << '*';
  }
  cout << endl;

  printOppositeTriangle(n - 1);
}

void printOppositeTriangles(int n) {
  printOppositeTriangle(n);
  printTriangle(n);
}

void printLine(int level) {
  for (int i = 0; i < level; i++) {
    cout << '-';
  }
  cout << endl;
}

void printRuler(int n) {
  if (n == 0)
    return;

  printRuler(n - 1);
  printLine(n);
  printRuler(n - 1);
}

int main() {
  int number;
  cout << "Enter a number: ";
  cin >> number;

  printOppositeTriangles(number);

  cout << "======================" << endl;

  printRuler(number);

  return 0;
}
