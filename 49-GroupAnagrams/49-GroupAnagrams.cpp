// Last updated: 5/20/2026, 11:37:40 PM
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length())
      return false;

    std::sort(s.begin(), s.end());
    std::sort(t.begin(), t.end());

    for (int i = 0; i < s.length(); ++i) {
      if (s.at(i) != t.at(i)) {
        return false;
      }
    }

    return true;
  }
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> vvec{};
    if (strs.size() == 0) {
      vvec.push_back({""});
      return vvec;
    } else if (strs.size() == 1) {
      vvec.push_back({strs[0]});
      return vvec;
    }
    std::sort(strs.begin(), strs.end());

    std::unordered_map<string, vector<string>> pairs{};
    for (const auto &str : strs) {
      string sortedStr = str;
      std::sort(sortedStr.begin(), sortedStr.end()); // Sort the string

      // Add the string to the corresponding anagram group in the map
      pairs[sortedStr].push_back(str);
    }

    for (const auto &pair : pairs) {
      vvec.push_back(pair.second);
    }

    return vvec;
  }
};
