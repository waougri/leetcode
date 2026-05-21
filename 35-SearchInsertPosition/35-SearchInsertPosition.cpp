// Last updated: 5/20/2026, 11:37:43 PM
#include <cmath>
#include <cstdio>
#include <vector>
using std::vector;

class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int lo = 0;
    int hi = std::size(nums) - 1;
    auto result = 0;
    while (hi > lo) {
      int mid = std::ceil(lo + (hi - lo) / 2);
      if (nums.at(mid) == target) {
        return mid;
      }
      if (nums.at(mid) < target) {
        ++lo;
      } else if (nums.at(mid) > target) {
        --hi;
      }
    }

    int res = hi;
    if (nums[hi] < target) {
      ++res;
    }
    return res;
  }
};


