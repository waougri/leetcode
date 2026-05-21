// Last updated: 5/20/2026, 11:37:42 PM
#include <vector>
using std::vector;

class Solution {
public:
  int trap(vector<int> &height) {
    if (height.empty()) {
      return 0;
    }

    int l = 0;
    int r = std::size(height) - 1;
    int lm = height.at(l);
    int rm = height.at(r);
    int res = 0;

    while (l < r) {
      if (lm < rm) {
        l++;
        lm = std::max(lm, height.at(l));
        res += lm - height.at(l);
      } else {
        r--;
        rm = std::max(rm, height.at(r));
        res += rm - height.at(r);
      }
    }

    return res;
  }
};
