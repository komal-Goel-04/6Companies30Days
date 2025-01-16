class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int j = 0, ans = 0, cookies = s.size();

        for (int i = 0; i < g.size(); i)
        {
            if (j >= cookies)
                break;
            if (s[j] >= g[i])
            {
                j++;
                i++;
                ans++;
            }
            else
                j++;
        }
        return ans;
    }
};