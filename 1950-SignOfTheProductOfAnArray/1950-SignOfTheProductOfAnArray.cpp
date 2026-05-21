// Last updated: 5/20/2026, 11:35:59 PM
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int negatives{}, positives{};
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0)
                return 0;
            if (nums[i] > 0)
                ++positives;
            if (nums[i] < 0)
                ++negatives;
        }

        if (!(negatives % 2)) {
            return 1;
        } else {
            return -1;
        }

        return 1;
    }
};