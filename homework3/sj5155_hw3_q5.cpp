#include <iostream>
#include <string>
using namespace std;

int main() {
  double weight, height;

  cout << "Please enter weight (in pounds): ";
  cin >> weight;

  cout << "Please enter height (in inches): ";
  cin >> height;

  double weightKg = 0.453592 * weight;
  double heightM = 0.0254 * height;

  double BMI = weightKg / (heightM * heightM);

  string status;

  if (BMI < 18.5) {
    status = "Underweight";
  } else if (BMI < 25) {
    status = "Normal";
  } else if (BMI < 30) {
    status = "Overweight";
  } else {
    status = "Obese";
  }

  cout << "The weight status is: " << status << endl;

  return 0;
}
