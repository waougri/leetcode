// Last updated: 5/20/2026, 11:36:44 PM
#include <string>
#include <array>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        array<int, 26> count = {0};
        
        for (char c : magazine) {
            ++count[c - 'a'];
        }
        
        for (char c : ransomNote) {
            if (--count[c - 'a'] < 0) {
                return false;
            }
        }
        
        return true;
    }
};