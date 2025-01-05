class Solution
{
public:
    int solve2(vector<int> &nums, int k)
    {
        map<int, int> m;
        int sum = 0, ans = 0;

        m[0] = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 != 0)
                sum++;

            if (m.find(sum - k) != m.end())
                ans += m[sum - k];

            m[sum]++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        return solve2(nums, k);
    }
};