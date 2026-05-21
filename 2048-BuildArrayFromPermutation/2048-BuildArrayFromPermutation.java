// Last updated: 5/20/2026, 11:35:55 PM
class Solution {
    public int[] buildArray(int[] nums) {
        int[] ans = new int[nums.length];
        for( int i = 0; i < nums.length; i++){
            ans[i] = nums[nums[i]];
            
        }

        return ans;
    }
}