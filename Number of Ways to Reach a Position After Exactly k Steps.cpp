// class Solution {
// public:
//     const int MOD = 1e9 + 7;
//     int solve1( int ep, int k, int step, int pos )
//     {
//         if(step > k)
//             return 0;

//         if(step == k && pos == ep)
//         {
//             return 1;
//         }
//         int left = solve1( ep, k, step+1, pos-1 );
//         int right = solve1( ep, k, step+1, pos+1 );

//         return left + right;

//     }

//     unordered_map<string, int> m;
//     int solve2( int ep, int k, int step, int pos )
//     {
//         if(step > k)
//             return 0;

//         if(step == k && pos == ep)
//             return 1;

//         string key = to_string(pos) + "_" + to_string(step);

//         if(m.find(key) != m.end())
//             return m[key];

//         int left = (solve2( ep, k, step+1, pos-1 )) % MOD;
//         int right = (solve2( ep, k, step+1, pos+1 )) % MOD;

//         return m[key] = (left + right) % MOD;
//     }

//     int numberOfWays(int startPos, int endPos, int k) {
//         return solve2( endPos, k, 0, startPos);
//     }
// };

class Solution
{
public:
    int dp[3005][1005];

    long long mod = 1e9 + 7;

    int dfs(int start, int end, int k)
    {
        if (k == 0)
        {
            if (start == end)
                return 1;
            else
                return 0;
        }

        if (dp[start + 1000][k] != -1)
            return dp[start + 1000][k];

        long long ways = 0;

        ways = (ways % mod + dfs(start - 1, end, k - 1) % mod) % mod;
        ways = (ways % mod + dfs(start + 1, end, k - 1) % mod) % mod;

        return dp[start + 1000][k] = ways;
    }

    int numberOfWays(int startPos, int endPos, int k)
    {

        memset(dp, -1, sizeof(dp));

        return dfs(startPos, endPos, k);
    }
};