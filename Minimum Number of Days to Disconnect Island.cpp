class Solution
{
public:
    int row;
    int col;
    int ans = 0;

    void dfs(vector<vector<int>> &visited, vector<vector<int>> &grid, int r, int c, int drow[], int dcol[])
    {
        visited[r][c] = 1;
        for (int i = 0; i < 4; i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if (nrow >= 0 && nrow < row && ncol >= 0 && ncol < col && !visited[nrow][ncol] && grid[nrow][ncol] == 1)
            {
                dfs(visited, grid, nrow, ncol, drow, dcol);
            }
        }
    }

    int countIsland(vector<vector<int>> &grid)
    {
        row = grid.size();
        col = grid[0].size();
        bool flag = false;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        vector<vector<int>> visited(row, vector<int>(col, 0));

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (!visited[i][j] && grid[i][j] == 1)
                {
                    if (flag)
                        return 2;
                    visited[i][j] = 1;
                    dfs(visited, grid, i, j, drow, dcol);
                    flag = true;
                }
            }
        }

        int nisland = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 1)
                {
                    return 1;
                }
            }
        }

        return 0;
    }
    int minDays(vector<vector<int>> &grid)
    {
        // more than 1 island so already disconnected
        int island = countIsland(grid);
        // cout<<island<<endl;
        if (island == 2 || island == 0)
            return 0;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 1)
                {
                    grid[i][j] = 0;
                    int x = countIsland(grid);
                    if (x == 2 || x == 0)
                        return 1;
                    grid[i][j] = 1;
                }
            }
        }

        return 2;
    }
};