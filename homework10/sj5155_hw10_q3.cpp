#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

void printResult(int num, const int* lines, int count) {
  if (count == 0) {
    cout << num << " does not show at all in the sequence.\n";
    return;
  }

  cout << num << " shows in lines ";
  for (int i = 0; i < count; ++i) {
    cout << lines[i];
    if (i != count - 1)
      cout << ", ";
  }
  cout << ".\n";
}

// VERSION 1  –  manual dynamic arrays  (no std::vector)
void main1() {
  cout << "Please enter a sequence of positive integers, each in a separate "
          "line.\n";
  cout << "End you input by typing -1.\n";

  int capacity = 10;
  int* seq = new int[capacity];
  int n = 0;

  while (true) {
    int val;
    cin >> val;
    if (val == -1)
      break;

    if (n == capacity) {
      int* bigger = new int[capacity * 2];
      memcpy(bigger, seq, capacity * sizeof(int));
      delete[] seq;
      seq = bigger;
      capacity *= 2;
    }
    seq[n++] = val;
  }

  cout << "Please enter a number you want to search.\n";
  int target;
  cin >> target;

  int lineCap = 4;
  int* lines = new int[lineCap];
  int count = 0;

  for (int i = 0; i < n; ++i) {
    if (seq[i] == target) {
      if (count == lineCap) {
        int* bigger = new int[lineCap * 2];
        memcpy(bigger, lines, lineCap * sizeof(int));
        delete[] lines;
        lines = bigger;
        lineCap *= 2;
      }
      lines[count++] = i + 1;
    }
  }

  printResult(target, lines, count);

  delete[] seq;
  delete[] lines;
}

// VERSION 2  –  using std::vector
void main2() {
  cout << "Please enter a sequence of positive integers, each in a separate "
          "line.\n";
  cout << "End you input by typing -1.\n";

  vector<int> seq;
  while (true) {
    int val;
    cin >> val;
    if (val == -1)
      break;
    seq.push_back(val);
  }

  cout << "Please enter a number you want to search.\n";
  int target;
  cin >> target;

  vector<int> lines;
  for (size_t i = 0; i < seq.size(); ++i) {
    if (seq[i] == target)
      lines.push_back(static_cast<int>(i) + 1);
  }

  int* raw = lines.empty() ? nullptr : &lines[0];
  printResult(target, raw, static_cast<int>(lines.size()));
}

int main() {
  cout << "\n--- version without vector --------------------------------\n";
  main1();

  cout << "\n--- version with vector -----------------------------------\n";
  main2();
  return 0;
}
