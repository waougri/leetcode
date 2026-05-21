# Last updated: 5/21/2026, 12:05:45 AM
class Solution(object):
    def capitalizeTitle(self, title):
        """
        :type title: str
        :rtype: str
        """
        return " ".join([word.lower() if len(word) <= 2 else word.capitalize() for word in title.split()])