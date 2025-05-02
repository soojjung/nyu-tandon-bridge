#include <iostream>
using namespace std;

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

int main() {
  double realNumber;
  int method;

  cout << "Please enter a Real number:" << endl;
  cin >> realNumber;

  cout << "Choose your rounding method:" << endl;
  cout << "1. Floor round" << endl;
  cout << "2. Ceiling round" << endl;
  cout << "3. Round to the nearest whole number" << endl;
  cin >> method;

  int result;

  switch (method) {
    case FLOOR_ROUND:
      result = (int)realNumber;
      break;

    case CEILING_ROUND:
      result = (int)realNumber;
      if (realNumber > 0 && realNumber != result) {
        result += 1;
      }
      break;

    case ROUND:
      result = (int)realNumber;
      if (realNumber - result >= 0.5) {
        result += 1;
      }
      break;

    default:
      cout << "Invalid rounding method" << endl;
      return 1;
  }

  cout << result << endl;

  return 0;
}
