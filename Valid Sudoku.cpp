class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int j = 0, k = 0;
        map<char, int> m;

        // row wise checking
        for (int i = 0; i < 9; i++)
        {
            for (int k = 0; k < 9; k++)
            {
                if (board[i][k] != '.')
                    m[board[i][k]]++;

                if (m[board[i][k]] > 1)
                    return false;
            }
            m.clear();
        }

        // col wise checking
        for (int i = 0; i < 9; i++)
        {
            for (int k = 0; k < 9; k++)
            {
                if (board[k][i] != '.')
                    m[board[k][i]]++;

                if (m[board[k][i]] > 1)
                    return false;
            }
            m.clear();
        }

        vector<unordered_set<char>> check_subbox(9);
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                int loc = (row / 3) * 3 + col / 3;
                if (board[row][col] != '.' && check_subbox[loc].find(board[row][col]) != check_subbox[loc].end())
                {
                    return false;
                }
                check_subbox[loc].insert(board[row][col]);
            }
        }

        return true;
    }
};