// Last updated: 5/20/2026, 11:37:29 PM
#include <algorithm>
#include <cctype>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using std::string;

std::string remove_excessive_ws(std::string str) {
  bool seen_space = false;
  auto end{std::remove_if(str.begin(), str.end(), [&seen_space](unsigned ch) {
    bool is_space = std::isspace(ch);
    std::swap(seen_space, is_space);
    return seen_space && is_space;
  })};

  if (end != str.begin() && std::isspace(static_cast<unsigned>(end[-1])))
    --end;

  str.erase(end, str.end());
  return str;
}

std::vector<std::string> split(const std::string &s, char delimiter) {
  std::vector<std::string> tokens;
  std::string token;
  std::istringstream tokenStream(s);
  while (std::getline(tokenStream, token, delimiter)) {
    tokens.push_back(token);
  }
  return tokens;
}
class Solution {
public:
  string reverseWords(string s) {

    auto trimmed{remove_excessive_ws(s)};
    auto sp = split(trimmed, ' ');
    std::reverse(sp.begin(), sp.end());

    std::ostringstream oss{};
    for (const auto &s : sp) {
      oss << s << ' ';
    }
    return remove_excessive_ws(oss.str());
  }
};
