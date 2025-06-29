#include <iostream>
#include <string>

using namespace std;

inline bool isWhite(char ch) {
  return ch == ' ';
}

string* createWordsArray(const string& sentence, int& outWordsArrSize) {
  size_t wordCount = 0;
  for (size_t i = 0; i < sentence.length(); ++i) {
    if (!isWhite(sentence[i]) &&
        (i + 1 == sentence.length() || isWhite(sentence[i + 1]))) {
      ++wordCount;
    }
  }

  outWordsArrSize = static_cast<int>(wordCount);

  string* words = new string[wordCount];
  if (wordCount == 0) {
    return words;
  }

  size_t start = 0, idx = 0, n = sentence.length();
  while (start < n) {
    while (start < n && isWhite(sentence[start])) {
      ++start;
    }

    if (start >= n) {
      break;
    }

    size_t end = sentence.find(' ', start);
    if (end == string::npos) {
      end = n;
    }

    words[idx++] = sentence.substr(start, end - start);

    start = end + 1;
  }
  return words;
}

int main() {
  cout << "Enter a sentence: ";
  string text;
  getline(cin, text);

  int wordCount = 0;
  string* arr = createWordsArray(text, wordCount);

  cout << "[";
  for (int i = 0; i < wordCount; ++i) {
    cout << '"' << arr[i] << '"';
    if (i != wordCount - 1) {
      cout << ", ";
    }
  }
  cout << "]\n";

  cout << "wordCount = " << wordCount << endl;

  delete[] arr;
  return 0;
}