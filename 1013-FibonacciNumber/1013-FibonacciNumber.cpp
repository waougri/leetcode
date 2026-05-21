// Last updated: 5/20/2026, 11:36:29 PM
class Solution {
public:
  int fib(int n) {
    std::vector<int> cache{0, 1};
    for (int i = 2; i <= n; ++i) {
      cache.push_back(cache[i - 1] + cache[i - 2]);
    }

    return cache[n];
  }
};
