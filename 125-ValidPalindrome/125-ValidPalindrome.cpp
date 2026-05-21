// Last updated: 5/20/2026, 11:37:32 PM
#include <algorithm>
#include <cctype>
#include <string>
using std::string;

class Solution {
public:
  bool isPalindrome(string s) {
    auto sw =
        s.erase(std::remove_if(s.begin(), s.end(),
                               [](const char &c) { return !std::isalnum(c); }),
                s.end());
    std::transform(s.begin(), s.end(), s.begin(),
                   [](const char &c) { return std::tolower(c); });

    auto cp{s};
    std::reverse(cp.begin(), cp.end());

    return cp == s;
  }
};
