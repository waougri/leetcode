// Last updated: 5/20/2026, 11:37:58 PM
class Solution {
  List<int> twoSum(List<int> nums, int target) {
    // Create a list of pairs (value, original index)
    List<MapEntry<int, int>> indexedNums = [];
    for (int i = 0; i < nums.length; ++i) {
      indexedNums.add(MapEntry(nums[i], i));
    }

    // Sort the indexedNums by the values (nums[i])
    indexedNums.sort((a, b) => a.key.compareTo(b.key));

    int left = 0;
    int right = indexedNums.length - 1;

    while (left < right) {
      int sum = indexedNums[left].key + indexedNums[right].key;
      if (sum == target) {
        // Return the original indices
        return [indexedNums[left].value, indexedNums[right].value];
      } else if (sum < target) {
        left++;
      } else {
        right--;
      }
    }
    return []; // No solution found
  }
}
