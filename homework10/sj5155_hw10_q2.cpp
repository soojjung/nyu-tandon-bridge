#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int* findMissing(int arr[], int n, int& resArrSize) {
  vector<char> seen(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    if (arr[i] >= 0 && arr[i] <= n)
      seen[arr[i]] = 1;
  }

  int missCount = 0;
  for (int v = 0; v <= n; ++v)
    if (!seen[v])
      ++missCount;
  resArrSize = missCount;

  int* result = new int[missCount];
  int idx = 0;
  for (int v = 0; v <= n; ++v)
    if (!seen[v])
      result[idx++] = v;
  return result;
}

int main() {
  cout << "Enter the array (e.g. [3, 1, 3, 0, 6, 4]): ";
  string line;
  getline(cin, line);

  for (size_t i = 0; i < line.length(); ++i) {
    if (line[i] == '[' || line[i] == ']' || line[i] == ',') {
      line[i] = ' ';
    }
  }
  stringstream ss(line);

  vector<int> input;
  int val;
  while (ss >> val) input.push_back(val);

  int n = static_cast<int>(input.size());

  int missingSize = 0;
  int* missing = (n == 0) ? nullptr : findMissing(&input[0], n, missingSize);

  cout << '{';
  for (int i = 0; i < missingSize; ++i) {
    cout << missing[i];
    if (i != missingSize - 1)
      cout << ", ";
  }
  cout << "}\n";
  cout << "missingSize = " << missingSize << '\n';

  delete[] missing;
  return 0;
}