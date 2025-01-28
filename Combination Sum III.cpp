class Solution
{
public:
    vector<vector<int>> result;

    void backtrack(int start, int remaining, int count, int k, vector<int> &current)
    {
        if (remaining == 0 && count == k)
        {
            result.push_back(current);
            return;
        }

        if (remaining < 0 || count > k)
        {
            return;
        }

        for (int i = start; i <= 9; ++i)
        {
            current.push_back(i);
            backtrack(i + 1, remaining - i, count + 1, k, current);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> current;
        backtrack(1, n, 0, k, current);
        return result;
    }
};
