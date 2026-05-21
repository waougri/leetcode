// Last updated: 5/20/2026, 11:37:24 PM
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                result.push_back(left + 1);
                result.push_back(right + 1);
                return result;
            } else if (sum < target) {
                ++left;
            } else {
                --right;
            }
        }

        return result;
    }
};