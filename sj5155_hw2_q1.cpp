#include <iostream>
using namespace std;

int main() {
  int quarters, dimes, nickels, pennies;

  cout << "Please enter number of coins:\n";
  cout << "# of quarters: ";
  cin >> quarters;

  cout << "# of dimes: ";
  cin >> dimes;

  cout << "# of nickels: ";
  cin >> nickels;

  cout << "# of pennies: ";
  cin >> pennies;

  int totalCents = quarters * 25 + dimes * 10 + nickels * 5 + pennies;
  int dollars = totalCents / 100;
  int cents = totalCents % 100;

  cout << "The total is " << dollars << " dollars and " << cents << " cents"
       << endl;

  return 0;
}
