#include <iostream>
#include <vector>

unsigned long long int sum_factorial(std::vector<int> vi) {
  unsigned long long int sum = 0;
  for (int el : vi) {
    if (el > 0) {
      unsigned long long s = 1;
      while (el)
        s *= el--;
      sum += s;
    }
  }
  return sum;
}

int main() {
  std::vector<int> v = {12, 3,  11, 4, 2,  16, 17, 20, 1,
                        8,  14, 18, 5, 10, 0,  19, 9,  7};
  std::cout << sum_factorial(v) << std::endl;
  return 0;
}