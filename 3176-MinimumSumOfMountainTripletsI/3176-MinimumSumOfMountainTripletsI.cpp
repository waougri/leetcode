// Last updated: 5/20/2026, 11:35:45 PM
#include <algorithm>
#include <climits>
#include <vector>
using std::vector;

class Solution {
public:
  int minimumSum(vector<int> &nums) {
    int sum{INT_MAX};
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = i + 1; j < nums.size(); ++j) {
        for (int k = j + 1; k < nums.size(); ++k) {
          if (nums[i] < nums[j] && nums[k] < nums[j]) {
            sum = std::min(sum, (nums[i] + nums[j] + nums[k]));
          }
        }
      }
    }

    return sum == INT_MAX ? -1 : sum;
  }
};
