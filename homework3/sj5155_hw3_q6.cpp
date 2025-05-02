#include <iostream>
#include <string>
using namespace std;

int main() {
  string day, time;
  int minutes;

  cout << "Enter the day of the week (Mo Tu We Th Fr Sa Su): ";
  cin >> day;

  cout << "Enter the time the call started (24-hour format, e.g., 13:30): ";
  cin >> time;

  cout << "Enter the duration of the call in minutes: ";
  cin >> minutes;

  int hour = (time[0] - '0') * 10 + (time[1] - '0');
  int minute = (time[3] - '0') * 10 + (time[4] - '0');

  double rate = 0.0;

  if (day == "Sa" || day == "Su") {
    rate = 0.15;
  } else {
    int startTime = hour * 60 + minute;
    int dayStart = 8 * 60;
    int dayEnd = 18 * 60;

    if (startTime >= dayStart && startTime < dayEnd) {
      rate = 0.40;
    } else {
      rate = 0.25;
    }
  }

  double cost = rate * minutes;

  cout << "The cost of the call is $" << cost << endl;

  return 0;
}
