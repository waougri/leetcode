// Last updated: 5/20/2026, 11:37:34 PM


class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    if(nums.empty()) return 0;
    std::sort(nums.begin(), nums.end());
    int maxlen{};
    int currentLen{1};
    for(int i = 1; i < nums.size(); ++i) {
        if(nums[i - 1] == nums[i]) {
            continue;
        }
        if(nums[i] == nums[i - 1] + 1) {
            currentLen++;
        } else {
            maxlen = std::max(maxlen, currentLen);
            currentLen = 1;
        }
    }
    maxlen = std::max(maxlen, currentLen);
    return maxlen;
  }
};