// Last updated: 5/20/2026, 11:36:27 PM
class Solution {
public:
    string removeDuplicates(string s) {
        string str;
        for (char c : s) {
            if (!str.empty() && str.back() == c) {
                str.pop_back();
            } else {
                str.push_back(c);
            }
        }
        return str;
    }
};