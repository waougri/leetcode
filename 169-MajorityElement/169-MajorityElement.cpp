// Last updated: 5/20/2026, 11:37:26 PM
#include <algorithm>
#include <map>
#include <vector>
using std::vector;

using histogram_t = std::map<int, int>;

auto hist(const std::vector<int> &vec) -> histogram_t {
  histogram_t hist{};
  for (const auto &v : vec) {
    if (hist.find(v) != hist.end()) {
      ++hist.at(v);
    } else {
      hist.insert({v, 1});
    }
  }

  return hist;
}
class Solution {
public:
  int majorityElement(vector<int> &nums) {
    auto histogram{hist(nums)};
    return std::max_element(histogram.begin(), histogram.end(),
                            [](const std::pair<int, int> &a,
                               const std::pair<int, int> &b) -> bool {
                              return a.second < b.second;
                            })
        ->first;
  }
};
