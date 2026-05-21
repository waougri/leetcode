// Last updated: 5/20/2026, 11:37:36 PM
class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int count{};
    while (count != n) {
      nums1.pop_back();
      ++count;
    }

    for (const auto &i : nums2) {
      nums1.push_back(i);
    }

    std::sort(nums1.begin(), nums1.end());
  }
};