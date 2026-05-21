// Last updated: 5/20/2026, 11:37:33 PM
#include <iostream>
#include <limits>
#include <vector>
using std::vector;
#define LOG(x) std::cout << x;
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int min = {std::numeric_limits<int>::max()};
    int max_p = {0};
    int share_ct = {1};

    for (int i = 1; i < prices.size(); i++) {
      if (prices[i] > prices[i - 1]) {
        max_p += prices[i] - prices[i - 1];
      }
    }
    return max_p;
  }
};

