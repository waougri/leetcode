// Last updated: 5/20/2026, 11:35:46 PM
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_set>

using std::string;

bool areAllSubstringsInReverse(const std::string& s, std::size_t k) {
    if (k == 0 || k > s.length()) {
        return false; 
    }

    std::string reversed = std::string(s.rbegin(), s.rend());

    std::unordered_set<std::string> substrings;
    
   
    for (std::size_t i = 0; i <= s.length() - k; ++i) {
        substrings.insert(s.substr(i, k));
    }
    

    for (const auto& sub : substrings) {
        if (reversed.find(sub) != std::string::npos) {
            return true;
        }
    }
    
    return false;
}
class Solution
{
public:
    bool isSubstringPresent(string s)
    {
        return areAllSubstringsInReverse(s, 2);
    }
};