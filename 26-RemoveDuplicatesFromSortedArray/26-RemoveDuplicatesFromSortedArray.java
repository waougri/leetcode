// Last updated: 5/20/2026, 11:37:50 PM
import java.util.Arrays;
import java.util.HashSet;

class Solution {
    public int removeDuplicates(int[] nums) {
       if (nums.length == 0) {
            return 0;
        }

        int uniqueCount = 1; // At least the first element is unique

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != nums[i - 1]) {
                nums[uniqueCount] = nums[i];
                uniqueCount++;
            }
        }

        return uniqueCount;
    }
}
