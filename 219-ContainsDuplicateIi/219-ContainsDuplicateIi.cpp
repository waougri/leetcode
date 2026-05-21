// Last updated: 5/20/2026, 11:36:52 PM
#include <iterator>
#include <vector>
using std::vector;
class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    auto f = std::adjacent_find(
        nums.begin(), nums.end(),
        [&nums, k, start = nums.begin()](const int &a, const int &b) mutable {
          int i = std::distance(nums.begin(), start);
          for (auto it = std::next(start);
               it != nums.end() && std::distance(start, it) <= k; ++it) {
            if (*start == *it) {
              return true;
            }
          }
          ++start;
          return false;
        });

    return f != nums.end();
  }
};