#include <cctype>
#include <iostream>
#include <string>

using namespace std;

string normalize(const string& s) {
  string out;
  out.reserve(s.size());
  for (size_t i = 0; i < s.length(); ++i) {
    char ch = s[i];
    if (isalpha(static_cast<unsigned char>(ch))) {
      out += tolower(static_cast<unsigned char>(ch));
    }
  }
  return out;
}

bool areAnagrams(const string& s1, const string& s2) {
  if (s1.length() != s2.length())
    return false;
  int count[26];

  for (int i = 0; i < 26; ++i) count[i] = 0;

  for (size_t i = 0; i < s1.length(); ++i) {
    count[s1[i] - 'a']++;
    count[s2[i] - 'a']--;
  }

  for (int i = 0; i < 26; ++i) {
    if (count[i] != 0)
      return false;
  }
  return true;
}

int main() {
  cout << "Please enter the first string:" << endl;
  string line1;
  getline(cin, line1);

  cout << "Please enter the second string:" << endl;
  string line2;
  getline(cin, line2);

  string s1 = normalize(line1);
  string s2 = normalize(line2);

  if (areAnagrams(s1, s2))
    cout << "The strings are anagrams." << endl;
  else
    cout << "The strings are not anagrams." << endl;

  return 0;
}
