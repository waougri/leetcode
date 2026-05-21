// Last updated: 5/20/2026, 11:37:31 PM
/*
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function (nums) {
    if(nums.length === 0) return 0;
    let longestStreak = 1;
    nums.sort((a, b) => a - b);
    let current = 1;
    for (let i = 0; i < nums.length - 1; ++i) {
        if (nums[i] === nums[i + 1]) continue;
        if (nums[i + 1] - nums[i] === 1) {
            ++current;
        } else {
            longestStreak = Math.max(longestStreak, current);
            current = 1;
        }
    }

    longestStreak = Math.max(longestStreak, current);
    return longestStreak;
};


