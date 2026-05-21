// Last updated: 5/20/2026, 11:37:56 PM
#include <cmath>
#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
  static double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    vector<int> vec;

    vec.reserve(nums1.size() + nums2.size());
    for (int i = 0 ; i < nums1.size(); i++) {
        vec.push_back(nums1[i]);
    }
    for (int i = 0 ; i < nums2.size(); i++) {
        vec.push_back(nums2[i]);
    }
    int n = (vec.size() - 1) / 2;
    
    double med;
    std::sort(vec.begin(), vec.end());

    if(vec.size() % 2 != 0) {
        med = vec[n]; 
    } else {
      
        med = (vec[n] + vec[n + 1]) / 2.0;
    }

    return med;
  }
};