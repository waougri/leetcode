# Last updated: 5/20/2026, 11:37:46 PM
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        return len(s.strip().split(" ")[-1])
