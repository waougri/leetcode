// Last updated: 5/20/2026, 11:36:18 PM
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
       vector<int> vec;
       int ctr = 0;

       for(size_t i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < nums.size(); j++) {
            if(nums[i] > nums[j]){
                ctr++;
            }
        }
        vec.push_back(ctr);
        ctr = 0;
       }



       return vec ;
    }

};