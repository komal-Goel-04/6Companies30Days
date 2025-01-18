class Solution
{
public:
    map<char, string> m;
    vector<string> result;

    void solve(string digits, int ind, string s)
    {
        if (ind == digits.length())
        {
            result.push_back(s);
            return;
        }

        char ch = digits[ind];
        string possible = m[digits[ind]];

        for (int i = 0; i < possible.length(); i++)
        {
            s += possible[i];
            solve(digits, ind + 1, s);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.length() == 0)
            return result;

        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";

        string s;
        solve(digits, 0, s);

        return result;
    }
};