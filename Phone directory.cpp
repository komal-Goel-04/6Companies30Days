class Solution
{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        map<string, int> m;

        for (int i = 0; i < n; i++)
            m[contact[i]]++;

        vector<vector<string>> ans;
        for (int i = 0; i < s.length(); i++)
        {
            vector<string> temp;
            for (auto it : m)
            {
                if (it.first.substr(0, i + 1) == s.substr(0, i + 1))
                    temp.push_back(it.first);
            }
            if (temp.size() == 0)
                temp.push_back("0");

            ans.push_back(temp);
        }
        return ans;
    }
};