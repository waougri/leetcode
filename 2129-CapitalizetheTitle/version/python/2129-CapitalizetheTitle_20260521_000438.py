# Last updated: 5/21/2026, 12:04:38 AM
1class Solution(object):
2    def capitalizeTitle(self, title):
3        """
4        :type title: str
5        :rtype: str
6        """
7        return " ".join([word.lower() if len(word) <= 2 else word.capitalize() for word in title.split()])