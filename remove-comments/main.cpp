#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> removeComments(std::vector<std::string> &source) {
  std::vector<std::string> result;
  std::reverse(result.begin(), result.end());

  bool is_block_comment = false;
  bool is_oneline_comment = false;
  std::string tmp = "";
  int i = 0;

  while (i < source.size()) {
    int j = 0;
    while (j < source[i].size()) {

      if (!is_block_comment) {
        if (source[i][j] == '/' && j + 1 < source[i].size() &&
            source[i][j + 1] == '/') {
          is_oneline_comment = true;
          break;
        }

        if (source[i][j] == '/' && j + 1 < source[i].size() &&
            source[i][j + 1] == '*') {
          is_block_comment = true;
          j += 2;
          continue;
        }
        tmp += source[i][j];
      } else {
        if (source[i][j] == '*' && j + 1 < source[i].size() &&
            source[i][j + 1] == '/') {
          is_block_comment = false;
          j += 2;
          continue;
        }
      }

      j++;
    }

    if (!is_block_comment) {
      if (!tmp.empty()) {
        result.push_back(tmp);
      }
      tmp = "";
      is_oneline_comment = false;
    }
    i++;
  }

  return result;
}

int main() {
  std::vector<std::string> source1 = {"a/*comment", "line", "more_comment*/b"};
  auto result1 = removeComments(source1);

  for (auto const &str : result1) {
    std::cout << str << std::endl;
  }

  std::cout << "----------------------------" << std::endl;

  std::vector<std::string> source2 = {"/*Test program */",
                                      "int main()",
                                      "{ ",
                                      "  // variable declaration ",
                                      "int a, b, c;",
                                      "/* This is a test",
                                      "   multiline  ",
                                      "   comment for ",
                                      "   testing */",
                                      "a = b + c;",
                                      "}"};
  auto result2 = removeComments(source2);

  for (auto const &str : result2) {
    std::cout << str << std::endl;
  }
  return 0;
}