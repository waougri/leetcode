# Last updated: 5/21/2026, 12:35:20 AM
1class Solution(object):
2    def resultArray(self, nums):
3        """
4        :type nums: List[int]
5        :rtype: List[int]
6        """
7        n1 = [nums[0]]
8        n2 = [nums[1]]
9        for i in range (2, len(nums)):
10            if n1[-1] > n2[-1]:
11                n1.append(nums[i])
12            else:
13                n2.append(nums[i])
14        return n1 + n2        