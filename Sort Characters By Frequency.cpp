class Solution
{
public:
    string frequencySort(string s)
    {
        // priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>> pq;
        priority_queue<pair<int, char>> pq;

        unordered_map<char, int> m;
        for (int i = 0; i < s.length(); i++)
        {
            m[s[i]]++;
        }

        for (auto i = m.begin(); i != m.end(); i++)
        {
            pq.push({i->second, i->first});
        }

        string ans = "";

        while (!pq.empty())
        {
            int i = pq.top().first;
            char c = pq.top().second;

            pq.pop();

            for (int j = 0; j < i; j++)
                ans += c;
        }
        return ans;
    }
};