#include <iostream>
using namespace std;

int main() {
  int daysJohn, hoursJohn, minutesJohn;
  int daysBill, hoursBill, minutesBill;

  cout << "Please enter the number of days John has worked: ";
  cin >> daysJohn;
  cout << "Please enter the number of hours John has worked: ";
  cin >> hoursJohn;
  cout << "Please enter the number of minutes John has worked: ";
  cin >> minutesJohn;

  cout << endl;

  cout << "Please enter the number of days Bill has worked: ";
  cin >> daysBill;
  cout << "Please enter the number of hours Bill has worked: ";
  cin >> hoursBill;
  cout << "Please enter the number of minutes Bill has worked: ";
  cin >> minutesBill;

  int totalMinutes = minutesJohn + minutesBill;
  int totalHours = hoursJohn + hoursBill + totalMinutes / 60;
  int totalDays = daysJohn + daysBill + totalHours / 24;

  int finalMinutes = totalMinutes % 60;
  int finalHours = totalHours % 24;

  cout << "\nThe total time both of them worked together is: " << totalDays
       << " days, " << finalHours << " hours and " << finalMinutes
       << " minutes." << endl;

  return 0;
}