class Solution
{
public:
    map<string, bool> m;
    int n;
    int solve(string s)
    {
        if (s.length() == 0)
            return 0;

        int exclude = 1 + solve(s.substr(1));
        int i = 0, j = 0, include = INT_MAX;
        while (j < s.length())
        {
            string temp = s.substr(i, j - i + 1);
            if (m[temp] == true)
                include = min(include, solve(s.substr(j + 1)));

            j++;
        }
        return min(include, exclude);
    }

    int solve2(int i, string &s, vector<int> &dp)
    {
        if (i >= n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int exclude = 1 + solve2(i + 1, s, dp);
        int j = i, include = INT_MAX;
        while (j < s.length())
        {
            string temp = s.substr(i, j - i + 1);
            if (m[temp] == true)
                include = min(include, solve2(j + 1, s, dp));

            j++;
        }
        return dp[i] = min(include, exclude);
    }

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

    int minExtraChar(string s, vector<string> &dictionary)
    {
        for (auto i : dictionary)
            m[i] = true;

        // n = s.length();

        // return solve(s);

        // vector<int> dp(n, -1);
        // return solve2(0, s, dp);

        return solve3(s);
    }
};