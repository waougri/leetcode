// Last updated: 5/20/2026, 11:36:47 PM
class Solution {
public:
    void moveZeroes(std::vector<int>& nums)
{
    if (nums.size() == 1)
    {
        return;
    }

    auto count = std::count(nums.begin(), nums.end(), 0);

    auto rem = std::remove(nums.begin(), nums.end(), 0);
    nums = std::vector<int>{nums.begin(), rem};
    for(int i = 0; i < count; ++i)
    {
        nums.push_back(0);
    }

}
};