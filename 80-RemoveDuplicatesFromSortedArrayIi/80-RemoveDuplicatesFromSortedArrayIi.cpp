// Last updated: 5/20/2026, 11:37:37 PM

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int n = nums.size();
    if (n <= 2) {
      return n;
    }

    int index = 2; // Start from the third element
    for (int i = 2; i < n; ++i) {
      if (nums[i] != nums[index - 2]) {
        nums[index++] = nums[i];
      }
    }

    nums.resize(index);
    return index;
  }
}

;
