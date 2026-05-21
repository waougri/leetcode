// Last updated: 5/20/2026, 11:36:20 PM
int f_nnbridx(std::vector<int>& vec) {
    unsigned long size = vec.size();
    unsigned long lo = 0, hi = size - 1;
    unsigned long m = lo + (hi - lo) / 2;

    while (lo <= hi) {
        if (vec[m] >= 0) {
            lo = m + 1;
        } else if (vec[m] < 0) {
            if (m == 0 || vec[m - 1] >= 0) {
                return m;
            } else {
                hi = m - 1;
            }
        }
        m = lo + (hi - lo) / 2;
    }

    return -1;
}


class Solution {
public:
  unsigned long countNegatives(vector<vector<int>>& grid) {
    unsigned long count = 0;

    for (auto& row : grid) {
        int nnidx = f_nnbridx(row);
        if (nnidx == 0) {
            count += row.size();
        } else if (nnidx != -1) {
            count += (row.size() - nnidx);
        }
    }

    return count;
}

}; 
