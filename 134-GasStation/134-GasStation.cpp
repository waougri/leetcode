// Last updated: 5/20/2026, 11:37:29 PM
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = std::size(gas);
        gas.insert(gas.end(), gas.begin(), gas.end());
        cost.insert(cost.end(), cost.begin(), cost.end());

        int start = 0, curr = 0;

        for (int i = start; i < n * 2; ++i) {
            curr += gas[i] - cost[i];

            if (curr < 0) {
                curr = 0;
                start = i + 1;
            }
            if (i == (n + start)) {
                return start;
            }
        }

        return -1;
    }
};