// Last updated: 5/20/2026, 11:37:46 PM

#include <algorithm>
#include <iterator>
#include <vector>
using std::vector;

class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    nums.erase(std::remove_if(std::begin(nums), std::end(nums),
                              [&](int &num) { return num == val; }),
               std::end(nums));

    return static_cast<int>(std::size(nums));
  }
};
