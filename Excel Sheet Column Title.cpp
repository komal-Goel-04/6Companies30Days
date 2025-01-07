class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string ans;
        int remainder = 0;

        while (columnNumber > 0)
        {
            columnNumber--;
            remainder = columnNumber % 26;
            ans += ('A' + remainder);
            columnNumber = columnNumber / 26;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};