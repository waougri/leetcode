// Last updated: 5/20/2026, 11:36:01 PM
class Solution {
    public static int arraySign(int[] nums) {
        int product = 1;
        int sign = nums.length;
        for (int i = 0; i < nums.length; i++) {
            if(nums[i] > 0){
                nums[i] = 1;
            }
            else if (nums[i] < 0) {
                nums[i] = -1;
            }
            else if(nums[i] == 0){
                return 0;
            }
        }
        System.out.println(nums);

        for (int j = 0; j < nums.length; j++) {
            product *= nums[j];
        }

        if (product > 0) {
            sign = 1;
        }
        else if (product == 0) {
            sign = 0;
        }
        else if(product < 0){
            sign = -1;
        }



        return sign;
    }
public static void main(String[] args) {
    int[] nums = {41,65,14,80,20,10,55,58,24,56,28,86,96,10,3,84,4,41,13,32,42,43,83,78,82,70,15,-41};
    System.out.println(arraySign(nums));
}
    
}