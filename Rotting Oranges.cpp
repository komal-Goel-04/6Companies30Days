class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();

        // store rotten oranges index
        vector<vector<int>> rooted;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 2)
                    rooted.push_back({i, j});
            }
        }

        int time = 0;

        while (!rooted.empty())
        {
            time++;
            vector<vector<int>> temp = rooted;
            rooted.clear();

            while (!temp.empty())
            {
                int r = temp[0][0];
                int c = temp[0][1];
                temp.erase(temp.begin());

                if (r + 1 < row && grid[r + 1][c] == 1)
                {
                    grid[r + 1][c] = 2;
                    rooted.push_back({r + 1, c});
                }
                if (r - 1 >= 0 && grid[r - 1][c] == 1)
                {
                    grid[r - 1][c] = 2;
                    rooted.push_back({r - 1, c});
                }
                if (c + 1 < col && grid[r][c + 1] == 1)
                {
                    grid[r][c + 1] = 2;
                    rooted.push_back({r, c + 1});
                }
                if (c - 1 >= 0 && grid[r][c - 1] == 1)
                {
                    grid[r][c - 1] = 2;
                    rooted.push_back({r, c - 1});
                }
            }
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 1)
                    return -1;
            }
        }

        if (time == 0)
            return 0;

        else
            return time - 1;
    }
};