#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

const string SECRET_PIN = "12345";

void generateMapping(int mapToNum[10]) {
  for (int i = 0; i < 10; ++i) {
    mapToNum[i] = rand() % 3 + 1;
  }
}

void printMapping(const int mapToNum[10]) {
  cout << "Please enter your PIN according to the following mapping:\n";
  cout << "PIN: ";
  for (int d = 0; d < 10; ++d) {
    cout << d << (d < 9 ? ' ' : '\n');
  }
  cout << "NUM: ";
  for (int d = 0; d < 10; ++d) {
    cout << mapToNum[d] << (d < 9 ? ' ' : '\n');
  }
}

string getUserResponse() {
  string resp;
  cin >> resp;
  return resp;
}

bool isCorrectPIN(const string& response, const int mapToNum[10]) {
  string expected;
  for (size_t i = 0; i < SECRET_PIN.length(); ++i) {
    char c = SECRET_PIN[i];
    int digit = c - '0';
    expected += char('0' + mapToNum[digit]);
  }
  return response == expected;
}

int main() {
  srand(static_cast<unsigned>(time(nullptr)));

  int mapToNum[10];
  generateMapping(mapToNum);

  printMapping(mapToNum);

  string response = getUserResponse();

  if (isCorrectPIN(response, mapToNum)) {
    cout << "Your PIN is correct" << endl;
  } else {
    cout << "Your PIN is not correct" << endl;
  }

  return 0;
}
