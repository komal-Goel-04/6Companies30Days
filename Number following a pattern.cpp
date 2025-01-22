class Solution
{
public:
    string printMinNumberForPattern(string S)
    {
        stack<int> st;
        string ans = "";

        if (S == "D")
            return "21";
        if (S == "I")
            return "12";

        for (int i = 0; i <= S.length(); i++)
        {
            st.push(i + 1);

            if (S[i] == 'I')
            {
                while (!st.empty())
                {
                    ans += to_string(st.top());
                    st.pop();
                }
            }
        }
        while (!st.empty())
        {
            ans += to_string(st.top());
            st.pop();
        }
        return ans;
    }
};
