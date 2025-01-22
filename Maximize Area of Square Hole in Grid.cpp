class Solution
{
public:
    int maximizeSquareHoleArea(int n, int m, vector<int> &hBars, vector<int> &vBars)
    {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int count = 1, maxh = 1, maxv = 1;

        for (int i = 1; i < hBars.size(); i++)
        {
            if (hBars[i] == hBars[i - 1] + 1)
                count++;
            else
                count = 1;
            maxh = max(maxh, count);
        }

        count = 1;
        for (int i = 1; i < vBars.size(); i++)
        {
            if (vBars[i] == vBars[i - 1] + 1)
                count++;
            else
                count = 1;
            maxv = max(maxv, count);
        }

        int s = min(maxh, maxv) + 1;
        return s * s;
    }
};