class Solution
{
public:
    string encode(string s)
    {
        int count = 1;
        char c = s[0];
        string ans = "";

        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == s[i - 1])
                count++;

            else
            {
                ans += c;
                ans += to_string(count);
                count = 1;
                c = s[i];
            }
        }
        ans += c;
        ans += to_string(count);
        return ans;
    }
};