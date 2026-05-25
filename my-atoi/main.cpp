#include <cctype>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>

int myAtoi(std::string s) {
  if (isalpha(s[0]))
    return 0;

  int i = 0;
  int k = 0;
  double result = 0;
  bool is_negative = false;

  while (i < s.size() && isspace(s[i]))
    i++;

  if (s[i] == '-') {
    is_negative = true;
    while (i + k + 1 < s.size() && isdigit(s[i + k + 1]))
      k++;
    s = s.substr(i + 1, k);
  } else {
    if (s[i] == '+')
      i++;
    while (i + k < s.size() && isdigit(s[i + k]))
      k++;
    s = s.substr(i, k);
  }

  for (int i = 0; i < s.size(); ++i) {
    result += (s[i] - '0') * pow(10, s.size() - i - 1);
    if (!is_negative && result >= INT_MAX)
      return INT_MAX;
    if (is_negative && -result <= INT_MIN)
      return INT_MIN;
  }

  if (is_negative)
    result = -result;
  return result;
}

int main() {
  std::cout << myAtoi("42") << std::endl;
  std::cout << myAtoi("-042") << std::endl;
  std::cout << myAtoi("   -042") << std::endl;
  std::cout << myAtoi("1337c0d3") << std::endl;
  std::cout << myAtoi("0-1") << std::endl;
  std::cout << myAtoi("words and 987") << std::endl;
  return 0;
}
