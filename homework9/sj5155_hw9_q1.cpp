#include <cctype>
#include <iostream>
#include <string>

using namespace std;

void countWordsAndLetters(const string& line, int& wordCount, int freq[26]) {
  wordCount = 0;
  for (int i = 0; i < 26; ++i) freq[i] = 0;

  bool inWord = false;
  for (size_t i = 0; i < line.length(); ++i) {
    char ch = line[i];
    if (isalpha(static_cast<unsigned char>(ch))) {
      ch = tolower(static_cast<unsigned char>(ch));
      freq[ch - 'a']++;
      if (!inWord) {
        inWord = true;
        ++wordCount;
      }
    } else {
      inWord = false;
    }
  }
}

int main() {
  cout << "Please enter a line of text:" << endl;
  string line;
  getline(cin, line);

  int wordCount;
  int freq[26];
  countWordsAndLetters(line, wordCount, freq);

  cout << wordCount << " words" << endl;
  for (int i = 0; i < 26; ++i) {
    if (freq[i] > 0) {
      cout << freq[i] << " " << static_cast<char>('a' + i) << endl;
    }
  }

  return 0;
}
