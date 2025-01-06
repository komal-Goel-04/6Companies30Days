class Solution
{
public:
    void put(char nuts[], int k, char c, int j)
    {
        for (int i = j; i < j + k; i++)
            nuts[i] = c;
    }
    void matchPairs(int tot, char nuts[], char bolts[])
    {
        map<char, int> n, b;

        vector<int> order = {'!', '#', '$', '%', '&', '*', '?', '@', '^'};

        for (int i = 0; i < tot; i++)
        {
            n[nuts[i]]++;
            b[bolts[i]]++;
        }

        int j = 0, k = 0;

        for (int i = 0; i < order.size(); i++)
        {
            if (n.find(order[i]) != n.end())
            {
                k = n[order[i]];
                put(nuts, k, order[i], j);
                j = j + k;
            }
        }

        j = 0;

        for (int i = 0; i < order.size(); i++)
        {
            if (b.find(order[i]) != b.end())
            {
                k = b[order[i]];
                put(bolts, k, order[i], j);
                j = j + k;
            }
        }
    }
};