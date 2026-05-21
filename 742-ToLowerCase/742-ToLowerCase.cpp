// Last updated: 5/20/2026, 11:36:34 PM
class Solution {
public:
        string toLowerCase(string s) {
      std::ostringstream oss {};
      for(const auto& c : s) {
        oss  << static_cast<char>(tolower(c));
      }

      return oss.str();
    }

};