class Solution
{
public:
    vector<int> solve5(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> hash(n, 0);

        int maxi = 0, lastind = -1;

        for (int i = 0; i < n; i++)
        {
            hash[i] = i;
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0 && dp[i] < 1 + dp[j])
                {
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
            if (dp[i] > maxi)
            {
                maxi = dp[i];
                lastind = i;
            }
        }

        // cout<<lastind<<endl;

        vector<int> ans;
        ans.push_back(nums[lastind]);

        while (hash[lastind] != lastind)
        {
            lastind = hash[lastind];
            ans.push_back(nums[lastind]);
        }

        // reverse(ans.begin(),ans.end());
        return ans;
    }
    vector<int> ans;
    void solve1(vector<int> &nums, int ind, int prev, vector<int> &temp)
    {
        if (ind >= nums.size())
        {
            if (temp.size() > ans.size())
            {
                ans = temp;
            }
            return;
        }

        if (prev == INT_MIN || nums[ind] % prev == 0)
        {
            temp.push_back(nums[ind]);
            solve1(nums, ind + 1, nums[ind], temp);
            temp.pop_back();
        }

        solve1(nums, ind + 1, prev, temp);
    }
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        // return solve5(nums);

        vector<int> temp;
        solve1(nums, 0, INT_MIN, temp);
        return ans;
    }
};