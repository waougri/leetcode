// Last updated: 5/20/2026, 11:35:58 PM
#include <cmath>
#include <vector>
using std::vector;

class Solution {
public:
    double dist (int x1, int y1, int x2, int y2) {
        return std::sqrt(std::pow((x2 - x1), 2) + std::pow((y2 - y1), 2));
    }
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        std::vector<int> res(queries.size(), 0);
        int idx = 0;
        for (const auto& query : queries) {
            for(const auto& point : points) {
                if (dist(query[0], query[1], point[0], point[1]) <= static_cast<double>(query[2])) {
                    res[idx]++;
                }
            }
            idx++;
        }

        return res;
    }
};