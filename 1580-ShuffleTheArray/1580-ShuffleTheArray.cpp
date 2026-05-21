// Last updated: 5/20/2026, 11:36:16 PM
#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        vector<int> vec;
        vec.reserve(n);
        vector<int> shuffed;
        shuffed.reserve(2 * n);

        std::copy(std::begin(nums) + n, 
                    std::end(nums), 
                    std::begin(vec));

        for(int i = 0; i < n; i += 1) {
            shuffed.push_back(nums[i]);
            shuffed.push_back(vec[i]);
        }

        return shuffed;

    }
};
