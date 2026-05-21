// Last updated: 5/20/2026, 11:36:17 PM
class Solution {
public:
   double average(vector<int> &salary) {

    int max = *std::max_element(salary.begin(), salary.end());
    int min = *std::min_element(salary.begin(), salary.end());
    int sum = std::accumulate(salary.begin(), salary.end(), 0,
                              [](int acc, int i) { return i + acc; });

    return (sum - (min + max)) / static_cast<double>(salary.size() - 2);
  }

};
