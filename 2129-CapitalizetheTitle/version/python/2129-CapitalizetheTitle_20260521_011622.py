# Last updated: 5/21/2026, 1:16:22 AM
1import json
2class Solution(object):
3    def hist(self, string):
4        hist = defaultdict(int)
5
6        for letter in string:
7            hist[letter] += 1
8        return hist
9
10    def rearrangeCharacters(self, s, target):
11        """
12        :type s: str
13        :type target: str
14        :rtype: int
15        """
16        shist = self.hist(s)
17        thist = self.hist(target)
18
19        
20        copies = 0
21        # if any target letter isnt in the items.
22        for key, val in thist.items():
23            if key not in thist or (val > shist[key]):
24                return 0
25        lhist = defaultdict(int)
26        for tletter, tval in thist.items():
27            # print(tletter, tval)
28            while( tval <= shist[tletter]):
29                shist[tletter] -= tval
30                lhist[tletter] += 1
31            
32        # print(json.dumps(shist, indent=2))
33        # print(json.dumps(thist, indent=2))
34        # print(json.dumps(lhist, indent=2))
35
36        return lhist[min(lhist, key=lhist.get)]