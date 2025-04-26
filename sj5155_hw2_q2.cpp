#include <iostream>
using namespace std;

int main() {
  int dollars, cents;

  cout << "Please enter your amount in the format of dollars and cents "
          "separated by a space:"
       << endl;
  cin >> dollars >> cents;

  int totalCents = dollars * 100 + cents;

  int quarters = totalCents / 25;
  totalCents %= 25;

  int dimes = totalCents / 10;
  totalCents %= 10;

  int nickels = totalCents / 5;
  totalCents %= 5;

  int pennies = totalCents;

  cout << dollars << " dollars and " << cents << " cents are:" << endl;
  cout << quarters << " quarters, " << dimes << " dimes, " << nickels
       << " nickels and " << pennies << " pennies" << endl;

  return 0;
}