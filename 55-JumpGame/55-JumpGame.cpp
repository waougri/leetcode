// Last updated: 5/20/2026, 11:37:40 PM
#include <iostream>
#include <vector>
using std::vector;

class Solution {
public:
  static bool canJump(vector<int> &nums) {
     int n = nums.size();
    int maxReach = 0;
    for (int i = 0; i < n; i++) {
        if (i > maxReach) return false;
        maxReach = max(maxReach, i + nums[i]);
    }
    return true;
  }
};
