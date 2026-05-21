// Last updated: 5/20/2026, 11:37:44 PM
#include <string>
#include <sstream>
#include <vector>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        std::istringstream iss(s);
        std::string word;
        std::vector<std::string> words;

        while (iss >> word) {
            words.push_back(word);
        }

        return words.empty() ? 0 : words.back().length();
    }
};
