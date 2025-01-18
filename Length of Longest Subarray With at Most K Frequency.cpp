class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int l = 0, r = 0, ans = 0;

        for (l = 0, r = 0; r < nums.size(); r++)
        {
            mp[nums[r]]++;

            if (mp[nums[r]] > k)
            {
                while (nums[l] != nums[r])
                {
                    mp[nums[l]]--;
                    l++;
                }
                mp[nums[l]]--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};