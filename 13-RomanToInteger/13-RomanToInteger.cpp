// Last updated: 5/20/2026, 11:37:52 PM
#include <string>
#include <unordered_map>
using std::string;

class Solution {
public:
    const std::unordered_map<char, int> romans{{'I', 1},   {'V', 5},   {'X', 10},
                                              {'L', 50},  {'C', 100}, {'D', 500},
                                              {'M', 1000}};
    const std::unordered_map<string, int> special_romans{
        {"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90}, {"CD", 400}, {"CM", 900}};

    int romanToInt(string s) {
        int sum = 0;
        int n = s.size();
        
        for (int i = 0; i < n; ++i) {
         
            if (i < n - 1 && special_romans.count(s.substr(i, 2))) {
                sum += special_romans.at(s.substr(i, 2));
                ++i; 
            } else {
                sum += romans.at(s[i]);
            }
        }
        
        return sum;
    }
};
