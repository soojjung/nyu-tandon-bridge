#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
  int x1, x2, x3, x4;

  srand(time(0));

  x1 = rand();
  x2 = rand();
  x3 = rand() % 100;
  x4 = (rand() % 100) + 1;

  int target = x4;

  int low = 1, high = 100;
  int guesses_left = 5;
  int attempts = 0;
  int guess;

  cout << "I thought of a number between 1 and 100! Try to guess it." << endl;

  while (guesses_left > 0) {
    cout << "Range: [" << low << ", " << high
         << "], Number of guesses left: " << guesses_left << endl;
    cout << "Your guess: ";
    cin >> guess;

    attempts++;
    guesses_left--;

    if (guess == target) {
      cout << "Congrats! You guessed my number in " << attempts << " guesses."
           << endl;
      return 0;
    } else if (guesses_left > 0) {
      if (guess < target) {
        cout << "Wrong! My number is bigger." << endl << endl;
        low = guess + 1;
      } else {
        cout << "Wrong! My number is smaller." << endl << endl;
        high = guess - 1;
      }
    } else {
      cout << "Out of guesses! My number is " << target << endl;
    }
  }

  return 0;
}
