#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>

class Solution {
public:
  std::string entityParser(std::string text) {
    std::map<std::string, char> chars{
        {"quot", '\"'}, {"apos", '\''}, {"amp", '&'},
        {"gt", '>'},    {"lt", '<'},    {"frasl", '/'},
    };

    std::string result;
    result.reserve(text.size());
    int i = 0;

    while (i < text.size()) {
      if (text[i] == '&') {
        int j = i + 1;
        std::string key = "";
        while (j < text.size() && std::isalnum(text[j])) {
          key += text[j++];
        }

        if (j < text.size() && text[j] == ';') {
          if (chars.find(key) != chars.end()) {
            result += chars.at(key);
          } else {
            result += '&' + key + ';';
          }
          i = j + 1;
        } else {
          result += '&';
          i++;
        }
      } else {
        result += text[i++];
      }
    }

    return result;
  }
};

int main() {
  Solution s;
  std::cout << s.entityParser(
                   "&amp; is an HTML entity but &ambassador; is not.")
            << std::endl;
  std::cout << s.entityParser("and I quote: &quot;...&quot;") << std::endl;
  std::cout << s.entityParser("&&gt;") << std::endl;
  return 0;
}
