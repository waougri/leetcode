// Last updated: 5/20/2026, 11:36:42 PM
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using std::string;

class Solution {
public:
    bool isSubsequence(string s, string t) {

        int s_len = s.length();
        int t_len = t.length();

        if (s_len > t_len) {
            return false;
        }

        int s_idx = 0;
        int t_idx = 0;

        while (t_idx < t_len) {
            if (s_idx < s_len && s[s_idx] == t[t_idx]) {
                ++s_idx;
            }
            ++t_idx;
        }

        return s_idx == s_len;
    }
};
