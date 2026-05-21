// Last updated: 5/20/2026, 11:37:48 PM
#include <cstdio>
#include <set>
#include <vector>
using std::vector;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {

    for (int i = 0; i < nums.size(); ++i) {
      auto curr = nums.at(i);

      nums.erase(std::remove_if(nums.begin() + i + 1, nums.end(),
                                [&](int &val) { return val == curr; }),
                 nums.end());
    }

    return nums.size();
  }
};
