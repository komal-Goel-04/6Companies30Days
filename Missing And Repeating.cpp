class Solution
{
public:
    vector<int> findTwoElement(vector<int> &arr)
    {
        int n = arr.size();
        vector<bool> visited(n + 1, false);
        int repeating = -1;
        int missing = -1;

        for (int i = 0; i < n; i++)
        {
            if (visited[arr[i]])
            {
                repeating = arr[i];
            }
            else
            {
                visited[arr[i]] = true;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                missing = i;
                break;
            }
        }

        return {repeating, missing};
    }
};