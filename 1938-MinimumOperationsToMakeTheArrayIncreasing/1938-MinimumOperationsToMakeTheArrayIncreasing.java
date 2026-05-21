// Last updated: 5/20/2026, 11:36:00 PM
class Solution {
    public static int minOperations(int[] nums) {

        int[] ans=new int[nums.length];

        if(nums.length == 0 || nums.length == 1){
            return 0;
        }


        int count=0;
        for(int numsValue : nums ){
            ans[count]=numsValue;
            count++;
        }


        for(int i= 1;  i < nums.length ; i++ ){
            if(nums[i] <= nums[i-1]){
                nums[i]=nums[i-1]+1;

            }
        }

        int diffCount=0;
        for(int i= 0 ; i< ans.length ; i++){
            diffCount=diffCount+nums[i]-ans[i];
        }

        return diffCount;



    }
}