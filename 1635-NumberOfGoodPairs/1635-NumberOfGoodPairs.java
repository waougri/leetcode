// Last updated: 5/20/2026, 11:36:10 PM
class Solution {
    public int numIdenticalPairs(int[] nums) {
        int goodPairCounter = 0;
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] == nums[j] && i < j){
                    goodPairCounter++;
                }
                else{
                    continue;
                }
            }
        }





        return goodPairCounter;
    }
}