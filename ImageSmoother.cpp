class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int row = img.size(), col = img[0].size();
        vector<vector<int>> ans(row, vector<int>(col, 0));

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int x = img[i][j];
                int tot = 1;

                // up
                if (i - 1 >= 0)
                {
                    cout << "up" << endl;
                    x += img[i - 1][j];
                    tot++;
                }

                // left
                if (j - 1 >= 0)
                {
                    cout << "left" << endl;
                    x += img[i][j - 1];
                    tot++;
                }

                // right
                if (j + 1 < col)
                {
                    cout << "right" << endl;
                    x += img[i][j + 1];
                    tot++;
                }

                // bottom
                if (i + 1 < row)
                {
                    cout << "bottom" << endl;
                    x += img[i + 1][j];
                    tot++;
                }

                // down right
                if (i + 1 < row && j + 1 < col)
                {
                    cout << "down right" << endl;
                    x += img[i + 1][j + 1];
                    tot++;
                }

                // top right
                if (i - 1 >= 0 && j + 1 < col)
                {
                    cout << "top right" << endl;
                    x += img[i - 1][j + 1];
                    tot++;
                }

                // top left
                if (i - 1 >= 0 && j - 1 >= 0)
                {
                    cout << "top left" << endl;
                    x += img[i - 1][j - 1];
                    tot++;
                }

                // down left
                if (i + 1 < row && j - 1 >= 0)
                {
                    cout << "down left" << endl;
                    x += img[i + 1][j - 1];
                    tot++;
                }

                ans[i][j] = floor(x / tot);
            }
        }
        return ans;
    }
};