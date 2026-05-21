// Last updated: 5/20/2026, 11:35:52 PM
var arithmeticTriplets = function(nums, diff) {
  let counter = 0

  for (let i = 0; i < nums.length; i++) {
    for (let j = 1; j < nums.length; j++) {
      for (let k = 2; k < nums.length; k++) {
        if (nums[j] - nums[i] == diff && nums[k] - nums[j] == diff) counter++
      }
    }
  }

  return counter
};