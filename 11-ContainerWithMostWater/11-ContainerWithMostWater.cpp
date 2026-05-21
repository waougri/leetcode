// Last updated: 5/20/2026, 11:37:54 PM
#include <algorithm>
#include <cstdio>
#include <vector>
using std::vector;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;

        while (left < right) {

            max_area =
                std::max(max_area,
                         std::min(height[left], height[right]) * (right -  left));

            if (height[left] > height[right]) {
                --right;
            } else {
                ++left;
            }
        }

        return max_area;
    }
};
