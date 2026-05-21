// Last updated: 5/20/2026, 11:36:15 PM

#include <vector>
class Solution {
    public:
        int kthFactor(int n, int k) {

            std::vector<int> vec;

            for(int i = 1; i <= n; i++)
            {
                if (n % i == 0)
                {
                    vec.push_back(i);
                }
            }

            if(vec.size() < k)
            {
                return -1;
            }
            
            return vec[k - 1];

        }
};


