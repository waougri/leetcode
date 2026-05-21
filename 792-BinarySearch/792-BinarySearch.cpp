// Last updated: 5/20/2026, 11:36:35 PM
#include <iostream>
#include <vector>
#include <cmath>

class Solution {
    public:
        int search(std::vector<int>& nums, int target) {
            int lo = 0, mid = 0, hi = nums.size();

            while(lo < hi) {
                mid = floor(lo + (hi - lo) / 2);

                if (nums[mid] == target) {
                    return mid;
                } else if (nums[mid] > target) { 
                    hi = mid;
                    continue;
                } else if (nums[mid] < target) {
                    lo = mid + 1;
                    continue;
                }

            }
            return -1;
        }
};
