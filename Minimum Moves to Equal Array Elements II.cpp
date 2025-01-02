class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int add = 0;

        int median = nums[nums.size() / 2];

        for (int i = 0; i < nums.size(); i++)
        {
            add += abs(nums[i] - median);
        }

        return add;
    }
};