#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  bool isPalindrome(std::string const &s) {
    if (s.empty())
      return true;
    for (size_t i = 0; i < s.size() / 2; ++i) {
      if (s[i] != s[s.size() - i - 1]) {
        return false;
      }
    }
    return true;
  }
  std::string firstPalindrome(std::vector<std::string> &words) {
    for (auto const &str : words) {
      if (isPalindrome(str)) {
        return str;
      }
    }
    return "";
  }
};

int main() {
  Solution s;
  std::vector<std::string> v1{"abc", "car", "ada", "racecar", "cool"};
  std::cout << s.firstPalindrome(v1) << std::endl; // ada
  return 0;
}