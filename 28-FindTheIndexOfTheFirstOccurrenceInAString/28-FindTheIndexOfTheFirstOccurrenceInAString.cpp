// Last updated: 5/20/2026, 11:37:45 PM
class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle) != std::string::npos ? haystack.find(needle) : -1;
    }
};