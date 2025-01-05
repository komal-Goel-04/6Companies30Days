class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> matrix(n, vector<int>(n, 1e9));

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            matrix[u][v] = w;
            matrix[v][u] = w;
        }

        for (int i = 0; i < n; i++)
        {
            matrix[i][i] = 0;
        }

        for (int via = 0; via < n; via++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                }
            }
        }

        int temp = 0, mincity = INT_MAX, ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] <= distanceThreshold)
                {
                    temp++;
                }
            }

            if (temp == mincity)
            {
                ans = max(ans, i);
            }
            if (temp < mincity)
            {
                mincity = temp;
                ans = i;
            }
            temp = 0;
        }

        return ans;
    }
};