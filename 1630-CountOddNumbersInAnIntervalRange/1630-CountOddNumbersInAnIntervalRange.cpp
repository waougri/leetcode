// Last updated: 5/20/2026, 11:36:11 PM
class Solution {
public:
    int countOdds(int low, int high) {
        int nums = high - low + 1;
        if (low % 2 == 0 || high % 2 == 0)
            return nums / 2;
        return (nums / 2) + 1;
    }
};