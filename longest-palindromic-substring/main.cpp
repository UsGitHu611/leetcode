#include <cctype>
#include <cmath>
#include <iostream>
#include <string>

class Solution {
public:
  bool isPalindrome(std::string &s, int i, int j) {
    int left = i;
    int right = j - 1;

    while (left < right) {
      if (s[left] != s[right]) {
        return false;
      }

      left++;
      right--;
    }

    return true;
  }
  std::string longestPalindrome(std::string s) {
    for (int i = s.size(); i > 0; i--) {
      for (int j = 0; j <= s.size() - i; j++) {
        if (isPalindrome(s, j, i + j)) {
          return s.substr(j, i);
        }
      }
    }
    return "";
  }
};

int main() {
  Solution s;
  std::cout << s.longestPalindrome("babad") << std::endl; // bab
  return 0;
}