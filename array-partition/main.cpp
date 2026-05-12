#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <vector>

class Solution {
public:
  int arrayPairSum(std::vector<int> &nums) {
    int sum = 0;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i += 2) {
      sum += nums[i];
    }
    return sum;
  }
};

int main() {
  Solution s;
  std::vector<int> v1{1, 4, 3, 2};
  std::vector<int> v2{6, 2, 6, 5, 1, 2};
  std::cout << s.arrayPairSum(v1) << std::endl; // 4
  std::cout << s.arrayPairSum(v2) << std::endl; // 9
  return 0;
}