#include <iostream>

#include "money.cpp"
using namespace std;

class Check {
 private:
  int checkNumber;
  Money amount;
  bool cashed;

 public:
  // Constructors
  Check();
  Check(int number, Money amt, bool isCashed);

  // Accessors
  int getNumber() const;
  Money getAmount() const;
  bool isCashed() const;

  // Mutators
  void setNumber(int number);
  void setAmount(Money amt);
  void setCashed(bool isCashed);

  // Input/Output
  void input();
  void output() const;
};

// Constructors
Check::Check() {
  checkNumber = 0;
  amount = Money();
  cashed = false;
}

Check::Check(int number, Money amt, bool isCashed) {
  checkNumber = number;
  amount = amt;
  cashed = isCashed;
}

// Accessors
int Check::getNumber() const {
  return checkNumber;
}

Money Check::getAmount() const {
  return amount;
}

bool Check::isCashed() const {
  return cashed;
}

// Mutators
void Check::setNumber(int number) {
  checkNumber = number;
}

void Check::setAmount(Money amt) {
  amount = amt;
}

void Check::setCashed(bool isCashed) {
  cashed = isCashed;
}

// Input
void Check::input() {
  int number;
  double amt;
  int cashedFlag;

  cout << "Enter check number: ";
  cin >> number;

  cout << "Enter check amount (e.g., 25.50 for $25.50): ";
  cin >> amt;

  cout << "Has it been cashed? (1 for yes, 0 for no): ";
  cin >> cashedFlag;

  long dollars = static_cast<long>(amt);
  int cents = static_cast<int>((amt - dollars) * 100 + 0.5);

  checkNumber = number;
  amount = Money(dollars, cents);
  cashed = (cashedFlag == 1);
}

// Output
void Check::output() const {
  cout << "Check #" << checkNumber << endl;
  cout << "Amount: " << amount << endl;
  cout << "Cashed: " << (cashed ? "Yes" : "No") << endl;
}

int main() {
  const int SIZE = 100;
  Check checks[SIZE];
  Money deposits[SIZE];

  // 1. Old account balance
  double oldAmt;
  cout << "Enter your old account balance: ";
  cin >> oldAmt;
  long d = static_cast<long>(oldAmt);
  int c = static_cast<int>((oldAmt - d) * 100 + 0.5);
  Money oldBalance(d, c);

  // 2. New deposits
  int numDeposits;
  cout << "\nEnter the number of new deposits: ";
  cin >> numDeposits;

  Money depositTotal(0);
  for (int i = 0; i < numDeposits; ++i) {
    double depAmt;
    cout << "Deposit #" << i + 1 << ": ";
    cin >> depAmt;
    long d = static_cast<long>(depAmt);
    int c = static_cast<int>((depAmt - d) * 100 + 0.5);
    deposits[i] = Money(d, c);
    depositTotal = depositTotal + deposits[i];
  }

  // 3. Checks
  int numChecks;
  cout << "\nEnter the number of checks: ";
  cin >> numChecks;

  for (int i = 0; i < numChecks; ++i) {
    cout << "\n[Check #" << i + 1 << "]\n";
    checks[i].input();
  }

  // 4. Total - cashed, uncashed
  Money totalCashed(0), totalUncashed(0);

  cout << "\n✅ Cashed Checks:\n";
  for (int i = 0; i < numChecks; ++i) {
    if (checks[i].isCashed()) {
      checks[i].output();
      totalCashed = totalCashed + checks[i].getAmount();
    }
  }

  cout << "\n✅ Uncashed Checks:\n";
  for (int i = 0; i < numChecks; ++i) {
    if (!checks[i].isCashed()) {
      checks[i].output();
      totalUncashed = totalUncashed + checks[i].getAmount();
    }
  }

  // 5. Final calculation
  Money bankBalance = oldBalance + depositTotal - totalCashed;
  Money actualBalance = bankBalance - totalUncashed;
  Money diff = actualBalance - bankBalance;

  cout << "\nTotal Deposits: " << depositTotal << endl;
  cout << "Total Cashed Amount: " << totalCashed << endl;
  cout << "Total Uncashed Amount: " << totalUncashed << endl;

  cout << "\nBank Balance (Old + Deposits - Cashed): " << bankBalance << endl;
  cout << "Actual Balance (after all checks cashed): " << actualBalance << endl;
  cout << "Difference from Bank: " << diff << endl;

  return 0;
}