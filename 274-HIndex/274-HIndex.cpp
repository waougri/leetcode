// Last updated: 5/20/2026, 11:36:49 PM
class Solution {
public:
 static void print_vec(const std::vector<int> &v) {
        for (const auto &i: v) {
            printf("%i ", i);
        }
        printf("\n");
    }
    int hIndex(vector<int>& arr) {

        int n = arr.size();
        sort(arr.begin(), arr.end());
        print_vec(arr);
        if (arr[0] >= n)
            return n;
        if (n == 1)
            return !(arr[0] == 0);
        for (int i = 0; i < n; i++) {
            int left = n - i;
            if (arr[i] >= left)
                return left;
        }
        return 0;
    }
};