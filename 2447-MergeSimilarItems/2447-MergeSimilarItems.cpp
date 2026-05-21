// Last updated: 5/20/2026, 11:35:51 PM
#include <algorithm>
#include <unordered_map>
#include <vector>
using std::vector;

class Solution {
public:
  vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1,
                                        vector<vector<int>> &items2) {

    auto map = std::unordered_map<int, int>{};
    auto res = std::vector<vector<int>>{};

    for (const auto &entry : items1) {
      map[entry[0]] += entry[1];
    }

    for (const auto &entry : items2) {
      map[entry[0]] += entry[1];
    }

    for (const auto &[k, v] : map) {
      res.emplace_back(std::vector{k, v});
    }
    
    std::sort(res.begin(), res.end());
    return res;
  }
};
