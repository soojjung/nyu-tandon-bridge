#include <iostream>
#include <string>
using namespace std;

int main() {
  string userName;
  int gradYear, currentYear;

  cout << "Please enter your name: ";
  cin >> userName;
  cout << "Please enter your graduation year: ";
  cin >> gradYear;
  cout << "Please enter current year: ";
  cin >> currentYear;

  int diff = gradYear - currentYear;
  string status;

  if (diff == 4) {
    status = "Freshman";
  } else if (diff == 3) {
    status = "Sophomore";
  } else if (diff == 2) {
    status = "Junior";
  } else if (diff == 1) {
    status = "Senior";
  } else {
    status = "not valid";
  }

  cout << userName << ", you are a " << status << endl;

  return 0;
}
