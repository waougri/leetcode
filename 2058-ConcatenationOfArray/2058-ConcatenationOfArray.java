// Last updated: 5/20/2026, 11:35:57 PM
class Solution {
    public int[] getConcatenation(int[] nums) {
        int[] ans = new int[2 * nums.length];
        for(int i =0; i < nums.length; i++){
            ans[i] = ans[i+ nums.length] = nums[i];
        }
        return ans;
    }
}