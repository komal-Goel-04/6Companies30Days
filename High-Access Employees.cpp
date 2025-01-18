class Solution
{
public:
    vector<string> ans;
    bool isans(vector<int> a)
    {
        sort(a.begin(), a.end());

        int n = a.size();
        if (n < 3)
            return false;

        int start = 0;

        for (int end = 0; end < n; end++)
        {
            while (a[end] - a[start] >= 60)
            {
                start++;
            }

            if (end - start + 1 >= 3)
            {
                return true;
            }
        }

        return false;
    }

    vector<string> findHighAccessEmployees(vector<vector<string>> &at)
    {
        map<string, vector<int>> m;

        for (int i = 0; i < at.size(); i++)
        {
            string name = at[i][0];
            string time = at[i][1];

            int hour = stoi(time.substr(0, 2));
            int minute = stoi(time.substr(2, 2));
            int totalMinutes = hour * 60 + minute;

            m[name].push_back(totalMinutes);
        }

        for (auto i : m)
        {
            if (isans(i.second))
            {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};