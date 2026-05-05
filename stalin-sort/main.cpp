#include <cstddef>
#include <iostream>
#include <vector>

void stalinSort(std::vector<int> &arr) {
  auto first_sirvives = arr.begin();
  size_t i = 1;
  while (i < arr.size()) {
    if (arr[i - 1] > arr[i]) {
      arr.erase(first_sirvives + i);
      std::cout << "Расстрелять!" << std::endl;
    } else {
      ++i;
    }
  }
}

int main() {
  std::vector<int> a = {5, 3, 1, 2, 4};

  stalinSort(a);

  for (const int &el : a) {
    std::cout << el << std::endl;
  }

  return 0;
}
