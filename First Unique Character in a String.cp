class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int> times;
        map<char,int> index;

        int ans = INT_MAX;
        char temp;

        for(int i=0;i<s.length();i++)
        {
            times[s[i]]++;
            index[s[i]] = i;
        }

        for(auto i : times)
        {
            if(i.second == 1)
                ans = min(ans, index[i.first]);
        }
        if(ans != INT_MAX)
            return ans;
        else
            return -1;

    }
};