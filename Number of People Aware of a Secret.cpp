class Solution
{
public:
    const int MOD = 1e9 + 7;
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        vector<int> knownat(n + forget, 0);
        knownat[1] = 1;
        int ans = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = i + delay; j < i + forget; j++)
            {
                knownat[j] = (knownat[j] + knownat[i]) % MOD;
            }
        }

        for (int i = n; i > n - forget; i--)
            ans = (ans + knownat[i]) % MOD;

        return ans;
    }
};