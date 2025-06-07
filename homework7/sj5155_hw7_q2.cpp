#include <iostream>
#include <vector>
using namespace std;

void analyzeDivisors(int num, int& outCountDivs, int& outSumDivs) {
  outCountDivs = 0;
  outSumDivs = 0;

  outCountDivs++;
  outSumDivs += 1;
  int limit = static_cast<int>(sqrt(num));
  for (int d = 2; d <= limit; ++d) {
    if (num % d == 0) {
      int other = num / d;
      if (d == other) {
        outCountDivs++;
        outSumDivs += d;
      } else {
        outCountDivs += 2;
        outSumDivs += d + other;
      }
    }
  }
}

bool isPerfect(int num) {
  int cnt, sum;
  analyzeDivisors(num, cnt, sum);
  return sum == num;
}

int main() {
  int M;
  cout << "Enter upper bound M (>=2): ";
  if (!(cin >> M) || M < 2) {
    cerr << "Invalid input\n";
    return 1;
  }

  cout << "\nPerfect numbers between 2 and " << M << ":\n";
  bool foundAny = false;
  for (int n = 2; n <= M; ++n) {
    if (isPerfect(n)) {
      cout << n << "  ";
      foundAny = true;
    }
  }
  if (!foundAny) {
    cout << "None";
  }
  cout << "\n";

  cout << "\nAmicable pairs between 2 and " << M << ":\n";
  foundAny = false;

  vector<int> sumDivs(M + 1, 0);
  for (int n = 2; n <= M; ++n) {
    int cnt;
    analyzeDivisors(n, cnt, sumDivs[n]);
  }
  for (int a = 2; a <= M; ++a) {
    int b = sumDivs[a];
    if (b > a && b <= M) {
      if (sumDivs[b] == a) {
        cout << "(" << a << ", " << b << ")\n";
        foundAny = true;
      }
    }
  }
  if (!foundAny) {
    cout << "None\n";
  }

  return 0;
}
