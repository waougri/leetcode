// Last updated: 5/20/2026, 11:36:12 PM
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int> &arr) {
   
std::sort(arr.begin(), arr.end());
    int difference = arr[1] - arr[0];

    for (int i = 1; i < std::size(arr) - 1; ++i) {
      if (arr[i + 1] - arr[i] != difference) {
        return false;
      }
    }

    return true;
  }

};