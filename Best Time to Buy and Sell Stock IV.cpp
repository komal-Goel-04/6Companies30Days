class Solution
{
public:
    int solve1(vector<int> &prices, int n, bool buy, int cap)
    {
        if (n >= prices.size())
            return 0;
        if (cap < 0)
            return 0;

        int profit = INT_MIN;
        if (buy)
            return profit = max(-prices[n] + solve1(prices, n + 1, !buy, cap), solve1(prices, n + 1, buy, cap));
        else
            return profit = max(prices[n] + solve1(prices, n + 1, true, cap - 1), solve1(prices, n + 1, false, cap));
    }

    int solve2(vector<int> &prices, int n, bool buy, int cap, vector<vector<vector<int>>> &dp)
    {
        if (n >= prices.size())
            return 0;
        if (cap == 0)
            return 0;

        if (dp[n][buy][cap] != -1)
            return dp[n][buy][cap];

        int profit = INT_MIN;
        if (buy)
            return dp[n][buy][cap] = max(-prices[n] + solve2(prices, n + 1, !buy, cap, dp), solve2(prices, n + 1, buy, cap, dp));
        else
            return dp[n][buy][cap] = max(prices[n] + solve2(prices, n + 1, true, cap - 1, dp), solve2(prices, n + 1, false, cap, dp));
    }

    int solve3(vector<int> &prices, int k)
    {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 1; j >= 0; j--)
            {
                for (int x = 1; x < k + 1; x++)
                {
                    int profit = INT_MIN;
                    if (j)
                        dp[i][j][x] = max(-prices[i] + dp[i + 1][0][x], dp[i + 1][1][x]);
                    else
                        dp[i][j][x] = max(prices[i] + dp[i + 1][1][x - 1], dp[i + 1][0][x]);
                }
            }
        }
        return dp[0][1][k];
    }

    int solve4(vector<int> &prices, int k)
    {
        int n = prices.size();

        vector<vector<int>> prev(2, vector<int>(k + 1, 0));
        vector<vector<int>> curr(2, vector<int>(k + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 1; j >= 0; j--)
            {
                for (int x = 1; x < k + 1; x++)
                {
                    int profit = INT_MIN;
                    if (j)
                        curr[j][x] = max(-prices[i] + prev[0][x], prev[1][x]);
                    else
                        curr[j][x] = max(prices[i] + prev[1][x - 1], prev[0][x]);
                }
            }
            prev = curr;
        }
        return prev[1][k];
    }

    int maxProfit(int k, vector<int> &prices)
    {
        // return solve1(prices, 0, 1, k-1);

        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return solve2(prices, 0, 1, k, dp);

        // return solve4(prices, k);
    }
};