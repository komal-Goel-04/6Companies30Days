class Solution
{
public:
    int numFriendRequests(vector<int> &ages)
    {
        vector<int> age(120 + 1, 0);

        for (int i = 0; i < ages.size(); i++)
            age[ages[i]]++;

        int ans = 0;

        for (int i = 120; i > 0; i--)
        {
            for (int j = i; j > 0; j--)
            {
                if (age[j] == 0)
                    continue;
                if (j <= 0.5 * i + 7)
                    continue;

                ans += age[i] * age[j];
                if (i == j)
                    ans -= age[i];
            }
        }
        return ans;
    }
};