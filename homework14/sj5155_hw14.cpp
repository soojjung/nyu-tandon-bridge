#include <algorithm>  // min, max 함수 사용
#include <iostream>
#include <vector>
using namespace std;

// Divide & Conquer로 min과 max를 찾는 함수
vector<int> findMinMax(const vector<int>& nums, int left, int right) {
    // base case: 요소 1개
    if (left == right) {
        return {nums[left], nums[left]};
    }
    // base case: 요소 2개
    if (right == left + 1) {
        if (nums[left] < nums[right]) {
            return {nums[left], nums[right]};
        } else {
            return {nums[right], nums[left]};
        }
    }

    // Divide
    int mid = (left + right) / 2;
    vector<int> leftMinMax = findMinMax(nums, left, mid);
    vector<int> rightMinMax = findMinMax(nums, mid + 1, right);

    // Conquer: 양쪽 결과를 비교해서 전체 min/max 구함
    int overallMin = min(leftMinMax[0], rightMinMax[0]);
    int overallMax = max(leftMinMax[1], rightMinMax[1]);

    return {overallMin, overallMax};
}

int main() {
    vector<int> nums;
    int n;

    cout << "How many numbers will you enter? ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive number." << endl;
        return 1;
    }

    cout << "Enter " << n << " integers: " << endl;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    vector<int> result = findMinMax(nums, 0, nums.size() - 1);

    cout << "Min: " << result[0] << endl;
    cout << "Max: " << result[1] << endl;

    return 0;
}