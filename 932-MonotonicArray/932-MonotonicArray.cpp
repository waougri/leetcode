// Last updated: 5/20/2026, 11:36:31 PM
#include <vector>
using std::vector;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool increasing = true;
        bool decreasing = true;
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i-1]) {
                decreasing = false;
            }
            if (nums[i] < nums[i-1]) {
                increasing = false;
            }
            if (!increasing && !decreasing) {
                return false;
            }
        }
        
        return true;
    }
};