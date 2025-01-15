class Solution
{
public:
    map<string, bool> m;
    int solve3(string &s)
    {
        int n = s.length();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            int exclude = 1 + dp[i + 1];
            int j = i, include = INT_MAX;
            while (j < s.length())
            {
                string temp = s.substr(i, j - i + 1);
                if (m[temp] == true)
                    include = min(include, dp[j + 1]);

                j++;
            }
            dp[i] = min(include, exclude);
        }
        return dp[0];
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        for (auto i : wordDict)
            m[i] = true;

        if (solve3(s) > 0)
            return false;

        return true;
    }
};