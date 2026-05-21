// Last updated: 5/20/2026, 11:36:36 PM
class Solution {
    public int pivotIndex(int[] nums) {
        int sum = 0, leftsum = 0;
            sum = Arrays.stream(nums).sum();
            for (int i = 0; i < nums.length; ++i) {
                if (leftsum == sum - leftsum - nums[i]) return i;
                leftsum += nums[i];
            }
            return -1;
    }
}