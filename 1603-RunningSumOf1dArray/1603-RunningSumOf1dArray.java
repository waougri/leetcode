// Last updated: 5/20/2026, 11:36:14 PM
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Stack;
class Solution {
    public static int[] runningSum(int[] nums){
        int[] runningSum = new int[nums.length];
        runningSum[0]= nums[0];
        for(int i = 1; i < nums.length; i++){
            runningSum[i] = runningSum[i-1] + nums[i];
        }
        return runningSum;
        }
}