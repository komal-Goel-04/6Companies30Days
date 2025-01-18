class Solution {
public:
    int countCollisions(string s) {
        int n = s.length(), ans = 0;

        if(n == 1)
            return 0;

        stack<char> st;
        st.push(s[0]);

        for(int i=1;i<n;i++)
        {
            if(!st.empty() && st.top() == 'R' && s[i] == 'L')
            {
                ans += 2;
                st.pop();
                st.push('S');
            }
            else if(!st.empty() && st.top() == 'S' && s[i] == 'L')
            {
                ans++;
            }
            else if(!st.empty() && st.top() == 'R' && s[i] == 'S')
            {
                ans++;
                st.pop();
                st.push('S');
            }
            else
                st.push(s[i]);

        }

        while(!st.empty() && st.top() == 'R')
        {
            st.pop();
        }

        while(!st.empty())
        {
            if(st.top() == 'R')
                ans++;

            st.pop();
        }

        return ans;
    }
};