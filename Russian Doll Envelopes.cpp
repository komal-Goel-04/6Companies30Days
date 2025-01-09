class Solution
{
public:
    int ans = 0;
    void solve1(vector<vector<int>> &nums, int ind, int prev, int length)
    {
        if (ind >= nums.size())
        {
            ans = max(ans, length);
            return;
        }

        if (prev == INT_MIN || (nums[ind][0] > nums[prev][0] && nums[ind][1] > nums[prev][1]))
            solve1(nums, ind + 1, ind, length + 1);

        solve1(nums, ind + 1, prev, length);
    }

    int solve2(vector<vector<int>> &nums, vector<vector<int>> &dp, int ind, int prevind)
    {
        if (ind >= nums.size())
            return 0;

        if (dp[ind][prevind + 1] != -1)
            return dp[ind][prevind + 1];

        int include = 0;
        if (prevind == -1 || (nums[ind][0] > nums[prevind][0] && nums[ind][1] > nums[prevind][1]))
            include = 1 + solve2(nums, dp, ind + 1, ind);

        int exclude = solve2(nums, dp, ind + 1, prevind);

        return dp[ind][prevind + 1] = max(include, exclude);
    }

    int solve3(vector<vector<int>> &nums)
    {
        int size = nums.size();

        vector<vector<int>> dp(size + 1, vector<int>(size + 1, 0));

        for (int ind = size - 1; ind >= 0; ind--)
        {
            for (int prevind = ind - 1; prevind >= -1; prevind--)
            {
                int include = 0;
                if (prevind == -1 || (nums[ind][0] > nums[prevind][0] && nums[ind][1] > nums[prevind][1]))
                    include = 1 + dp[ind + 1][ind + 1];

                int exclude = dp[ind + 1][prevind + 1];

                dp[ind][prevind + 1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }

    int solve4(vector<vector<int>> &nums)
    {
        int size = nums.size();

        vector<int> dp(size + 1, 0);

        for (int ind = size - 1; ind >= 0; ind--)
        {
            vector<int> temp(size + 1, 0); // Temporary DP array for the current row
            for (int prevind = ind - 1; prevind >= -1; prevind--)
            {
                int include = 0;
                if (prevind == -1 || (nums[ind][0] > nums[prevind][0] && nums[ind][1] > nums[prevind][1]))
                    include = 1 + dp[ind + 1];

                int exclude = dp[prevind + 1];

                temp[prevind + 1] = max(include, exclude);
            }
            dp = temp; // Update DP array with current row values
        }
        return dp[0];
    }

    int solveoptimal(int n, vector<vector<int>> &nums)
    {
        if (n == 0)
            return 0;

        vector<int> ans;
        ans.push_back(nums[0][1]);

        for (int i = 1; i < n; i++)
        {
            if (nums[i][1] > ans.back())
                ans.push_back(nums[i][1]);
            else
            {
                int index = lower_bound(ans.begin(), ans.end(), nums[i][1]) - ans.begin();
                ans[index] = nums[i][1];
            }
        }
        return ans.size();
    }

    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }

    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        sort(envelopes.begin(), envelopes.end(), cmp);

        // solve1(envelopes, 0, INT_MIN, 0);
        // return ans;

        // int size = envelopes.size();

        // vector<vector<int>> dp(size+1, vector<int>(size+1, -1));
        // return solve2(envelopes, dp, 0, -1);

        // return solve4(envelopes);

        return solveoptimal(envelopes.size(), envelopes);
    }
};