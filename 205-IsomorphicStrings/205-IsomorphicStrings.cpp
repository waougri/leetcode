// Last updated: 5/21/2026, 12:06:22 AM
#include <string>
#include <array>
using std::string;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
       
        std::array<char, 256> s_to_t = {0};
        std::array<char, 256> t_to_s = {0};

        for (size_t i = 0; i < s.length(); ++i) {
            char c_s = s[i];
            char c_t = t[i];

            if (s_to_t[c_s] == 0 && t_to_s[c_t] == 0) {
                s_to_t[c_s] = c_t;
                t_to_s[c_t] = c_s;
            } else if (s_to_t[c_s] != c_t || t_to_s[c_t] != c_s) {
                return false;
            }
        }

        return true;
    }
};