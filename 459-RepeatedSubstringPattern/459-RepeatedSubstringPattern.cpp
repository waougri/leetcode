// Last updated: 5/20/2026, 11:36:39 PM
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string doubled = s + s;
        string substr = doubled.substr(1, doubled.size() - 2);
        
        return search(substr.begin(), substr.end(), 
                      s.begin(), s.end()) != substr.end();
    }
};