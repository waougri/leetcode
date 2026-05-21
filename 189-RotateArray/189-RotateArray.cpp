// Last updated: 5/20/2026, 11:37:27 PM
/**
 * @file 189rotate_array.cpp
 * @author iustus (lindgreiae@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-23
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <vector>
using std::vector;

class Solution {
public:
  void rotate(vector<int> &nums, int k) {
k=k%nums.size();
        reverse(nums.begin(),nums.begin()+(nums.size()-k));

        reverse(nums.begin()+(nums.size()-k),nums.end());
    
        reverse(nums.begin(),nums.end());
            
  }
};
