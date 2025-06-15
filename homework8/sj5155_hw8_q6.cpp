#include <iostream>
#include <sstream>
#include <string>
using namespace std;

bool isAllDigits(const string& token) {
  if (token.empty())
    return false;
  for (size_t i = 0; i < token.size(); ++i) {
    char c = token[i];
    if (!isdigit(static_cast<unsigned char>(c)))
      return false;
  }
  return true;
}

string maskToken(const string& token) {
  return string(token.size(), 'x');
}

string processLine(const string& line) {
  istringstream iss(line);
  string token;
  string output;
  bool first = true;

  while (iss >> token) {
    if (!first)
      output += ' ';
    first = false;

    if (isAllDigits(token)) {
      output += maskToken(token);
    } else {
      output += token;
    }
  }

  return output;
}

int main() {
  cout << "Please enter a line of text:\n";

  string line;
  getline(cin, line);

  cout << processLine(line) << endl;
  return 0;
}
