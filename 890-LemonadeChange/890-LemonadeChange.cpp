// Last updated: 5/20/2026, 11:36:32 PM
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    enum Change : int { FIVE = 5, TEN = 10, TWENTY = 20 };

    bool lemonadeChange(vector<int> &bills) {
        // Initialize the map to track the number of 5s and 10s
        unordered_map<int, int> change{{FIVE, 0}, {TEN, 0}};
        
        // Iterate over each bill in the vector
        for (int bill : bills) {
            if (bill == FIVE) {
                ++change[FIVE];
            } else if (bill == TEN) {
                // Check if we can give change for 10
                if (change[FIVE] > 0) {
                    --change[FIVE];
                    ++change[TEN];
                } else {
                    return false;  // Not enough 5s to provide change for 10
                }
            } else if (bill == TWENTY) {
                // Check if we can give change for 20
                if (change[FIVE] >= 1 && change[TEN] >= 1) {
                    --change[FIVE];
                    --change[TEN];
                } else if (change[FIVE] >= 3) {
                    change[FIVE] -= 3;
                } else {
                    return false;  // Not enough change to provide for 20
                }
            }
        }
        
        return true;  // All bills processed successfully
    }
};
