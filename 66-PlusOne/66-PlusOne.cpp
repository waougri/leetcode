// Last updated: 5/20/2026, 11:37:39 PM
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Start from the least significant digit
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                // If the digit is less than 9, we can simply increment it and return
                digits[i]++;
                return digits;
            }
            // If the digit is 9, set it to 0 and continue to the next digit
            digits[i] = 0;
        }
        
        // If we're here, it means all digits were 9
        vector<int> result(n + 1, 0);
        result[0] = 1;
        return result;
    }
};