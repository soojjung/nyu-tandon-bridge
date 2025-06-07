#include <iostream>
#include <string>
using namespace std;

int printMonthCalendar(int numOfDays, int startingDay) {
  cout << "Mon\tTue\tWed\tThr\tFri\tSat\tSun\n";

  for (int wd = 1; wd < startingDay; ++wd) {
    cout << "\t";
  }
  int weekday = startingDay;
  for (int day = 1; day <= numOfDays; ++day) {
    cout << day;
    if (weekday < 7)
      cout << "\t";
    else
      cout << "\n";
    weekday = (weekday % 7) + 1;
  }
  if (weekday != 1)
    cout << "\n";
  int last = (startingDay + numOfDays - 1) % 7;
  return (last == 0 ? 7 : last);
}

bool isLeapYear(int year) {
  if (year % 400 == 0)
    return true;
  if (year % 100 == 0)
    return false;
  return (year % 4 == 0);
}

void printYearCalendar(int year, int startingDay) {
  const string months[12] = {"January",   "February", "March",    "April",
                             "May",       "June",     "July",     "August",
                             "September", "October",  "November", "December"};
  int monthDays[12] = {
      31, isLeapYear(year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  int sd = startingDay;
  for (int m = 0; m < 12; ++m) {
    cout << "\n" << months[m] << " " << year << "\n";

    int lastWeekday = printMonthCalendar(monthDays[m], sd);

    sd = (lastWeekday % 7) + 1;
  }
}

int main() {
  int year, startingDay;
  cout << "Print Year Calendar\n";
  cout << "Enter year and starting weekday of Jan 1 (1=Mon…7=Sun): ";
  if (!(cin >> year >> startingDay) || startingDay < 1 || startingDay > 7) {
    cerr << "Invalid input\n";
    return 1;
  }

  cout << "\n=== " << year << " Calendar ===\n";
  printYearCalendar(year, startingDay);
  cout << endl;
  return 0;
}
