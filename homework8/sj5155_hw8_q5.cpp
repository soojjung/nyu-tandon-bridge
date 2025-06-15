#include <iostream>
#include <string>
using namespace std;

int main() {
  string first, middle, last;
  cout << "Please enter your name (First Middle Last): ";

  cin >> first >> middle >> last;

  char midInit = middle[0];

  cout << last << ", " << first << " " << midInit << "." << endl;

  return 0;
}
