# Last updated: 5/21/2026, 12:01:57 AM
# It's Python, so just use your head.
1class Solution(object):
2    def capitalizeTitle(self, title):
3        """
4        :type title: str
5        :rtype: str
6        """
7
8
9        splitted = title.split(" ")
10        result = ""
11
12        for word in splitted:
13            if len(word) <=2:
14                result += word.lower()
15            else:
16                result += word.capitalize()
17            
18            result += " "
19
20
21        return result.strip()