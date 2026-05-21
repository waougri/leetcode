// Last updated: 5/20/2026, 11:38:00 PM
class Solution {
    void putIntoHash(int[] nums, HashMap<Integer, Integer> hs){
        for (int i = 0; i < nums.length; i++) {
            hs.put(nums[i], i);
        }
    }
    public int[] twoSum(int[] nums, int target) {
        

        HashMap<Integer, Integer> hm = new HashMap<>(nums.length);
        putIntoHash(nums, hm);
        
        
        
        
        
        
        for (int i = 0; i < nums.length; i++) {
            if (hm.containsKey(target - nums[i]) && hm.get(target - nums[i]) != i){
                return new int[]{i,  hm.get(target - nums[i])};
            }
        }

        return new int[]{-1, -1};
    }


}