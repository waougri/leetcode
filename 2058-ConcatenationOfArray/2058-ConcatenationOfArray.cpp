// Last updated: 5/20/2026, 11:35:55 PM
#include <algorithm>
#include <vector>

using std::vector;

class Solution {
    public:
        vector<int> getConcatenation(vector<int>& nums) {
            vector<int> n;
            n.reserve(2 * nums.size());
            n.insert(n.end(), nums.begin(), nums.end());
            n.insert(n.end(), nums.begin(), nums.end());

            return n;
        }
};



