#include <iostream>
using namespace std;

/*
 * 높이 n인 삼각형을, 왼쪽에서 m칸 띄우고(symbol으로 채운) 출력한다.
 * 각 행 i (1 <= i <= n)에는 (2*i - 1)개의 symbol 문자가 나온다.
 */
void printShiftedTriangle(int n, int m, char symbol) {
  for (int i = 1; i <= n; i++) {
    // 한 줄에 들어가는 symbol의 개수: 2*i - 1
    int rowWidth = 2 * i - 1;

    // 왼쪽에 찍어야 할 공백 수: (totalWidth - rowWidth) / 2
    int leftSpaces = (m - rowWidth) / 2;
    for (int s = 0; s < leftSpaces; s++) {
      cout << ' ';
    }

    // symbol을 rowWidth개 찍는다.
    for (int c = 0; c < rowWidth; c++) {
      cout << symbol;
    }

    cout << '\n';
  }
}

void printPineTree(int n, char symbol) {
  int totalWidth = 2 * (n + 1) - 1;

  for (int k = 1; k <= n; k++) {
    printShiftedTriangle(k + 1, totalWidth, symbol);
  }
}

int main() {
  int n;
  char symbol;

  cout << "Enter the number of triangles: ";
  cin >> n;

  if (n <= 0) {
    return 0;
  }

  cout << "Enter the fill character: ";
  cin >> symbol;

  printPineTree(n, symbol);

  return 0;
}