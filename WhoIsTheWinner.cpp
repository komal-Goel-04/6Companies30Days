class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            q.push(i);
        }
        while (q.size() > 1)
        {
            int temp = k - 1;
            // int x = temp;
            for (int i = 0; i < temp; i++)
            {
                q.push(q.front());
                q.pop();
                // temp--;
            }
            q.pop();
        }
        return q.front();
    }
};