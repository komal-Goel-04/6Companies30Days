class Solution
{
public:
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {
        int n = original.size();

        vector<vector<long long>> cost_grid(26, vector<long long>(26, LONG_MAX));

        for (int i = 0; i < 26; i++)
        {
            cost_grid[i][i] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            if (original[i] != changed[i])
            {
                cost_grid[original[i] - 'a'][changed[i] - 'a'] = min(cost_grid[original[i] - 'a'][changed[i] - 'a'], (long long)cost[i]);
            }
        }

        for (int k = 0; k < 26; k++)
        {
            for (int i = 0; i < 26; i++)
            {
                for (int j = 0; j < 26; j++)
                {
                    if (cost_grid[i][k] != LONG_MAX && cost_grid[k][j] != LONG_MAX)
                    {
                        cost_grid[i][j] = min(cost_grid[i][j], cost_grid[i][k] + cost_grid[k][j]);
                    }
                }
            }
        }

        long long total_cost = 0;

        for (int i = 0; i < source.size(); i++)
        {
            if (source[i] != target[i])
            {
                if (cost_grid[source[i] - 'a'][target[i] - 'a'] == LONG_MAX)
                    return -1;

                total_cost += cost_grid[source[i] - 'a'][target[i] - 'a'];
            }
        }

        return total_cost;
    }
};