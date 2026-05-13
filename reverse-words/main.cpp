#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>

class Solution {
public:
  std::string reverseWords(std::string s) {
    std::string result = "";
    int i = s.size() - 1;

    while (i >= 0) {
      if (s[i] == ' ') {
        i--;
        continue;
      }

      std::string tmp = "";
      int j = i;

      while (j >= 0 && s[j] != ' ') {
        tmp += s[j];
        j--;
      }

      std::reverse(tmp.begin(), tmp.end());

      result += tmp + ' ';
      i = j;
    }

    if (!result.empty()) {
      result.pop_back();
    }

    return result;
  }
};

int main() {
  Solution s;
  std::cout << s.reverseWords("the sky is blue")
            << std::endl; // blue is sky the
  return 0;
}
