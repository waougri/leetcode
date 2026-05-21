// Last updated: 5/20/2026, 11:36:02 PM
class Solution {
public:
    string mergeEqualSizedWords(const string& word1, const string& word2) {
        std::ostringstream oss{};
        for (int i = 0; i < word1.size(); ++i) {
            oss << word1.at(i);
            oss << word2.at(i);
        }
        return oss.str();
    }

    string mergeNonEqualSizedWords(const string& word1, const string& word2) {
        std::ostringstream oss{};
        std::string::size_type size =
            word1.size() < word2.size() ? word1.size() : word2.size();

        for (int i = 0; i < size; ++i) {
            oss << word1.at(i);
            oss << word2.at(i);
        }

        const auto word = word1.size() >  word2.size() ? word1 : word2;

        for (int i = 0; i < word.size() - size; ++i) {
            oss << word.at(i + size);
        }

        return oss.str();
    }

    string mergeAlternately(string word1, string word2) {
        return word1.size() == word2.size()
                   ? mergeEqualSizedWords(word1, word2)
                   : mergeNonEqualSizedWords(word1, word2);
    }
};