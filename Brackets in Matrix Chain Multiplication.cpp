class Solution
{
public:
    map<pair<int, int>, int> m;
    int solve2(vector<int> &arr, int i, int j, vector<vector<int>> &dp)
    {
        if (i == j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int mini = INT_MAX;

        for (int k = i; k < j; k++)
        {
            int ans = solve2(arr, i, k, dp) + solve2(arr, k + 1, j, dp) + arr[i - 1] * arr[k] * arr[j];
            if (mini > ans)
                m[{i, j}] = k;
            mini = min(mini, ans);
        }
        return dp[i][j] = mini;
    }

    void buildOrder(int i, int j, string &result)
    {
        if (i == j)
        {
            // Append the next matrix letter (A, B, C, ...)
            result += char('A' + (i - 1));
            return;
        }

        int k = m[{i, j}];            // Get the split point
        result += "(";                // Open a bracket
        buildOrder(i, k, result);     // Solve for the left half
        buildOrder(k + 1, j, result); // Solve for the right half
        result += ")";                // Close the bracket
    }
    string matrixChainOrder(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        solve2(arr, 1, n - 1, dp);

        string result = "";
        buildOrder(1, n - 1, result); // Construct the bracketed order
        return result;
    }
};