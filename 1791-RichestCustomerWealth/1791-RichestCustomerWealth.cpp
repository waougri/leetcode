// Last updated: 5/20/2026, 11:36:06 PM
class Solution {
public:
  int maximumWealth(vector<vector<int>> &accounts) {
    int max{};
    for (const auto &account : accounts) {
      int sum = std::accumulate(account.begin(), account.end(), 0,
                                [](int acc, int i) { return acc + i; });
      max = std::max(max, sum);
    }

    return max;
  }
};
