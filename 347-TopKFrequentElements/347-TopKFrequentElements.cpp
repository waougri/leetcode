// Last updated: 5/20/2026, 11:36:46 PM
class Solution {
  using vec_t = std::vector<std::pair<int, int>>;
  using histogram_t = std::map<int, int, std::greater<>>;

public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
        #pragma GCC optimize("Ofast")
        #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
        #pragma GCC optimize("unroll-loops")
    

    std::vector<int> frequent{};

    histogram_t hist{};

    vec_t r_vec{};

    for (const auto &n : nums) {
      ++hist[n];
    }

    int counter{1};

    for (const auto &[k, v] : hist) {
      r_vec.emplace_back(std::pair{k, v});
    }

    std::sort(std::begin(r_vec), std::end(r_vec),
              [](auto &l, auto &r) { return l.second > r.second; });

    for (vec_t::iterator it = std::begin(r_vec);
         it != std::end(r_vec) && counter <= k; ++it, ++counter) {
      frequent.push_back(it->first);
    }
    return frequent;
  }
};