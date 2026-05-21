// Last updated: 5/21/2026, 12:06:19 AM
#include <unordered_set>
#include <vector>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> set;
        
        for (const auto& num : nums) {
            if (set.count(num))
                return true;
            set.insert(num);
        }
        
        return false;
    }
};
