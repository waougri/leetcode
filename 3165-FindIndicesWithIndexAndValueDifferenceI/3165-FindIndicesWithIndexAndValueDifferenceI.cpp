// Last updated: 5/20/2026, 11:35:50 PM
#include <cstdlib>
#include <vector>
using std::vector;

class Solution {
public:
  vector<int> findIndices(vector<int> &nums, int indexDifference,
                          int valueDifference) {

    for (int i = 0; i < nums.size(); ++i) {
      for (int j = i; j < nums.size(); ++j) {
        if (std::abs(i - j) >= indexDifference &&
            std::abs(nums[i] - nums[j]) >= valueDifference) {
          return {i, j};
        }
      }
    }
    return {-1, -1};
  }
};
