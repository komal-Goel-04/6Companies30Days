class Solution
{
public:
    map<int, map<vector<int>, int>> m;
    int solve(int ind, vector<int> ds, vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
    {
        if (ind == special.size())
        {
            int tot = 0;
            for (int i = 0; i < needs.size(); i++)
                tot += (needs[i] - ds[i]) * price[i];

            return tot;
        }

        if (m.find(ind) != m.end() && m[ind].find(ds) != m[ind].end())
            return m[ind][ds];

        int nottake = solve(ind + 1, ds, price, special, needs);

        int take = 1e9;
        vector<int> copyds = ds;

        for (int i = 0; i < needs.size(); i++)
        {
            if (copyds[i] + special[ind][i] <= needs[i])
                copyds[i] += special[ind][i];
            else
                return m[ind][ds] = min(nottake, take);
        }

        take = special[ind][price.size()] + solve(ind, copyds, price, special, needs);

        return m[ind][ds] = min(nottake, take);
    }
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
    {
        vector<int> ds(needs.size(), 0);
        return solve(0, ds, price, special, needs);
    }
};