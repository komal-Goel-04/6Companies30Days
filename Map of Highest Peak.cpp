class Solution
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        int row = isWater.size();
        int col = isWater[0].size();

        vector<vector<int>> height(row, vector<int>(col, 0));
        vector<vector<bool>> visited(row, vector<bool>(col, 0));
        queue<pair<int, int>> q;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (isWater[i][j] == 1)
                {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        int i = 1, r, c;

        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                pair<int, int> front = q.front();
                q.pop();

                r = front.first;
                c = front.second;

                if (r + 1 < row && !visited[r + 1][c])
                {
                    height[r + 1][c] = i;
                    visited[r + 1][c] = true;
                    q.push({r + 1, c});
                }
                if (r - 1 >= 0 && !visited[r - 1][c])
                {
                    height[r - 1][c] = i;
                    visited[r - 1][c] = true;
                    q.push({r - 1, c});
                }
                if (c + 1 < col && !visited[r][c + 1])
                {
                    height[r][c + 1] = i;
                    visited[r][c + 1] = true;
                    q.push({r, c + 1});
                }
                if (c - 1 >= 0 && !visited[r][c - 1])
                {
                    height[r][c - 1] = i;
                    visited[r][c - 1] = true;
                    q.push({r, c - 1});
                }
            }
            i++;
        }
        return height;
    }
};