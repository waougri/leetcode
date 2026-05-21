# Last updated: 5/20/2026, 11:36:46 PM
class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split();
        if(len(words) != len(pattern)):
            return False;

        pattern_mappings = {}
        for i, c in enumerate(pattern):
            if(c not in pattern_mappings):
                if(words[i] in pattern_mappings.values()):
                    return False
                pattern_mappings[c] = words[i]
            elif (words[i] != pattern_mappings[c]):
                return False;


        for i, c in enumerate(pattern):
            word = words[i]
            if(word not in pattern_mappings.values()):
                return False
            if(words[i] != pattern_mappings[c]):
                return False;

        return True



