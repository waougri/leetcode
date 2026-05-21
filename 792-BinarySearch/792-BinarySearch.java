// Last updated: 5/20/2026, 11:36:40 PM
class Solution {
    public int search(int[] nums, int target) {
        int lo = 0, hi = nums.length - 1;
    // This below check covers all cases , so need to check
    // for mid=lo-(hi-lo)/2
    while (hi - lo > 1) {
        int mid = (hi + lo) / 2;
        if (nums[mid] < target) {
            lo = mid + 1;
        }
        else {
            hi = mid;
        }
    }
    if (nums[lo] == target) {
        return lo;
    }
    else if (nums[hi] == target) {
        return hi;
    }
    else {
        return -1;
    }
    
    }
}